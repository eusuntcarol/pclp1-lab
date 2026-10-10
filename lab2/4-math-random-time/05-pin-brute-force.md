## Problem Statement

**PIN brute force**

A device is protected by a numeric PIN. Write a program that tries every possible PIN, from `0` upwards, until it finds the right one. It counts the attempts and measures how long the search takes.

Read the number of digits `D` and the secret PIN from standard input. `D` must be in [1, 9]; use `scanf` for both values.

Print the PIN **zero-padded to `D` digits**, the number of attempts and the elapsed time with 3 decimals.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | the input is invalid or `D` is not in [1, 9] |
| 2 | the secret PIN does not fit in `D` digits |

**Examples**

```
$ ./main
4 42
PIN 0042 found after 43 attempts
Time: 0.000 sec

$ ./main
4 9999
PIN 9999 found after 10000 attempts
Time: 0.000 sec

$ ./main
4 12345
Error: PIN does not fit in 4 digits       (exit code 2)

$ ./main
8 99999999
PIN 99999999 found after 100000000 attempts
Time: 0.237 sec   <- depends on your machine
```

**Part 2:** compile and run the 9-digit worst case with `-O0` and with `-O2`. Compare the times.
```
gcc -Wall -Wextra -O0 main.c -o main
gcc -Wall -Wextra -O2 main.c -o main
./main
9 999999999
```

**Hints**
- Compute `10^D` with a loop (the last valid PIN is `10^D - 1`).
- `%0*u` takes the width from an argument: `printf("%0*u", D, pin)`.
- `clock()` is in `<time.h>`. Seconds = `(double)(end - start) / CLOCKS_PER_SEC`.
- Time only the search loop.

## Questions to verify knowledge
- Why does the time grow about 10 times for each extra digit?
- Why `%u` and not `%i` for reading `0042`? (what does `%i` do with a leading `0`?)
- What does `-O2` change? Why is the result still correct?
- How do real systems make this attack impractical? (think about the number of attempts allowed)
