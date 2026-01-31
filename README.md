# SymFit
SymFit is a symbolic execution framework for analyzing binaries, supporting multiple backends such as SymCC and SymSan. This document provides instructions for building and running SymFit using Docker.

## Prerequisites
- Docker installed and running on your system
- Sufficient permissions to perform Docker pull and run operations (either root/sudo, or your user added to the `docker` group)
- A GitHub account with access to the SymFit container registry (`ghcr.io`)

## Installation
Clone this repository, enter the `symfit` directory, and run the install script:

```bash
git clone https://github.com/bitsecurerlab/symfit.git
cd symfit
./install.sh
```

This will pull the SymFit Docker image, clone the necessary dependencies, and compile all components. Once installation is complete, you will be dropped into an interactive shell inside the Docker container, ready to run SymFit. When entering the Symfit Docker environment after installation completes, please use the launch.sh script.

## Usage
SymFit is operated through the `fgtest` wrapper program, located at `symsan_build/driver/fgtest` once compilation is complete. The wrapper accepts environment variables to configure execution behavior, followed by the path to the emulator and any QEMU options.

The general invocation looks like this:

```bash
SYMCC_INPUT_FILE=<input> SYMCC_OUTPUT_DIR=<output> symsan_build/driver/fgtest symfit_symsan_build/x86_64-softmmu/symqemu-system-x86_64 [qemu options]
```

### System Mode
When running in system mode, set the input source to stdin and specify an output directory for generated test cases:

```bash
SYMCC_INPUT_FILE=stdin SYMCC_OUTPUT_DIR=/tmp symsan_build/driver/fgtest symfit_symsan_build/x86_64-softmmu/symqemu-system-x86_64 -your -options -here
```

`SYMCC_INPUT_FILE=stdin` tells the solver to expect input from a terminal rather than a file, which is required for system mode. `SYMCC_OUTPUT_DIR` specifies where the solver will write generated test cases.

### Userland Binaries and Hybrid Fuzzing
When analyzing userland binaries within QEMU, an AFL++ coverage map can be passed to the solver using the `SYMCC_AFL_COVERAGE_MAP` option. This allows constraints to be imported from AFL++ for use in hybrid fuzzing environments.

### Marking Variables as Symbolic
In system mode, variables in compiled programs can be marked symbolic by loading them into memory from the address `0x10000000`. This is done by mapping that address and reading or writing through it. The following example marks a variable as symbolic and prints its value at runtime:

```c
#include <stdio.h>
#include <sys/mman.h>

int main(void) {
    void *ptr = mmap((void *)0x10000000, 1024,
                     PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
                     -1, 0);
    if (ptr == MAP_FAILED) {
        fprintf(stderr, "Couldn't mmap!\n");
        return 1;
    }

    unsigned int *iptr = (unsigned int *)ptr;
    *iptr = 1; // Concrete value - can be reassigned normally
    printf("The value of the symbolic variable at the time of execution is %d\n", *iptr);

    munmap((void *)0x10000000, 1024);
    return 0;
}
```

> **Note:** The target address (`0x10000000`) will need to differ on other emulated CPU architectures, as it could conflict with memory-mapped I/O or other components. No other modifications are needed — the solver will automatically track propagation of symbolic values throughout system memory, generating constraints and producing test cases for the uninstrumented binary.

### Intercepting Syscall Arguments
Rather than instrumenting individual arguments, the emulator can be signaled to create labels for all syscall arguments automatically. Compile `syscall_instrument.c` for your preferred guest operating system, then use it to bracket your target program:

```sh
./syscall_instrument enable && ./target_executable && ./syscall_instrument disable
```

It is recommended to halt instrumentation immediately after the target program terminates in order to reduce noise.

## MCP Server for LLM Agents
SymFit includes an MCP (Model Context Protocol) server that enables LLM agents to perform automated concolic execution on binaries. It provides a standardized interface for running symbolic execution campaigns, managing test case corpora, analyzing coverage and results, and automating binary analysis workflows.

See the [SymFit MCP repository](https://github.com/bitsecurerlab/symfit) for more details.

## Contributing
Contributions are welcome! Please feel free to submit issues and pull requests.

## License
See the LICENSE file for details.
