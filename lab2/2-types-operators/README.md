# Types and operators cheatsheet

## Types and conversions

`sizeof` reports a size in bytes and has type `size_t`. The sizes below are typical for a 64-bit Linux system; always verify them on your platform:

```c
printf("int: %zu bytes\n", sizeof(int));
// Displays: int: 4 bytes (on a typical platform)
```

Exact sizes are platform-dependent. Common sizes are:

| Type | Size (bytes) | Typical use | `printf` |
|---|---:|---|---|
| `int` | 4 | signed whole numbers | `%d` |
| `unsigned int` | 4 | non-negative whole numbers and bits | `%u` |
| `long long` | 8 | large signed whole numbers | `%lld` |
| `unsigned long long` | 8 | large non-negative whole numbers | `%llu` |
| `float` | 4 | lower-precision real | `%f` |
| `double` | 8 | usual real calculation | `%f` |
| `long double` | 16 | extended-precision real calculation | `%Lf` |

Converting to a narrower integer type discards information. Converting an integer to `double` can lose precision for sufficiently large values. An unsigned value wraps modulo `UINT_MAX + 1`; this is defined, unlike signed overflow.

## Operators

Operators are evaluated according to precedence, from the highest level to the lowest:

| Level | Operators | Associativity |
|---:|---|---|
| 1 | `()` `[]` postfix `++` postfix `--` | left to right |
| 2 | unary `+` unary `-` `!` `~` prefix `++` prefix `--` `sizeof` | right to left |
| 3 | `*` `/` `%` | left to right |
| 4 | `+` `-` | left to right |
| 5 | `<<` `>>` | left to right |
| 6 | `<` `<=` `>` `>=` | left to right |
| 7 | `==` `!=` | left to right |
| 8 | `&` | left to right |
| 9 | `^` | left to right |
| 10 | `\|` | left to right |
| 11 | `&&` | left to right |
| 12 | `\|\|` | left to right |
| 13 | `?:` | right to left |
| 14 | `=` `+=` `-=` `*=` `/=` `%=` `<<=` `>>=` `&=` `^=` `\|=` | right to left |

For example, multiplication happens before addition:

```c
int result = 2 + 3 * 4;
// result is 14
```

Parenthesize mixed expressions when the intended order is not obvious:

```c
if ((n & 1u) == 0u) { /* even */ }
```

Equality binds tighter than bitwise AND, so `n & 1 == 0` is interpreted as `n & (1 == 0)`, not `(n & 1) == 0`. `&`, `|`, and `^` operate bit by bit; `&&` and `||` produce logical true/false values and short-circuit. `%` is remainder, so `17 % 10` is `7`.

Shifts move bits: `n << 1` usually multiplies an unsigned value by two, and `n >> 1` removes its lowest bit. Shift counts must be non-negative and smaller than the width of the promoted left operand. Use unsigned values for masks and bit manipulation. Octal constants begin with `0`, such as `0755`; hexadecimal constants begin with `0x`.

## Integer versus real division

`7 / 2` is `3` because both operands are integers. Make at least one operand real to get `3.5`:

```c
double result = (double)7 / 2;
// result is 3.5; printing it with printf("%f", result) displays: 3.500000
```

Cast before division, not after it. `(double)(7 / 2)` is still `3.0`.
