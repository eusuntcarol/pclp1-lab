# Math and random cheatsheet

## Math functions

Include [`<math.h>`](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html) and link the math library:

```sh
gcc -Wall -Wextra main.c -o main -lm
```

| Function | Result |
|---|---|
| `pow(x, y)` | `x` raised to `y` |
| `sqrt(x)` | square root |
| `floor(x)` | greatest integer-valued real not greater than `x` |
| `ceil(x)` | smallest integer-valued real not less than `x` |
| `fabs(x)` | absolute value of a `double` |

These functions return `double`. A negative argument to `sqrt` produces a domain error and usually NaN. `abs` is the integer function; use `fabs` for doubles.

Binary floating-point numbers are approximate. Compare with a tolerance:

```c
if (fabs(actual - expected) < 0.0001) {
    printf("equal\n");
    // Displays: equal
}
```

## Random numbers

Include `<stdlib.h>`. `rand()` produces a deterministic pseudo-random sequence; call `srand(seed)` once before generating values. A fixed seed makes tests repeatable, while `time(NULL)` is convenient but weak for security. For one decimal digit, `rand() % 10` gives a value from 0 through 9, but modulo can introduce bias when the range is not a multiple of 10.

```c
#include <stdlib.h>
#include <time.h>

srand((unsigned)time(NULL));
int digit = rand() % 10;
printf("Digit: %d\n", digit);
// Displays: Digit: 7 (example; the value is different each run)
```

`rand()` is not suitable for passwords or real PIN security. Use an operating-system cryptographic source for security-sensitive values.

## Measuring time

The `<time.h>` library provides `clock()` and the `CLOCKS_PER_SEC` constant. `clock()` measures processor time used by the program, not necessarily elapsed wall-clock time:

```c
#include <time.h>

clock_t start = clock();
/* code being measured */
clock_t end = clock();
double seconds = (double)(end - start) / CLOCKS_PER_SEC;
printf("Time: %.3f sec\n", seconds);
// Displays: Time: 0.237 sec (example; depends on the machine)
```

Measure only the operation you want to compare. The value can vary between runs and machines. In the PIN brute-force exercise, compare the search compiled with `-O0` and `-O2`.
