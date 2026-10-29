## Problem Statement

**User lookup**

A login server keeps the IDs of its users **sorted**. Every login has to check whether an ID exists. Write a program that searches each ID with both linear search and binary search, and shows how many comparisons each one needed.

Read the IDs with `read_array` (from section 1). They must be sorted ascending. Then read IDs to look up until the input ends.

```c
int is_sorted(int n, int v[]);              // 1 if v[0] <= v[1] <= ... <= v[n-1], otherwise 0
int find_array(int n, int v[], int x);      // linear search (exercise 01)
int binary_search(int n, int v[], int x);   // binary search; index of x, or -1
```

Count the comparisons in a global variable `int comparisons;`: set it to `0` before a search, and add `1` every time a search looks at an element (`v[i]` in linear search, `v[mid]` in binary search).

For each ID print `<id>: found at #<index> (linear: <count>, binary: <count>)` or `<id>: not found (linear: <count>, binary: <count>)`.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input, or the IDs are not sorted |

**Constraint:** `binary_search` uses a `while` loop with `low`, `high` and `mid = low + (high - low) / 2`, as in the cheatsheet.

**Examples**

```
$ ./main
16
1003 1010 1017 1024 1031 1038 1045 1052 1059 1066 1073 1080 1087 1094 1101 1108
1003 1059 1108 1050
<Ctrl+D>
1003: found at #0 (linear: 1, binary: 4)
1059: found at #8 (linear: 9, binary: 4)
1108: found at #15 (linear: 16, binary: 5)
1050: not found (linear: 16, binary: 4)

$ ./main
3
5 2 9
Error: IDs are not sorted
(exit code 1)
```

**Hints**
- Follow the cheatsheet pseudocode line by line. Write `low`, `high`, `mid` on paper for `1059`.
- The loop condition is `low <= high`, not `low < high`. With `<`, a one-element range is never checked.
- After comparing with `v[mid]`, move to `mid + 1` or `mid - 1`, never to `mid`, otherwise the loop can run forever.
- A global variable is visible in every function of the file (lab 3, storage classes).

## Questions to verify knowledge
- Why must the array be sorted for binary search? Show a case where it fails on `5 2 9`.
- For `1003`, linear search wins. Why? Is that the usual case?
- How many comparisons does binary search need at most for 1 000 IDs? For 1 000 000?
- Why `mid = low + (high - low) / 2` instead of `(low + high) / 2`?
- What happens if you write `low = mid` instead of `low = mid + 1`?
