# I/O cheatsheet

## Formatted output

`printf` receives a format string followed by values:

```c
int count = 7;
double average = 3.5;
printf("count=%d average=%.2f\n", count, average);
// Displays: count=7 average=3.50
```

| Conversion | Value type | Meaning |
|---|---|---|
| `%d` / `%i` | `int` | signed decimal |
| `%u` | `unsigned int` | unsigned decimal |
| `%o` | `unsigned int` | octal |
| `%x` / `%X` | `unsigned int` | hexadecimal |
| `%ld` / `%lu` | `long` / `unsigned long` | long integer |
| `%lld` / `%llu` | `long long` / `unsigned long long` | long long integer |
| `%f` | `float` | fixed-point real 
| `%lf` | `double` | bigger fixed-point real |
| `%Lf` | `long double` | extended-precision real |
| `%e` / `%g` | `double` | exponential / compact real |
| `%c` | `int` | one character |
| `%s` | pointer to text | string |
| `%%` | none | literal percent sign |

The length is at least the requested width, so `%10.3f` means ten columns and three digits after the decimal point. `%-8d` aligns left, `%08u` pads with zeroes, and `%0*u` takes the width from another argument.

### Escape sequences

Escape sequences represent special characters inside a string:

| Sequence | Meaning |
|---|---|
| `\n` | new line |
| `\t` | horizontal tab |
| `\\` | backslash |
| `\"` | double quote |

## Formatted input

`scanf` stores values through addresses and returns the number of assignments made. Store that return value before validating it:

```c
int number;
int result = scanf("%d", &number);

if (result != 1) {
    printf("Error: expected an integer\n");
    // Displays: Error: expected an integer
    return 1;
}
printf("You entered %d\n", number);
// Displays: You entered 42 (if the input was 42)
```

For two values separated by whitespace:

```c
int first, second;
int result = scanf("%d %d", &first, &second);

if (result != 2) {
    printf("Error: expected two integers\n");
    // Displays: Error: expected two integers
    return 1;
}
printf("Sum: %d\n", first + second);
// Displays: Sum: 42 (if the input was 12 30)
```

Literal separators in the format must match the input:

```c
int hour, minute, second;
int result = scanf("%d:%d:%d", &hour, &minute, &second);

if (result != 3) {
    printf("Error: expected hh:mm:ss\n");
    // Displays: Error: expected hh:mm:ss
    return 1;
}
```

| Conversion | Destination |
|---|---|
| `%d`, `%u`, `%o`, `%x` | `int *`, `unsigned int *` |
| `%ld`, `%lu` | `long *`, `unsigned long *` |
| `%lld`, `%llu` | `long long *`, `unsigned long long *` |
| `%f` | `float *` |
| `%lf` | `double *` |
| `%Lf` | `long double *` |

The format can contain literal separators (`%d/%d/%d`), `*` to read and discard (`%*c`), and a maximum field width (`%2x`). Unlike `printf`, `%f` and `%lf` are different in `scanf`.

For a `long double`, use `%Lf` with both functions:

```c
long double precise = 1.0L / 3.0L;
printf("%.4Lf\n", precise);
// Displays: 0.3333
```

Always check the return value before using an input variable. Handle the three possible outcomes explicitly:

`EOF` means **end of file**. It is returned when the input ends before `scanf` can perform any conversion. For example, an empty redirected input or pressing `Ctrl+D` on Linux/macOS produces `EOF`. If input is available but does not match the format, `scanf` returns `0` instead.

```c
int number;
int result = scanf("%d", &number);

if (result == 1) {
    printf("Read: %d\n", number);
    // Displays: Read: 42 (if the input was 42)
} else if (result == 0) {
    printf("Error: input is not an integer\n");
    // Displays: Error: input is not an integer
} else if (result == EOF) {
    printf("Error: input ended before an integer was read\n");
    // Displays: Error: input ended before an integer was read
}
```

For multiple values, compare the result with the number of values you expect. Print errors with `printf` in this lab and return a documented non-zero code.
