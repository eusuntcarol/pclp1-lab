## Problem Statement

**CTF leaderboard**

At the end of a Capture The Flag contest the scores have to be sorted to find the podium. Write a program that sorts the scores with **selection sort** and prints the top 3.

Read the scores with `read_array` (from section 1).

```c
void swap_elements(int v[], int i, int j);   // swaps v[i] and v[j]
void sort_array(int n, int v[]);             // sorts v ascending, with selection sort
```

Print `Sorted: ` followed by the array (`print_array`), then `Podium:` and the 3 highest scores, highest first. If there are fewer than 3 scores, print only those.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input (same rules as `read_array`) |

**Constraint:** selection sort, as in the cheatsheet. The podium is read from the end of the sorted array, without sorting again.

**Examples**

```
$ ./main
5
10 30 -1 4 5
Sorted: -1 4 5 10 30
Podium:
1. 30
2. 10
3. 5

$ ./main
2
7 3
Sorted: 3 7
Podium:
1. 7
2. 3
```

**Hints**
- Outer loop: `i` from `0` to `n - 2`. Inner loop: find the position of the minimum in `v[i]` to `v[n - 1]`. Then swap it with `v[i]`.
- The inner loop keeps the **index** of the minimum, like `posmax_array` in section 1.
- After sorting, the highest score is `v[n - 1]`, the second is `v[n - 2]`, the third is `v[n - 3]`.
- The loop for the podium needs two conditions: `place <= 3` and `place <= n`.

## Questions to verify knowledge
- Why does the outer loop stop at `n - 2`?
- How many swaps does selection sort make for `n` elements, at most? How many comparisons?
- Write the array after each step of the outer loop for `10 30 -1 4 5`.
- What would you change to sort descending?
- Try bubble sort from the cheatsheet on the same input. Which one makes fewer swaps?
