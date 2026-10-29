## Problem Statement

**Status code histogram**

In lab 3 the log error counter used one variable per class of HTTP codes. With five classes that is five variables and five `if`s. A **frequency vector** does the same with one array: the class of a code is `code / 100` (`404 / 100 = 4`), so it can be used directly as an index.

Read HTTP status codes until the input ends. Count each valid code (100 to 599) in `count[code / 100]`. Codes outside that range are counted as invalid. Then print one histogram line per class, and the most frequent class.

```c
void print_bar(int len);                 // prints len '#' characters, no newline
void print_histogram(int count[]);       // prints the 5 lines, for classes 1 to 5
int posmax_array(int n, int v[]);        // from exercise 02
```

Histogram line format: `printf("%dxx | %3d | ", class, count)`, then the bar, then `\n`.

The most frequent class: if several classes have the same count, the smallest one wins. If there are no valid codes, print `Most frequent: none`.

**Constraint:** one array `int count[6] = {0};` and no other counter per class. Read with `while (scanf("%d", &code) == 1)`.

**Examples**

```
$ ./main
200 404 500 503 99 301 404 403 200 200 201 302 404
<Ctrl+D>
1xx |   0 | 
2xx |   4 | ####
3xx |   2 | ##
4xx |   4 | ####
5xx |   2 | ##
Invalid: 1
Most frequent: 2xx

$ ./main
<Ctrl+D>
1xx |   0 | 
2xx |   0 | 
3xx |   0 | 
4xx |   0 | 
5xx |   0 | 
Invalid: 0
Most frequent: none
```

**Hints**
- `int count[6] = {0};` sets all six elements to `0`. `count[0]` stays unused, so that class `4` is `count[4]`.
- Check the range **before** `count[code / 100]++`. A code like `9999` would write to `count[99]`, outside the array.
- To reuse `posmax_array` on classes 1 to 5 only, you can copy them into a small array of 5, or write the loop from 1 to 5 yourself.
- `print_bar` is the progress bar from lab 3 in its simplest form.

## Questions to verify knowledge
- Why does `count` have 6 elements and not 5?
- What happens if you forget `= {0}`?
- What happens if the range check is missing and the input contains `9999`?
- How would you count every exact code (200, 404, ...) instead of classes? How big must the array be?
- Why does `posmax_array` return the first maximum, and how does that decide the tie between 2xx and 4xx?
