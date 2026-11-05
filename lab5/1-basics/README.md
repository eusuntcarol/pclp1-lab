# 1 — Basics: `&`, `*`, `NULL`

## 1. Write and observe — Easy

Starting from `1-observe/main.c`:

1. Declare `int x = 5;` and `int *p = &x;`.
2. Print `x`, `&x`, `p`, `*p`, `&p` (addresses with `%p` and `(void *)`).
3. Run `*p = 10;`, then print `x` again.

Answer (as a comment in the code):
- Which printed values are equal? Why?
- Why did `x` change, even though you never wrote `x = 10`?
- Run the program twice. Do the addresses change?

## 2. Moving pointer — Easy

Starting from `2-moving-pointer/main.c`:

1. Declare `int a = 1, b = 2;` and `int *p = &a;`.
2. `*p = 100;` and print `a` and `b`.
3. `p = &b;`, then `*p = 200;` and print `a` and `b` again.
4. Print `sizeof(int)`, `sizeof(int *)`, `sizeof(double)`, `sizeof(double *)`.

Answer:
- What changed in step 3: `p` or `*p`? And in step 2?
- Why are `sizeof(int *)` and `sizeof(double *)` equal, even though `int` and `double` have different sizes?

## 3. swap — Easy

Please try to write it yourself first. If you get stuck, look at `3-swap/main.c`.

1. Implement `swap_val(int a, int b)` and `swap_ptr(int *a, int *b)`, both trying to exchange the values.
2. Test them on two variables in `main`. Which one works, and why?
3. Implement `sort3(int *a, int *b, int *c)`, which sorts three values in ascending order using only `swap_ptr`.

```
Enter 3 numbers: 7 2 5
Sorted: 2 5 7
```
