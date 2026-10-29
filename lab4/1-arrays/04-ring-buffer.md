## Problem Statement

**Ring buffer**

Embedded devices and routers keep their logs in a **ring buffer**: an array of fixed size where new entries overwrite the oldest ones, wrapping around to index `0` after the last index. A `head` index remembers where the oldest entry is.

When the buffer is dumped as it sits in memory, the entries are out of order:

```
index:  0    1    2    3    4
       104  105  101  102  103        head = 2 (entry 101 is the oldest)
```

Write a program that reads the buffer and `head`, rotates the array **in place** so that the oldest entry comes first, and prints it.

Read the buffer with `read_array` (exercise 01), then `head`, which must be in [0, n - 1].

```c
void rotate_left_once(int n, int v[]);        // moves every element one position to the left; v[0] goes to the end
void rotate_left(int n, int v[], int k);      // rotates left k times
```

Print `Oldest first: ` followed by the array, with `print_array`.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input, or `head` outside [0, n - 1] |

**Constraint:** the rotation changes `v` itself. Do not print with a computed index and do not use a second array.

**Examples**

```
$ ./main
5
104 105 101 102 103
2
Oldest first: 101 102 103 104 105

$ ./main
3
7 8 9
0
Oldest first: 7 8 9

$ ./main
5
1 2 3 4 5
7
Error: head must be between 0 and 4
(exit code 1)
```

**Hints**
- `rotate_left_once`: save `v[0]`, shift `v[1]..v[n-1]` one position left, put the saved value at `v[n - 1]`.
- The shift loop goes up to `i < n - 1`, because it reads `v[i + 1]`.
- Draw the array on paper before and after one rotation.
- `rotate_left` only calls `rotate_left_once` `k` times.

## Questions to verify knowledge
- Why must `v[0]` be saved before shifting?
- What goes wrong if the shift loop goes up to `i < n`?
- How many element moves does `rotate_left` do for `n = 100` and `k = 99`? Can you think of a faster way with a second array?
- Without rotating, how would you print the entries oldest first using `%` (`(head + i) % n`)?
- Where else is a ring buffer useful? (Hint: keyboard input, audio, network cards.)
