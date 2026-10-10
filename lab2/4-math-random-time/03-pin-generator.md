## Problem Statement

**PIN generator**

Write a program that generates a random numeric PIN.

Read the number of digits `D` and a seed with `scanf`. A seed of `0` means seed the generator with the current time.

Generate `D` random digits and print the PIN **zero-padded to `D` digits**, followed by a newline. Leading zeros are valid (`0042` is a PIN).

**Errors** (print a message on screen):

| Code | Condition |
|---|---|
| 1 | `scanf` did not read both values |
| 2 | `D` not in [1, 9] |

**Constraints:** no arrays, no strings, no characters. Build the PIN as a single number and print it once.

**Examples** (random output, yours will differ)

```
$ echo "4 0" | ./main
7305

$ echo "6 0" | ./main
048213

$ echo "4 42" | ./main
6011
$ echo "4 42" | ./main
6011                 <- same seed, same PIN

$ echo "0 42" | ./main
Error: digits must be between 1 and 9     (exit code 2)
```

**Extension:** reject weak PINs made of a single repeated digit (`0000`, `7777`). Generate again until the PIN is acceptable. (Use `do...while`.) For `D = 1` skip this check.

**Hints**
- `rand()` and `srand()` are in `<stdlib.h>`, `time()` is in `<time.h>`.
- `rand() % 10` gives one random digit.
- Build the number digit by digit: `pin = pin * 10 + digit`.
- `printf("%0*u", D, pin)` prints `pin` padded with zeros to `D` digits.
- The same seed gives the same sequence **on the same machine and libc**. Don't expect the exact output above on your system.

## Questions to verify knowledge
- Why are the numbers from `rand()` called pseudo-random?
- What happens if you never call `srand`? What if you call it with a constant?
- Why is `time(NULL)` a weak seed for real PINs? What should be used instead?
- Why does printing `pin` with plain `%d` lose the leading zeros?
- Why is `D = 10` not allowed? (what is the largest `unsigned int`?)
