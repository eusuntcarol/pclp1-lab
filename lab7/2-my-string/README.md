# 2. Write your own `string.h`

The functions in `string.h` are short loops over a `char` array. Writing them yourself is the best way to see why they need `'\0'`, why they never check sizes, and why `strtok` behaves so strangely.

Rules for this section:

- Inside your `my_` functions, do not use `string.h`. You may call your own `my_` functions.
- Write `my_strlen` and `my_strcpy` with pointers only (no `[]`).
- In `main`, call each function next to the real one and print both results, to check yours.

## 1. Length and copy

```c
size_t my_strlen(const char *s);
char *my_strcpy(char *dst, const char *src);   /* returns dst */
char *my_strcat(char *dst, const char *src);   /* returns dst */
```

Test them at least on `"hello"`, `""` (the empty string) and a string with spaces.

```
my_strlen("hello") = 5    strlen = 5
my_strlen("") = 0         strlen = 0
my_strcpy -> [pclp]
my_strcat -> [pclp lab 7]
```

Questions:

- Why is `src` a `const char *`, but `dst` is not?
- Why do `strcpy` and `strcat` return `dst`? Hint: try `my_strcat(my_strcpy(buf, "lab "), "7")`.
- What happens if `dst` is too small? Who is supposed to check that?
- Bonus: write `my_strcat` in one line, using `my_strcpy` and `my_strlen`.

## 2. Compare and search

```c
int my_strcmp(const char *a, const char *b);
char *my_strchr(const char *s, int c);
char *my_strstr(const char *s, const char *t);
```

- `my_strcmp` returns the difference between the first two characters that differ (`0` if the strings are equal).
- `my_strchr` returns a pointer to the first `c` in `s`, or `NULL`.
- `my_strstr` returns a pointer to the first place where `t` starts inside `s`, or `NULL`. If `t` is empty, it returns `s`.

`s` is `const char *`, but the return type is `char *`, like in the real functions. You need a cast: `return (char *)s;`.

In `main`, print positions (`p - s`), not pointers. Test at least these:

```
my_strcmp("apple", "apricot") = -2    strcmp = -1
my_strcmp("pear", "peach") = 15       strcmp = 1
my_strcmp("lab", "lab") = 0           strcmp = 0
my_strchr("banana", 'n') at 2
my_strchr("banana", 'x') is NULL
my_strstr("banana", "nan") at 2
my_strstr("aaab", "aab") at 1
my_strstr("banana", "") at 0
```

Your `my_strcmp` and `strcmp` may give different numbers. That is fine, only the sign is guaranteed.

Questions:

- `my_strstr("aaab", "aab")` is a trap for a simple implementation. Why? Does yours pass it?
- What does `my_strchr(s, '\0')` return? Is that useful?

## 3. `strtok`

```c
char *my_strtok(char *s, const char *delim);
```

It behaves like the real `strtok` (see the theory README):

1. If `s` is not `NULL`, start from `s`. If it is `NULL`, continue from where the previous call stopped. Keep that position in a `static char *` variable inside the function.
2. Skip delimiters. If you reached `'\0'`, there are no more tokens: return `NULL`.
3. The token starts here. Walk until the next delimiter or `'\0'`.
4. If you stopped at a delimiter, overwrite it with `'\0'` and remember the position after it. Otherwise, remember the `'\0'`.
5. Return the start of the token.

To check if a character is a delimiter, use your `my_strchr` on `delim` (careful with `'\0'`: see the last question of exercise 2).

In `main`, read a line with `fgets`, split it by spaces and print every token. Then split `"red,green,,blue"` by `","`.

```
command: ls   -la    /home/ana
[ls]
[-la]
[/home/ana]
line is now: [ls]
[red]
[green]
[blue]
```

Questions:

- Why must the position be `static`? What would happen with a normal local variable? (Lab 3, storage classes.)
- Why does `line` print as `[ls]` after the loop?
- Why can't you call it on a string literal?
- Split `"1,2;3,4;5,6"` by `";"`, and inside that loop split each group by `","`. You expect three groups. How many do you get, and why?

Bonus: fix the last problem the way POSIX does it. Write `char *my_strtok_r(char *s, const char *delim, char **save);`, where the position is kept in `*save`, a variable owned by the caller, instead of a `static`.
