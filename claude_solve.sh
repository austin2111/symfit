#!/bin/bash

set -e

OUTPUT_DIR="/workdir/results"
mkdir -p "$OUTPUT_DIR"

echo "=================================================="
echo "  Claude Code-Style Analysis (via API)"
echo "=================================================="
echo ""

# Check API key
if [ -z "$ANTHROPIC_API_KEY" ]; then
    echo "❌ Error: ANTHROPIC_API_KEY not set"
    exit 1
fi

# Step 1: Run symbolic execution
echo "[1/3] Running symbolic execution..."
/workdir/run_cve_automated.sh
if [ $? -ne 0 ]; then
    echo "❌ Symbolic execution failed"
    exit 1
fi
echo "✓ Complete"
echo ""

# Step 2: Prepare Claude Code environment
echo "[2/3] Preparing Claude Code environment..."

# Create a task file that mimics Claude Code's style
cat > "$OUTPUT_DIR/claude_code_task.md" << 'TASK_EOF'
# Task: Analyze Vulnerability Symbolic Execution Output

You are a security researcher analyzing symbolic execution output. You have access to:

## Available Files

1. **execution.log** - Complete symbolic execution trace, including constraints evaluated at each conditional branch until a KASAN error occurs. You may grep for "CONSTRAINTS WITH VALUES" to find them, occasionally interleaved with solver debug logs. The KASAN report will be at the end of execution.log, likely within the last 500 lines. 
4. **source.c** - Vulnerable kernel function
5. **source.asm** - gdb dump of function source

## Your Task

Analyze the symbolic execution output and provide:

### 1. Constraint Analysis
- Provide the conditional jump instruction associated with the constraint that prevents nr_filters from exceeding a certain value
- Explain the SMT encoding pattern
- Categorize constraints by purpose

### 2. Exploitability Assessment
- Determine valid range for nr_filters
- Find minimum value triggering overflow
- Explain why nr_filters = 1 causes OOB write

### 3. Overflow Calculation
For nr_filters = 1, calculate:
- Expected allocation size
- Actual write size (nr_filters × 44 bytes)
- Overflow amount in bytes

### 4. Technical Report
Create a markdown report with:
- Executive summary
- Detailed constraint breakdown
- Exploitability range analysis
- Security recommendations

## Tools Available

You can read files using standard commands such as:
- `cat constraints.txt` - View constraints

Please do not use resources such as curl or internet access to analyze the data.

## Output

Save your analysis as `claude_analysis.md`
TASK_EOF

echo "✓ Task prepared"
echo ""

# Step 3: Run Claude Code-style analysis
echo "[3/3] Running Claude Code analysis..."
echo ""

python3 << 'PYTHON_EOF'
import os
from anthropic import Anthropic

OUTPUT_DIR = "/workdir/results"

# Read the files Claude Code would have access to
def read_file(filename, max_chars=None):
    try:
        with open(f"{OUTPUT_DIR}/{filename}", 'r') as f:
            content = f.read()
            if max_chars:
                content = content[:max_chars]
            return content
    except FileNotFoundError:
        return f"[File {filename} not found]"

# Read task
task = read_file("claude_code_task.md")

# Read project files
source_code = read_file("source.c")
decompiled_code = read_file("source.asm")
execution_preview = read_file("execution.log", 2000)  # First 2000 chars

# Build Claude Code-style prompt
prompt = f"""You are Claude Code analyzing a security research project.

{task}

## Project Files Content

### source.c
```c
{source_code}
```

### source.asm
```
{decompiled_code}
```

### execution.log (preview)
```
{execution_preview}
```

## Instructions

Analyze these files as if you were working in Claude Code with full file access. 

Provide a comprehensive security analysis in markdown format, following the task specifications above.

Focus on:
1. Technical accuracy (these are real SMT constraints from SymSan)
2. Actionable insights (what do the constraints tell us about exploitability?)
3. Clear explanations (suitable for a research presentation)

Output your complete analysis.
"""

# Call Claude API
print("  Calling Claude API in 'Code Mode'...")
print()

client = Anthropic(api_key=os.environ["ANTHROPIC_API_KEY"])

message = client.messages.create(
    model="claude-sonnet-4-20250514",
    max_tokens=4000,
    messages=[
        {"role": "user", "content": prompt}
    ]
)

analysis = message.content[0].text

# Save analysis
with open(f"{OUTPUT_DIR}/claude_analysis.md", "w") as f:
    f.write(analysis)

print("  ✓ Analysis complete!")
print()
print("="*70)
print("  CLAUDE CODE ANALYSIS")
print("="*70)
print()
print(analysis)
print()
print("="*70)
print()

PYTHON_EOF

if [ $? -eq 0 ]; then
    echo ""
    echo "✓ Analysis saved to: $OUTPUT_DIR/claude_analysis.md"
else
    echo ""
    echo "❌ Analysis failed"
    exit 1
fi

echo ""
echo "=================================================="
echo "  Analysis Complete"
echo "=================================================="
echo ""
echo "Results:"
ls -lh "$OUTPUT_DIR/"
echo ""
