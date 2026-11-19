# 1. Basics

## 1. Write and observe

Write a program that does the following, step by step. Compile with `-fsanitize=address`.

1. Declare `char c = 'A';`. Print it with `%c` and with `%d`. Print `c + 1` with `%c`. Print `'7' - '0'` with `%d`.
2. Declare `char s[NMAX] = "hello";` with `NMAX` 8. Print `sizeof(s)` and `strlen(s)`.
3. Print every element of `s` (all `NMAX` of them) with `%d`. Where is the `'\0'`? What is in the elements after it?
4. Set `s[2] = '\0';` and print `s` with `%s`, then `strlen(s)`, then `s + 3` with `%s`.
5. Convert `s` back to `"hello"` and then to upper case, character by character, with a loop and `toupper`. Print it.
6. Declare `const char *p = "hello";`. Print `sizeof(p)` and `strlen(p)`. Add the line `p[0] = 'H';` and compile. Read the error, then remove the line.
7. Declare `char t[5] = "hello";` and print it with `%s`. Does it compile? What does the sanitizer say when you run it?

Questions:

- Why is `'7' - '0'` equal to 7, for any digit?
- In step 4, `strlen(s)` changed, but did the characters `'l'`, `'l'`, `'o'` disappear from memory?
- Why is `sizeof(p)` different from `sizeof(s)`?
- Why does step 7 compile, and what exactly is wrong with `t`?

## 2. Progress bar

Installers and downloads show a progress bar. Write a function that builds one in a string:

```c
void make_bar(char *out, int done, int total);
```

The bar is `WIDTH` characters wide (`#define WIDTH 20`), between `[` and `]`. The filled part is `done * WIDTH / total` characters of `#`, the rest is `-`.

Rules:

- Build `out` character by character, with a loop and an index. No `string.h`, no `sprintf`.
- `out` must be a valid string at the end.

In `main`, read `done` and `total`, print the bar followed by the percentage (`done * 100 / total`), then print the bar for every step from 0 to `total`.

```
done total: 3 7
[########------------]  42%

all steps:
[--------------------]   0%
[##------------------]  14%
[#####---------------]  28%
[########------------]  42%
[###########---------]  57%
[##############------]  71%
[#################---]  85%
[####################] 100%
```

Questions:

- How many bytes must the array passed as `out` have, for `WIDTH` 20? Use `#define NMAX` with that value.
- Remove the line that writes `'\0'`. What happens? Does it always happen?

Bonus: animate it. Print the bar with `printf("\r%s", ...)` instead of `"\n"` (`'\r'` moves the cursor back to the start of the line), call `fflush(stdout)` and wait between steps with `usleep(200000)` from `unistd.h` (Linux / WSL).

## 3. Bug hunt

[3-bug-hunt/main.c](3-bug-hunt/main.c) reads a name and prints a greeting, a tag (the first 3 letters of the name) and a role (`Admin` for the name `admin`, `Guest` for everyone else). It has **5 bugs**.

For the input `admin`, the correct output is:

```
name: admin
Hello, admin!
tag: adm, role: Admin
```

Find them with the compiler warnings, the address sanitizer, and by reading the code: not all of them are caught by a tool. For each bug, write a comment next to the fix: what was wrong and how you found it.
