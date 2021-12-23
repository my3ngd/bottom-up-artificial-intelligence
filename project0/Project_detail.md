# Project 0: Decimal Type and Matrix

## Install GMP Library

1. GMP, GNU Multiple Precision library, is a library for arbitrary precision arithmetic. Download the library using this command: `wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz`
2. Download lzip using this command: `sudo apt-get install lzip`
3. Unzip the file: `lzip -d gmp-6.2.1.tar.lz`
4. Unzip the file: `tar -xf gmp-6.2.1.tar`
5. Change directory to the extracted file: `cd gmp-6.2.1`
6. Run this command: `./configure`
7. Run this command: `sudo apt-get install libgmp-dev` to use the library.

<!-- sudo apt-get install autoconf automake libtool ? -->

---

## Compile Your Code

1. Go to the directory by this command: `cd project0/ai_project`
2. Run this command: `cmake -S . -B build` to make `build` directory
3. Run this command: `cmake --build build` to make executable files and shared library
4. Run this command: `build/bin/artificial_intelligence` to run the executable file
5. Run this command: `build/bin/ai_test` to run the test file

If you want to compile your code again, start from step 3.

---

## Insructions

You need to implement the following type, functions, constants.

+ `real_t` must support below operations:
    + unary operators `-`, `++`, `--`
    + binary operators `+`, `-`, `*`, `/`
    + comparison operatiors `==`, `!=`, `<`, `<=`, `>`, `>=`
    + assignment operators `=`, `+=`, `-=`, `*=`, `/=`
    + iostream operators `>>`, `<<`

+ `real_t` must support the following functions:
    - `abs()`, `floor()`, `ceil()`, `round()`, `trunc()`, `frac()`
    - `sqrt()`, `pow()`, `exp()`, `log()`, `log10()`
    - `sin()`, `cos()`, `tan()`, `asin()`, `acos()`, `atan()` (in radian)

> If the decimal precision is expected to be `MAX_PRECISION` or higher, the lower part will be discarded. Also, you should pay as much attention to the performance as possible when implementing them.

+ Also, you must define the following constants using `real_t`:
    + `e = 2.71828182845904523536028747135266249775724709369995...`
    + `pi = 3.1415926535897932384626433832795028841971693993751...`

---

### Thank you.
