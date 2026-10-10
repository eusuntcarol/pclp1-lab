## Problem Statement

Write a program that measures how long it takes to iterate from `0` to `999999`.

Use `clock()` from `<time.h>`:

1. Save the start time.
2. Run a loop that visits one million values.
3. Save the end time.
4. Convert the difference to seconds with `CLOCKS_PER_SEC`.
5. Print the elapsed time with three decimal places.

Do not print inside the loop because terminal output would dominate the measurement. Keep the sum in a `long long`, because the sum from `0` to `999999` does not fit in an `int`. Print the sum after measuring so you can check the result:

```text
Sum: 499999500000
```

**Example**

```text
$ ./main
Elapsed time: 0.003 sec
```

The order of the two output lines does not matter, but the sum must be `499999500000`.

The exact value depends on the machine and compiler. Compile and compare:

```sh
gcc -Wall -Wextra -O0 main.c -o main
./main
gcc -Wall -Wextra -O2 main.c -o main
./main
```

`-O0` means that the compiler applies almost no optimization, while `-O2` asks it to make the program faster and smaller where it can. At `-O2`, the compiler may recognize that the sum has a simple mathematical result and replace the loop with a direct calculation, so the measured time can be close to zero.

You do not need to understand how these optimizations work yet. For now, just observe the difference and make sure both programs give the expected result.

## Questions

- What does `clock()` measure?
- Why do we divide by `CLOCKS_PER_SEC`?
- Why should the loop not contain `printf`?
- Why might `-O2` produce a different time than `-O0`?
