## Problem Statement

**Merge server logs**

Two servers, `A` and `B`, each write a log of event timestamps (seconds since midnight). Each log is already sorted by time. To see what happened across the system, the two logs must be combined into one timeline, still sorted.

Sorting the combined list again would work, but it is slow. Because both logs are already sorted, they can be **merged** in a single pass (see the cheatsheet).

Read log `A` and then log `B`, each with `read_array` (from section 1). Both must be sorted ascending.

```c
int is_sorted(int n, int v[]);                                        // exercise 03
int merge(int na, int a[], int nb, int b[], int out[], char src[]);   // merges a and b into out, returns na + nb
```

`src[k]` records where `out[k]` came from: `'A'` or `'B'`. When two timestamps are equal, the one from `A` goes first.

Print the timeline, one event per line: `<timestamp> <source>`.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input, or one of the logs is not sorted |

**Constraint:** one pass, as in the cheatsheet. No sorting function, no searching. `out` and `src` have `2 * NMAX` elements.

**Examples**

```
$ ./main
4
10 20 30 40
5
5 15 30 31 60
5 B
10 A
15 B
20 A
30 A
30 B
31 B
40 A
60 B

$ ./main
3
1 3 2
1
5
Error: logs must be sorted by time
(exit code 1)
```

**Hints**
- Three indexes: `i` in `a`, `j` in `b`, `k` in `out`. Every step copies one element and moves `k` and one of `i` / `j`.
- The first loop runs while **both** logs have elements left. After it, only one of the two "copy what is left" loops does anything.
- `<=` (not `<`) in `a[i] <= b[j]` is what puts `A` first on equal timestamps.
- Write `i`, `j`, `k` on paper for the first example.

## Questions to verify knowledge
- Why do `out` and `src` need `2 * NMAX` elements?
- Why are the two loops after the main one needed? Give an example where each of them runs.
- How many steps does `merge` make for logs of 1 000 events each? How does that compare to selection sort on 2 000 events?
- What changes on equal timestamps if you write `<` instead of `<=`?
- Merge sort sorts an array by splitting it in halves, sorting each half, then merging them. Which part did you just write?
