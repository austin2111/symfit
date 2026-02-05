#!/bin/bash
set -euo pipefail

#==============================================================================
# Universal Hybrid Fuzzing Script for Symfit + AFL++
#==============================================================================
# Usage: ./hybrid_fuzz.sh [OPTIONS]
#
# Required:
#   -t, --target PATH       Path to target binary
#   -s, --seeds PATH        Path to seed corpus directory
#
# Optional:
#   -o, --output PATH       Output directory (default: ./fuzz_output)
#   -a, --args "ARGS"       Target arguments (use @@ for input file)
#   -T, --timeout TIME      AFL warmup timeout in seconds (default: 10)
#   -m, --memory LIMIT      Memory limit (default: none)
#   -t, --time LIMIT        Execution timeout in ms (default: 1000+)
#   --max-seeds NUM         Maximum seeds to use from corpus (default: all)
#   --symfit PATH          Path to Symfit binary (auto-detect if not set)
#   --symsan PATH           Path to SymSan fgtest (auto-detect if not set)
#   --afl-dir PATH          Path to AFL++ binaries (default: ./afl++)
#   -h, --help              Show this help
#
# Examples:
#   # Basic usage
#   ./hybrid_fuzz.sh -t /bin/readelf -s ./seeds -a "-a @@"
#
#   # With custom output
#   ./hybrid_fuzz.sh -t ./myprogram -s ./corpus -o ./my_results
#
#   # With memory and timeout limits
#   ./hybrid_fuzz.sh -t ./target -s ./seeds -m 200M -t 5000+
#
#   # Custom configuration
#   ./hybrid_fuzz.sh -t ./app -s ./seeds --max-seeds 1000
#==============================================================================

#==============================================================================
# Default Configuration
#==============================================================================

CONFIG="mode_switch_symsan"
OUTPUT_DIR="./fuzz_output"
TARGET_BINARY=""
SEED_DIR=""
TARGET_ARGS="@@"
AFL_WARMUP_TIME=10
MEMORY_LIMIT="none"
TIME_LIMIT="1000+"
MAX_SEEDS=""
SYMFIT_BIN=""
SYMSAN_FGTEST=""
AFL_DIR="./afl++"

# AFL++ options
export AFL_SKIP_CPUFREQ=1
export AFL_NO_AFFINITY=1
export AFL_NO_UI=1

# Solver options
export RUST_BACKTRACE=1
export RUST_LOG=info

#==============================================================================
# Parse Arguments
#==============================================================================

show_help() {
    sed -n '/^#==/,/^#==/p' "$0" | sed 's/^# \?//'
    exit 0
}

while [[ $# -gt 0 ]]; do
    case $1 in
        -t|--target)
            TARGET_BINARY="$2"
            shift 2
            ;;
        -s|--seeds)
            SEED_DIR="$2"
            shift 2
            ;;
        -c|--config)
            CONFIG="$2"
            shift 2
            ;;
        -o|--output)
            OUTPUT_DIR="$2"
            shift 2
            ;;
        -a|--args)
            TARGET_ARGS="$2"
            shift 2
            ;;
        -T|--timeout)
            AFL_WARMUP_TIME="$2"
            shift 2
            ;;
        -m|--memory)
            MEMORY_LIMIT="$2"
            shift 2
            ;;
        --time)
            TIME_LIMIT="$2"
            shift 2
            ;;
        --max-seeds)
            MAX_SEEDS="$2"
            shift 2
            ;;
        --symfit)
            SYMFIT_BIN="$2"
            shift 2
            ;;
        --symsan)
            SYMSAN_FGTEST="$2"
            shift 2
            ;;
        --afl-dir)
            AFL_DIR="$2"
            shift 2
            ;;
        -h|--help)
            show_help
            ;;
        *)
            echo "Error: Unknown option: $1"
            echo "Use --help for usage information"
            exit 1
            ;;
    esac
done

#==============================================================================
# Validate Required Arguments
#==============================================================================

if [ -z "$TARGET_BINARY" ]; then
    echo "Error: Target binary not specified"
    echo "Use: $0 --target /path/to/binary --seeds /path/to/corpus"
    exit 1
fi

if [ -z "$SEED_DIR" ]; then
    echo "Error: Seed directory not specified"
    echo "Use: $0 --target /path/to/binary --seeds /path/to/corpus"
    exit 1
fi

if [ ! -f "$TARGET_BINARY" ]; then
    echo "Error: Target binary not found: $TARGET_BINARY"
    exit 1
fi

if [ ! -d "$SEED_DIR" ]; then
    echo "Error: Seed directory not found: $SEED_DIR"
    exit 1
fi

# Check if seed directory is empty
if [ -z "$(ls -A "$SEED_DIR")" ]; then
    echo "Error: Seed directory is empty: $SEED_DIR"
    exit 1
fi

# Make target binary path absolute
TARGET_BINARY=$(realpath "$TARGET_BINARY")
SEED_DIR=$(realpath "$SEED_DIR")

#==============================================================================
# Auto-detect Binaries
#==============================================================================

echo "[*] Auto-detecting binaries..."

# Find AFL++ binaries
if [ ! -d "$AFL_DIR" ]; then
    # Try common locations
    for dir in /usr/local/bin /opt/aflplusplus /usr/bin; do
        if [ -f "$dir/afl-fuzz" ]; then
            AFL_DIR="$dir"
            break
        fi
    done
fi

if [ ! -f "$AFL_DIR/afl-fuzz" ]; then
    echo "Error: AFL++ not found. Please specify with --afl-dir"
    exit 1
fi

# Auto-detect Symfit if not specified
if [ -z "$SYMFIT_BIN" ]; then
    # Try common locations
    for path in \
        "/workdir/symfit_symsan_build/x86_64-linux-user/symqemu-x86_64"
    do
        if [ -f "$path" ]; then
            SYMFIT_BIN="$path"
            break
        fi
    done

    if [ -z "$SYMFIT_BIN" ]; then
        echo "Error: Symfit binary not found. Please specify with --symfit"
        exit 1
    fi
fi

# Auto-detect SymSan fgtest if using SymSan config
if [[ "$CONFIG" == *"symsan"* ]] && [ -z "$SYMSAN_FGTEST" ]; then
    for path in \
        "/workdir/symsan_build/driver/fgtest" \
        "./symsan_build/driver/fgtest" \
        "./fgtest" \
        "/usr/local/bin/fgtest"
    do
        if [ -f "$path" ]; then
            SYMSAN_FGTEST="$path"
            break
        fi
    done

    if [ -z "$SYMSAN_FGTEST" ]; then
        echo "Error: SymSan fgtest not found. Please specify with --symsan"
        exit 1
    fi
fi

echo "[X] Symfit: $SYMFIT_BIN"
if [ -n "$SYMSAN_FGTEST" ]; then
    echo "[X] SymSan:  $SYMSAN_FGTEST"
fi
echo "[X] AFL++:   $AFL_DIR"

#==============================================================================
# Display Configuration
#==============================================================================

PROG_NAME=$(basename "$TARGET_BINARY")

echo "========================================="
echo "Hybrid Fuzzing Configuration"
echo "========================================="
echo "Target:       $TARGET_BINARY"
echo "Arguments:    $TARGET_ARGS"
echo "Seeds:        $SEED_DIR"
echo "Output:       $OUTPUT_DIR"
echo "Config:       $CONFIG"
echo "Memory:       $MEMORY_LIMIT"
echo "Timeout:      $TIME_LIMIT"
echo "AFL Warmup:   ${AFL_WARMUP_TIME}s"
echo "========================================="

#==============================================================================
# Setup Directories
#==============================================================================

echo "[*] Setting up directories..."

mkdir -p "$OUTPUT_DIR"
cd "$OUTPUT_DIR"

# Check if already run
if [ -d "${CONFIG}_out" ]; then
    echo "Warning: Output directory ${CONFIG}_out already exists"
    read -p "Overwrite? (y/N) " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        exit 1
    fi
    rm -rf "${CONFIG}_out"
fi

# Copy seeds (limiting if requested)
echo "[*] Preparing seed corpus..."
mkdir -p work_seeds

if [ -n "$MAX_SEEDS" ]; then
    echo "[*] Limiting to $MAX_SEEDS seeds..."
    find "$SEED_DIR" -type f | head -n "$MAX_SEEDS" | xargs -I{} cp {} work_seeds/
else
    cp "$SEED_DIR"/* work_seeds/ 2>/dev/null || true
fi

SEED_COUNT=$(find work_seeds -type f | wc -l)
echo "[*] Using $SEED_COUNT seeds"

if [ "$SEED_COUNT" -eq 0 ]; then
    echo "Error: No seeds found"
    exit 1
fi

#==============================================================================
# Setup AFL++ Binaries
#==============================================================================

echo "[*] Setting up AFL++ binaries..."
ln -sf "$AFL_DIR/afl-fuzz" ./afl-fuzz
ln -sf "$AFL_DIR/afl-showmap" ./afl-showmap
ln -sf "$AFL_DIR/afl-qemu-trace" ./afl-qemu-trace

#==============================================================================
# Install SymCC Fuzzing Helper
#==============================================================================

echo "[*] Checking for symcc_fuzzing_helper..."

if ! command -v /workdir/symcc_fuzzing_helper &> /dev/null; then
    echo "[*] symcc_fuzzing_helper not found, attempting to install..."

    if [ -d "$HOME/.cargo/bin" ]; then
        export PATH="$HOME/.cargo/bin:$PATH"
    fi

    if ! command -v /workdir/symcc_fuzzing_helper &> /dev/null; then
        echo "Error: symcc_fuzzing_helper not found"
        exit 1
    fi
fi

echo "[*] symcc_fuzzing_helper found"

#==============================================================================
# AFL++ Warmup Phase
#==============================================================================

echo "[*] Running AFL++ warmup (${AFL_WARMUP_TIME}s)..."

timeout "${AFL_WARMUP_TIME}s" ./afl-fuzz \
    -S afl-secondary \
    -Q \
    -i work_seeds \
    -o . \
    -m "$MEMORY_LIMIT" \
    -t "$TIME_LIMIT" \
    -- "$TARGET_BINARY" $TARGET_ARGS \
    || true  # Timeout is expected

# Wait for fuzzer stats
echo "[*] Waiting for AFL++ to initialize..."
for i in {1..30}; do
    if [ -f "afl-secondary/fuzzer_stats" ]; then
        break
    fi
    sleep 1
done

if [ ! -f "afl-secondary/fuzzer_stats" ]; then
    echo "Error: AFL++ failed to initialize"
    exit 1
fi

echo "[X] AFL++ initialized"

#==============================================================================
# Concolic Execution Phase
#==============================================================================

echo "[*] Starting concolic execution..."

# Build solver command
if [[ "$CONFIG" == *"symsan"* ]]; then
    echo "[*] Using SymSan solver"
    SOLVER_CMD="SYMCC_OUTPUT_DIR=/tmp/solver $SYMSAN_FGTEST $SYMFIT_BIN $TARGET_BINARY $TARGET_ARGS"
else
    echo "[*] Using built-in solver"
    SOLVER_CMD="$SYMFIT_BIN $TARGET_BINARY $TARGET_ARGS"
fi

echo "[*] Command: $SOLVER_CMD"

# Run symcc_fuzzing_helper
/usr/bin/time -o exec_time.log -f "Total time: %E" \
    /workdir/symcc_fuzzing_helper \
        -o . \
        -a afl-secondary \
        -n "${CONFIG}_out" \
        -s "$SEED_COUNT" \
        -- $SOLVER_CMD \
    &> "log_${CONFIG}.txt" &

HELPER_PID=$!

echo "[*] Fuzzing in progress (PID: $HELPER_PID)"
echo "[*] Monitor with: tail -f $OUTPUT_DIR/log_${CONFIG}.txt"
echo "[*] Press Ctrl+C to stop"

# Wait for completion
wait $HELPER_PID

#==============================================================================
# Results
#==============================================================================

echo "========================================="
echo "Fuzzing Complete!"
echo "========================================="
echo "Target:       $TARGET_BINARY"
echo "Config:       $CONFIG"
echo "Output:       $OUTPUT_DIR/${CONFIG}_out"
echo "Log:          $OUTPUT_DIR/log_${CONFIG}.txt"
echo "========================================="

if [ -f "exec_time.log" ]; then
    cat exec_time.log
fi

# Count results
if [ -d "${CONFIG}_out/queue" ]; then
    QUEUE_COUNT=$(find "${CONFIG}_out/queue" -type f 2>/dev/null | wc -l)
    echo "Test cases:   $QUEUE_COUNT"
fi

if [ -d "${CONFIG}_out/crashes" ]; then
    CRASH_COUNT=$(find "${CONFIG}_out/crashes" -type f 2>/dev/null | wc -l)
    echo "Crashes:      $CRASH_COUNT"

    if [ "$CRASH_COUNT" -gt 0 ]; then
        echo ""
        echo "[!]  Crashes found in: ${CONFIG}_out/crashes/"
    fi
fi

echo "========================================="
