## Problem Statement

**Serial number checksum**

Devices, tickets and parcels have serial numbers whose **last digit is a check digit**, so a typo can be caught before the number is used. The check digit is the last digit of the sum of all the other digits.

Write a program that reads one serial number and says if it is valid.

Example: in `4093` the digits before the last one are `4`, `0`, `9`. Their sum is `13`, and its last digit is `3`. The last digit of the serial is `3`, so the serial is valid.

Write three functions, each one using the previous:

```c
unsigned int digit_sum(unsigned int n);          // sum of the decimal digits of n (recursive)
unsigned int checksum(unsigned int serial);      // the check digit the serial should have
int is_valid_serial(unsigned int serial);        // 1 if the serial is valid, otherwise 0
```

- `digit_sum` is **recursive**.
- `checksum` computes the expected check digit: the last digit of the digit sum of the number without its last digit (`serial / 10`).
- `is_valid_serial` compares the last digit of the serial (`serial % 10`) with `checksum(serial)`.

`main` reads the serial as an integer, calls `is_valid_serial` and prints
`Serial OK` or `Serial corrupted`. Display the serial with four digits,
including leading zeroes when necessary.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | the input is not an integer or it is negative |

**Constraint:** `digit_sum` must call itself. No `for`, `while` or `do while` inside it.

**Examples**

```
$ ./main
4093
Serial 4093: OK          (4 + 0 + 9 = 13, last digit 3)

$ ./main
4096
Serial 4096: corrupted   (check digit should be 3, not 6)

$ ./main
12340
Serial 12340: OK         (1 + 2 + 3 + 4 = 10, last digit 0)

$ ./main
7
Serial 0007: corrupted   (there are no other digits, sum 0, but the last digit is 7)

$ ./main
-5
Error: serial must be a non-negative number       (exit code 1)
```

**Hints**
- Base case: a number with one digit (`n < 10`) is its own digit sum.
- Recursive case: the last digit is `n % 10`, the rest of the number is `n / 10`. The answer is the last digit plus the digit sum of the rest.
- `digit_sum(0)` is `0`. Check that your base case gives that.
- Read into a signed integer with `scanf("%d", &input)`, reject a negative
  `input`, then convert it to `unsigned int serial`. Print the value with
  leading zeroes using `printf("%04u", serial)`.
- `checksum` and `is_valid_serial` are one-liners once `digit_sum` works. Test each function on its own from `main` before putting them together.
- Trace `digit_sum(409)` on paper: write each call and what it returns.

## Questions to verify knowledge
- What is the base case? What would happen without it?
- Can you think of other stop criteria that would make the function do the same thing?
- What does `digit_sum(0)` return? Which line handles it?
- The serials `4093` and `4903` are both valid. What kind of typo does this checksum miss? (real systems use weighted sums, like Luhn on bank cards or ISBN)
- How many calls happen for a serial with 9 digits? How deep can the call stack get?
- Why split the work into `digit_sum`, `checksum` and `is_valid_serial` instead of one function? What can you reuse if you later need to **generate** a serial with the right check digit?
