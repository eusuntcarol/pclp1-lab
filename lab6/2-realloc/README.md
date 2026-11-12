# 2 — realloc

Theory: section 2 of `../README.md`. Demo: `../demos/3-realloc.c`.

## 1. Write and observe — Easy

Write a program that does the following, step by step.

1. Allocate 1 int. Grow the block with `realloc` to 2, 3, ..., 10 ints, through a `tmp` pointer. Print the old address before calling `realloc` (after it, the old address may no longer be valid) and the new one after.
2. Grow it once more, to 1000000 ints, and print the addresses again.
3. Before step 1, store `42` in `v[0]`. At the end, print `v[0]`.

Answer:
- Did the address change at every step? At step 2?
- Is `v[0]` still 42 at the end, even if the block moved?
- Why go through `tmp` instead of writing `v = realloc(v, ...)`?

## 2. Read until 0 — Medium

Read numbers until `0`, without knowing how many come. Start with an empty array (`v = NULL`, `cap = 0`) and, when it is full, grow it by `INCR` elements (`#define INCR 4`). Print every growth, then the count, the capacity and the numbers in reverse order.

```
numbers, 0 to stop: 5 8 2 7 1 9 0
  grow: 0 -> 4
  grow: 4 -> 8
count: 6, capacity: 8
reversed: 9 1 7 2 8 5
```

Then change the growth to doubling (`cap * 2`, starting from 1) and run again.

Answer:
- For 1000 numbers, how many `realloc` calls does `INCR 4` need? And doubling?
- With doubling, at most how much of the block can be unused?

## 3. Filter — Medium

`int *filter(const int *v, int n, int (*keep)(int), int *out_n)`

Returns a **new** array with the elements of `v` for which `keep` returns true, and their count through `out_n`. `keep` is a function pointer (lab5, section 4): the same `filter` works with any function `int f(int)`. Write two of them: `is_even` and `is_positive`.

1. Allocate `n` ints (the worst case).
2. Copy the kept elements.
3. Shrink the block to exactly the number kept, with `realloc`. If nothing is kept, free it and return `NULL`.

In `main`, the predicates are in an array of function pointers: pick one with the option, without an `if`/`switch`.

```
n: 6
-3 4 7 -8 10 1
keep (0 even, 1 positive): 0
kept 3: 4 -8 10
```

```
n: 6
-3 4 7 -8 10 1
keep (0 even, 1 positive): 1
kept 4: 4 7 10 1
```

Then add your own predicate (for example `is_multiple_of_3`) to the array, without changing `filter`.

Answer:
- Why allocate `n` first and shrink later, instead of allocating the exact size from the start?
- Can shrinking with `realloc` move the block?
