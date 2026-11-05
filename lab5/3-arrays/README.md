# 3 — Pointers and arrays

## 1. Write and observe — Easy

`1-observe/main.c` already has `int v[5]` and `double w[5]`, initialized.

1. For each `i` from 0 to 4, print on one line: `v[i]`, `*(v + i)`, `&v[i]`, `v + i`.
2. Do the same for `w`.

Answer:
- Which columns are identical?
- By how much do the addresses grow from one line to the next for `v`? And for `w`? Why do they differ?

## 2. Sum without `[]` — Easy

`int sum(int *v, int n)`

Walk the array with a pointer `p` that starts at `v` and stops at `v + n`. You may not use `[]` inside the function.

```
n: 4
1 2 3 4
sum = 10
```

## 3. Reverse with two pointers — Medium

`void reverse(int *v, int n)`

Use two pointers: `left` on the first element and `right` on the last. Swap, then move them towards each other, while `left < right`. No `[]`, no extra array.

```
n: 5
1 2 3 4 5
5 4 3 2 1
```

## 4. find — Medium

`int *find(int *v, int n, int x)`

Returns a pointer to the first occurrence of `x`, or `NULL` if there is none. In `main`, if the result is not `NULL`, print the index computed as `p - v`.

Extra: call `find` repeatedly, starting from the element after the last match, and print every position of `x`.

```
n: 6
4 7 1 7 9 7
x: 7
first occurrence: 1
all: 1 3 5
```
