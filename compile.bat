@echo off
REM This script compiles and links the C and Assembly files, then runs the executable.

REM 1. Assemble the .asm file
nasm -f win64 dot_product_asm.asm -o dot_product_asm.obj

REM 2. Compile the .c files
gcc -c -m64 main.c -o main.obj
gcc -c -m64 dot_product.c -o dot_product.obj

REM 3. Link all the .obj files into an .exe
gcc -m64 main.obj dot_product.obj dot_product_asm.obj -o dot_product.exe

REM 4. Run the final program
dot_product.exe
