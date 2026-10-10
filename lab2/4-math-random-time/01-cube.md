## Problem Statement

**Cube of a number**

Read a number from the keyboard and print its cube, using a function from the math library (`<math.h>`).

In a second part, read a number and print its `sqrt`, `floor`, and `ceil` values.

**Examples**

```
2     -> 8.000000
-3    -> -27.000000
0.5   -> 0.125000
```

**Hints**
- Look up the function in the [POSIX `math.h` documentation](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html).
- Don't forget to link the math library: `gcc main.c -o main -lm`.

## Questions to verify knowledge
- What is the type of the argument and the return value of the function you used?
- What error do you get if you omit `-lm`? At which stage does it appear: compiling or linking?
- Why does `pow(x, 3)` work with `double`, and what happens if you read `x` as `int` and print with `%d`?
- Is there a function dedicated to cubes? Which one, and why use it?
- What does `sqrt` give for a negative number?
