## Problem Statement

**Time difference**

Read two moments of time, each in the exact format `hh:mm:ss`. Compute the time elapsed **from the first moment to the second** and print it as `hh:mm:ss`, zero-padded to 2 digits per field.

**Sanity checks** (return the code and print an error message):

| Code | Condition |
|---|---|
| 1 | hours not in [0, 24) |
| 2 | minutes not in [0, 60) |
| 3 | seconds not in [0, 60) |
| 4 | second moment is before the first |

**Examples**

```
10:20:30
10:54:37   -> 00:34:07   (exit code 0)

09:59:59
10:00:00   -> 00:00:01

10:00:00
09:00:00   -> error      (exit code 4)

25:00:00
10:00:00   -> error      (exit code 1)
```

**Hints**
- Read each moment with a single `scanf` and a format that contains the `:` separators.
- Convert both moments to seconds, subtract, then convert back with `/` and `%`.
- Zero padding is a `printf` flag.

## Questions to verify knowledge
- Why is converting to seconds easier than subtracting field by field (borrowing)?
- What does `%02d` mean? How is it different from `%2d`?
- What does `scanf("%d:%d:%d", ...)` do with the `:` characters in the format?
- What does `scanf` return for `10-20-30`, and why check it?
