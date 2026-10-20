## Problem Statement

**IPv4 address in binary**

Subnet masks and routing tables are easiest to understand in binary. Write a program that reads an IPv4 address and prints each octet in binary.

Read the address in dotted form with `scanf("%d.%d.%d.%d", ...)`. Each octet must be in [0, 255]. Print the four octets as 8-bit groups separated by dots.

The printing of one number in binary must be done by this **recursive** function:

```c
void print_binary(unsigned int value, int bits);
```

It prints the lowest `bits` bits of `value`, most significant bit first, and **no newline**. There must be no loop inside it.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | the input is not a valid dotted address, or an octet is outside [0, 255] |

**Constraint:** `print_binary` must call itself. No `for`, `while` or `do while` inside it, and no arrays.

**Examples**

```
192.168.1.10   ->  11000000.10101000.00000001.00001010
10.0.0.1       ->  00001010.00000000.00000000.00000001
255.255.255.0  ->  11111111.11111111.11111111.00000000
300.1.1.1      ->  Error: octet out of range         (exit code 1)
1.2.3          ->  Error: invalid address            (exit code 1)
```

**Hints**
- Base case: `bits == 0`, nothing left to print.
- Recursive case: the bit to print last is `value & 1`. The bits before it are `value >> 1` with `bits - 1` bits.
- To get the most significant bit first, make the recursive call **before** printing the current bit.
- `scanf` returns `4` when all four octets were read. Check it, then check each range.
- Print the dots and the final newline from `main`.

## Questions to verify knowledge
- What is the base case and why does it guarantee that the recursion stops?
- What happens to the output if you print `value & 1` **before** the recursive call?
- How many calls (and how many stack frames at most) does `print_binary(x, 8)` use?
- Why does the function take `bits` as a parameter instead of stopping when `value` becomes `0`? What would the output be for `10` then?
- Where have you seen a subnet mask like `255.255.255.0`? Which bits are `1`?
