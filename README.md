# C vs. x86-64 Assembly Dot Product Performance Analysis

A project for the LBYARCH course to implement and compare the performance of a single-precision floating-point dot product kernel. The kernel was implemented in both standard C and x86-64 assembly language.

-----

## Project Requirements

The goal was to create two versions of a dot product kernel and time their execution on large vectors.

  * **C Kernel:** A baseline implementation for correctness and performance comparison.
  * **x86-64 Assembly Kernel:** A performance-oriented implementation using scalar SIMD registers (`XMM`) and floating-point instructions (`movss`, `mulss`, `addss`).
  * **Timing:** The program times both kernels across vector sizes of 1 >> 20, 1 >> 24, and 1 >> 26, averaging the results over 20 runs.

-----

## Tools Required

To compile and run this project, you will need:

  * **NASM Assembler:** For assembling the `.asm` file.
  * **GCC (MinGW-w64):** For compiling and linking the `.c` files and object files on Windows.
  * Both `nasm` and `gcc` must be available in your system's PATH environment variable.

-----

## Results and Analysis

````
------------------------------------------
Testing with vector size n = 1048576
------------------------------------------
C Kernel Result:       262329.000000
ASM Kernel Result:     262329.000000

Average Execution Times (20 runs):
C Kernel:        0.003148 seconds
x86-64 Kernel:   0.001821 seconds

------------------------------------------
Testing with vector size n = 16777216
------------------------------------------
C Kernel Result:       4100319.500000
ASM Kernel Result:     4100319.500000

Average Execution Times (20 runs):
C Kernel:        0.047361 seconds
x86-64 Kernel:   0.023173 seconds

------------------------------------------
Testing with vector size n = 67108864
------------------------------------------
C Kernel Result:       13106567.000000
ASM Kernel Result:     13106567.000000

Average Execution Times (20 runs):
C Kernel:        0.190770 seconds
x86-64 Kernel:   0.087249 seconds
````

The results show that both the C and assembly kernels produced identical, correct results. In terms of performance, the hand-written x86-64 assembly kernel was consistently about 2x faster than the C version across all tested vector sizes.

-----

## How to Compile and Run

The easiest way to run the project is by using the provided batch script.

Make sure you are in the project's root directory. Run the script from the command line:

```bash
compile.bat
```
-----

## Authors  

  * Kelvin Alviar 
  * Henzley Young 
