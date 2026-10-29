# Searching and sorting cheatsheet

## Linear search

Compare every element with `x`, from left to right. Stop at the first match. Works on **any** array.

```
linear_search(v, n, x):
    for i = 0 .. n-1:
        if v[i] == x:
            return i
    return -1                       // -1 = not found, never a valid index
```

## Binary search

Works **only on a sorted array**. Look at the middle element: if it is `x`, done. If it is smaller than `x`, `x` can only be in the right half. Otherwise, in the left half. Every step throws away half of what is left.

```
binary_search(v, n, x):
    low = 0
    high = n - 1
    while low <= high:
        mid = low + (high - low) / 2
        if v[mid] == x:
            return mid
        if v[mid] < x:
            low = mid + 1           // x is in the right half
        else:
            high = mid - 1          // x is in the left half
    return -1
```

Searching for `23` in 8 sorted values:

```
index:  0   1   2   3   4   5   6   7
value:  3   8  11  15  23  42  57  91
        L          M               H     15 < 23 -> go right
                        L   M      H     42 > 23 -> go left
                        LMH              23 found at 4 (3 comparisons)
```

Why `low + (high - low) / 2` and not `(low + high) / 2`? The two are equal mathematically, but `low + high` can overflow `int` when both are large. This bug existed in Java's standard library for 9 years.

## Swapping two elements

Arrays are not copied, so a function can swap two elements of the caller's array:

```c
void swap_elements(int v[], int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
```

## Selection sort

Find the minimum of the unsorted part and swap it to the front of that part. Repeat on what is left.

```
selection_sort(v, n):
    for i = 0 .. n-2:
        min_pos = i
        for j = i+1 .. n-1:
            if v[j] < v[min_pos]:
                min_pos = j
        swap(v[i], v[min_pos])      // v[0..i] is now sorted
```

```
start:     10  30  -1   4   5
i = 0:    -1 | 30  10   4   5      min of all is -1, swap with v[0]
i = 1:    -1   4 | 10  30   5      min of the rest is 4
i = 2:    -1   4   5 | 30  10
i = 3:    -1   4   5  10 | 30      done
```

## Bubble sort

Compare neighbours and swap them if they are in the wrong order. After one pass, the largest value has "bubbled" to the end. Repeat until a pass makes no swap.

```
bubble_sort(v, n):
    repeat:
        swapped = false
        for i = 0 .. n-2:
            if v[i] > v[i+1]:
                swap(v[i], v[i+1])
                swapped = true
        n = n - 1                   // the last element is in place
    until not swapped
```

```
pass 1:   10  30  -1   4   5   ->  10  -1   4   5  30
pass 2:   10  -1   4   5 | 30  ->  -1   4   5  10  30
pass 3:   -1   4   5 | 10  30  ->  no swap, done
```

## Merging two sorted arrays

Two sorted arrays can be combined into one sorted array in **one pass**, without sorting again. Keep one index in each array. Each step, copy the smaller of the two current elements and move that index forward.

```
merge(a, na, b, nb, out):
    i = 0, j = 0, k = 0
    while i < na and j < nb:
        if a[i] <= b[j]:
            out[k] = a[i]; i++; k++
        else:
            out[k] = b[j]; j++; k++
    while i < na:                   // copy what is left of a
        out[k] = a[i]; i++; k++
    while j < nb:                   // copy what is left of b
        out[k] = b[j]; j++; k++
    return k                        // = na + nb
```

```
a: 10 20 30 40        b: 5 15 30 31 60
out: 5 10 15 20 30 30 31 40 60
```

## Comparison

| Algorithm | Needs sorted input | Work for 1 000 elements (worst case) |
|---|---|---|
| linear search | no | 1 000 comparisons |
| binary search | yes | 10 comparisons |
| selection sort | no | about 500 000 comparisons |
| bubble sort | no | about 500 000 comparisons, fewer if almost sorted |
| merge | both inputs sorted | 1 000 steps |

Faster sorting algorithms (merge sort, quicksort) come in later courses.
