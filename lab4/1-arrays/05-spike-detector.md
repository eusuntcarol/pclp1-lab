## Problem Statement

**Spike detector**

Monitoring systems raise an alert when a value jumps far above its recent level, for example when CPU load or traffic suddenly doubles. Write a program that finds such spikes in a series of samples.

Read the samples with `read_array` (exercise 01), then the window size `w`, which must be in [1, n - 1].

For every position `i` from `w` to `n - 1`, compute the average of the `w` samples **before** it (`v[i - w]` to `v[i - 1]`). Sample `i` is a **spike** if it is more than twice that average.

```c
double window_avg(int v[], int start, int w);   // average of v[start], ..., v[start + w - 1]
```

For each spike print `Spike at #<i>: <value> (previous <w> average: <avg with 2 decimals>)`. At the end print `Spikes: <count>`, or `No spikes` if there was none.

`main` returns `0` if there was no spike and `2` if there was at least one (an alert).

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input, or `w` outside [1, n - 1] |
| 2 | at least one spike was found (not an error, an alert) |

**Examples**

```
$ ./main
10
12 10 11 40 12 13 11 60 12 10
3
Spike at #3: 40 (previous 3 average: 11.00)
Spike at #7: 60 (previous 3 average: 12.00)
Spikes: 2
(exit code 2)

$ ./main
5
10 11 12 11 10
2
No spikes
(exit code 0)

$ ./main
4
1 2 3 4
4
Error: window must be between 1 and 3
(exit code 1)
```

(First example, position 4: the previous 3 samples are `10 11 40`, average `20.33`. `12` is not a spike.)

**Hints**
- Write the indexes on paper for `i = w`: the window is `v[0]` to `v[w - 1]`.
- `window_avg(v, i - w, w)` gives the average of the window before `i`.
- Compare as `double`: `v[i] > 2 * avg`.
- Why `w <= n - 1`? With `w = n` there is no sample left after the first window.

## Questions to verify knowledge
- Which indexes does the window cover for `i = 5`, `w = 3`?
- Why does the loop start at `i = w` and not at `i = 0`?
- The spike at #3 raises the average of the next windows. Which position is affected, and could it hide a second spike?
- How many additions does the program do for `n = 100`, `w = 10`? How could you update the window sum in one step instead of recomputing it?
- Why is returning `2` useful for a script that runs this program every minute?
