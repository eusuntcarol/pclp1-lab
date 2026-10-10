## Problem Statement

**Unix permissions decoder**

On Unix, file permissions are stored as a number, usually written in octal. The nine displayed positions are split into three groups:

| Group | Bits | Meaning |
|---|---|---|
| owner | `rwx` | permissions of the file owner |
| group | `rwx` | permissions of the file's group |
| others | `rwx` | permissions of everyone else |

Inside each group, `r = 4`, `w = 2`, and `x = 1`. Therefore:

- `7 = 4 + 2 + 1 = rwx`
- `5 = 4 + 1 = r-x`
- `4 = r--`
- `0 = ---`

Read a Unix permission mode in octal and print its nine-character display (`rwxr-xr--`). Use shifts and `&` to extract bits and `?:` to choose each displayed literal. Print `r`, `w`, `x`, and `-` directly in `printf` calls; do not store characters.

**Errors:** return `1` if octal input is invalid, and `2` if the mode is greater than `0777`.

**Errors**

| Code | Condition |
|---|---|
| 1 | `scanf` did not read a valid octal number |
| 2 | the mode is greater than `0777` |

**Examples**

```
754  -> rwxr-xr--
644  -> rw-r--r--
755  -> rwxr-xr-x
777  -> rwxrwxrwx
000  -> ---------
7    -> ------rwx
888  -> error (exit code 1)
1777 -> error (exit code 2)
```

**Extension:** accept modes up to `07777`. The first octal digit holds special bits: setuid, setgid, and sticky. Display `s`/`S` or `t`/`T` in the execute position.

**Hints**

- `scanf("%o", &mode)` reads an octal number.
- The owner's read bit is `(mode >> 8) & 1`; the group's execute bit is `(mode >> 3) & 1`.
- Octal constants start with `0`, so `0777` is not decimal 777.

## Questions to verify knowledge
- What does `(mode >> 6) & 7` extract?
- Why does `scanf("%o", &mode)` interpret `755` correctly?
- Why is `rwx` exactly three bits?
