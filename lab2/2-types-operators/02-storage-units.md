## Problem Statement

**Storage units**

Read a number of bytes as `unsigned long long`. Print the equivalent number of gigabytes, megabytes, kilobytes, and bytes, using 1024 bytes per unit.

Use the units in this order:

- `1 KB = 1024 B`
- `1 MB = 1024 KB`
- `1 GB = 1024 MB`

The input must be a non-negative integer.

**Example**

```
1073742848 -> 1 GB, 0 MB, 1 KB, 0 B
```

Use `/` and `%` from largest unit to smallest. If `scanf` does not read one valid number, print `Error: expected a number` and return code `1`.

**Hints**

- The number of complete gigabytes is `bytes / (1024 * 1024 * 1024)`.
- The remainder after extracting a unit is the input for the next smaller unit.
- `%` gives the remainder after division.

## Questions to verify knowledge
- Why is `unsigned long long` suitable here?
- What does the remainder after division represent?
