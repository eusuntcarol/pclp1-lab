## Problem Statement

**Sensor report**

Extend the previous exercise: after reading the batch of temperatures, print a short report.

Reuse `read_array` from exercise 01 and add one function per statistic:

```c
int sum_array(int n, int v[]);       // sum of the n values
int min_array(int n, int v[]);       // smallest value
int posmax_array(int n, int v[]);    // index of the largest value (the first one, if it appears several times)
double avg_array(int n, int v[]);    // average of the n values
```

Print:

```
Sum: <sum>
Min: <min>
Max: <max> (reading #<index>)
Average: <average with 2 decimals>
```

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | same as exercise 01 |

**Constraint:** `avg_array` must call `sum_array`. No loop inside `avg_array`.

**Examples**

```
$ ./main
5
10 30 -1 4 5
Sum: 48
Min: -1
Max: 30 (reading #1)
Average: 9.60

$ ./main
4
7 9 9 2
Sum: 27
Min: 2
Max: 9 (reading #1)
Average: 6.75

$ ./main
1
-3
Sum: -3
Min: -3
Max: -3 (reading #0)
Average: -3.00
```

**Hints**
- Start `min` from `v[0]`, not from `0`. With all values negative, `0` would be a wrong answer.
- `posmax_array` keeps the **index** of the best value so far. Compare `v[i] > v[pos]` with `>` (not `>=`), so the first maximum stays.
- `main` gets the maximum value from the index: `v[posmax_array(n, v)]`.
- `sum / n` with two `int`s drops the decimals (lab 2). Convert one side: `(double)sum / n`.

## Questions to verify knowledge
- Why is it a bad idea to start the minimum from `0`? Give an input where it fails.
- Why does `posmax_array` return the index and not the value? What can `main` do with the index?
- What changes in the output for `7 9 9 2` if you compare with `>=`?
- Why does `avg_array` reuse `sum_array` instead of having its own loop?
- What would `avg_array` do with `n = 0`? Why can it not happen here?
