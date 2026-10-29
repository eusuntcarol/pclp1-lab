# Arrays cheatsheet

An **array** (vector) is a list of values of the **same type**, stored one after another in memory. Each value is reached by its **index**, from `0` to `n - 1`.

```c
int v[5];        // 5 ints: v[0], v[1], v[2], v[3], v[4]
v[0] = 10;       // first element
v[4] = 5;        // last element
v[5] = 1;        // WRONG: out of bounds, compiles but breaks memory
```

## Declaration and initialization

The size must be a constant known at compile time. Use a `#define` for it, so it can be changed in one place:

```c
#define NMAX 100

int v[NMAX];                        // 100 ints, values are "garbage" until set
int a[5] = {1, 2, 3, 4, 5};         // all 5 set
int b[] = {7, 8, 9};                // size 3, counted by the compiler
int c[NMAX] = {1, 2};               // c[0] = 1, c[1] = 2, all the rest = 0
int count[NMAX] = {0};              // all 0
```

A local array without `= {...}` holds garbage. Set every element before reading it.

## Capacity vs size

`NMAX` is the **capacity** (how many fit). `n` is the **size** (how many are used). Always check `n` before using the array:

```c
int v[NMAX], n;
if (scanf("%d", &n) != 1 || n < 1 || n > NMAX) {
    printf("Error: invalid size\n");
    return 1;
}
for (int i = 0; i < n; i++) {       // < n, not <= n
    scanf("%d", &v[i]);             // & is needed for one element
}
```

## Arrays and functions

Pass the array **and** its size. The size in `[]` can be left out:

```c
int sum_array(int n, int v[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    return sum;
}

int v[NMAX] = {10, 30, -1, 4, 5};
int s = sum_array(5, v);            // s = 48
```

**An array is not copied** when passed to a function. The function gets the address where the array starts, so it works on the **same** elements. Changes made inside are visible in the caller. This is different from `int` parameters (see `swap` in lab 3):

```c
void reset(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        v[i] = 0;                   // changes the caller's array
    }
}
```

A function can not return an array. It fills one received as a parameter, and returns something small, such as the count.

## How an array sits in memory

```
        +------+------+------+------+------+
v:      |  10  |  30  |  -1  |   4  |   5  |
        +------+------+------+------+------+
index:    v[0]   v[1]   v[2]   v[3]   v[4]
```

C does not check the index. `v[7]` reads whatever is at that location after `v`: another variable, garbage, or a crash. Checking the bounds is your job.

## Frequency vectors

When the values are small and in a known range, use the **value as the index** and count:

```c
int count[6] = {0};                 // must start at 0
int code;
while (scanf("%d", &code) == 1) {
    if (code >= 100 && code <= 599) {   // check the range before indexing
        count[code / 100]++;        // 404 -> count[4]++
    }
}
// count[4] = how many 4xx codes were read
```

```
frequency(v, n, MAXV):
    count[0 .. MAXV-1] = 0
    for i = 0 .. n-1:
        count[v[i]] += 1
    // count[x] = how many times x appears in v
```

Used for: counting, finding duplicates (`count[x] > 1`), the most frequent value, checking anagrams, letter statistics (`count[c - 'a']`).

## Common mistakes

| Mistake | Example | Fix |
|---|---|---|
| out of bounds | `for (i = 0; i <= n; i++)` | `i < n` |
| size not checked | `scanf("%d", &n);` then `v[n - 1]` with `n = 500` | check `1 <= n <= NMAX` |
| uninitialized counters | `int count[26];` | `int count[26] = {0};` |
| mixed-up indexes | `v[i]` written as `v[j]` in nested loops | name indexes clearly |
| magic sizes | `int v[100];` and `i < 100` everywhere | `#define NMAX 100` |
