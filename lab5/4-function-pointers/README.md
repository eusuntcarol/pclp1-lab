# 4 — Function pointers

## 1. Write and observe — Easy

In `1-observe/main.c`, the functions `add` and `sub` are already written.

1. Declare `int (*op)(int, int) = add;` and print `op(7, 3)`.
2. Do `op = sub;` and print `op(7, 3)` again.
3. Print the addresses of `add`, `sub` and the value of `op`, with `%p` and a `(void *)` cast.
4. Write `if (add) printf("true\n");`. Compile with `-Wall -Wextra`.

Answer:
- After step 2, which address is `op` equal to?
- Why is the condition in step 4 always true? What does the warning say?

## 2. Calculator — Easy

The functions `add`, `sub`, `mul`, `divi` are written. Put them in an array of function pointers and call the chosen operation **without an `if`/`switch` on the option**.

Validate the option (0–3) and division by 0.

```
a b option (0 + | 1 - | 2 * | 3 /): 12 4 2
result: 48
```

## 3. Sort with a comparator — Medium

`void sort(int *v, int n, int (*cmp)(int, int))`

Selection sort (from lab4), but `cmp` decides "which comes first":
- `cmp(a, b) < 0` → `a` goes before `b`
- `cmp(a, b) > 0` → `a` goes after `b`

Write `cmp_asc` and `cmp_desc`. The same `sort` function must sort both ways.

```
n: 5
3 1 4 1 5
mode (1 asc, 2 desc): 2
5 4 3 1 1
```

## 4. qsort — Medium

Same task, using `qsort` from `stdlib.h`.

- The comparator has the signature `int cmp(const void *a, const void *b)`. Convert `a` and `b` to `const int *` before dereferencing.
- Question: why does `qsort` also take `sizeof(v[0])`, while `sort` from exercise 3 does not?
- Question: why can `return x - y;` give a wrong result? Try `x = 2000000000`, `y = -2000000000`. Use `(x > y) - (x < y)` instead.
