## Problem Statement

**Data sizes**

We want to understand data types sizes.
Read the following C program.

```c
#include <stdio.h>

int main(void) {
    long long a = 4294967297;
    int b = a;

    printf("%d\n", b);

    return 0;
}
```

1. What you'd expect to print on the screen? What is actually being printed?
1. Why? Let's *debug*. You may want to use `sizeof` operator.
1. How you'd modify the program to print that big number?
1. Add `unsigned int u = 0; u = u - 1;`. Print `u` with `%u` and `%d`. What do you observe?

## Questions to verify knowledge
- Size of int in bytes?
- Size of long long in bytes?
- How are numbers represented in memory?
- What does unsigned overflow do?
