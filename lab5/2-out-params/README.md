# 2 — Pointers as parameters

## 1. divide — Easy

Try to write it yourself first. If you get stuck, look at `1-divide/main.c`.

`int divide(int a, int b, int *quot, int *rem)`

- Writes the quotient and the remainder to the given addresses.
- Returns `1` if the division succeeded and `0` if `b == 0` (in which case it writes nothing).

```
a b: 17 5
17 = 5 * 3 + 2

a b: 4 0
Division by 0
```

## 2. min_max — Easy

Try to write it yourself first. If you get stuck, look at `2-min-max/main.c`.

`void min_max(int *v, int n, int *min, int *max)`

Read `n` and then `n` numbers (at most `NMAX`), print the minimum and the maximum.

```
n: 5
3 -1 8 0 4
min = -1, max = 8
```

## 3. Bug: address of a local variable — Medium

`3-bug-local/main.c` compiles and sometimes even seems to work. The `digits` function returns the digits of a number, but it is wrong.

1. Compile with `gcc -Wall -Wextra main.c -o main`. Which warning appears, and what does it say?
2. Run it for `12345`. Is the result correct?
3. Explain the problem in a comment.
4. Rewrite the function as `void digits(int n, int d[5])`: the array is declared in `main` and passed to the function.
