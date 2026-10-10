## Problem Statement

**Reading and printing numbers**

Write a program that practices reading from the keyboard and formatted output.

1. **Integers.** Read two natural numbers from the keyboard, add them, and print the result.
2. **Reals.** Read two real numbers from the keyboard, divide the first by the second, and print the result with exactly 3 decimals, on a total width of 10 printable characters (padded with spaces on the left).

**Examples**

```
Part 1:  12 30        ->  42
Part 2:  7 2          ->  [     3.500]
         10 3         ->  [     3.333]
         -1 8         ->  [    -0.125]
```
(The brackets only show the padding, don't print them.)

## Questions to verify knowledge
- What does the `10` in `%10.3f` count? Does the `.` count? Does the minus sign?
- What happens if the result needs more than 10 characters (e.g. `1000000 / 3`)?
- What happens if the second number is `0`?
- Why does `scanf("%f", &x)` work for `float` but not for `double`?
