## Problem Statement

**Log error counter**

A web server writes one HTTP status code per request. Write a program that reads all the codes from standard input and reports how many requests failed.

Read integers until the input ends (or an invalid token appears). Classify each code:

| Code | Class |
|---|---|
| 400 to 499 | client error |
| 500 to 599 | server error |
| below 100 or above 599 | invalid (not counted as a valid request) |
| anything else | ok |

Use these functions:

```c
int is_client_error(int code);    // returns 1 if code is 4xx, otherwise 0
int is_server_error(int code);    // returns 1 if code is 5xx, otherwise 0
int percent(int part, int whole); // part * 100 / whole, or 0 if whole is 0
```

At the end print the totals. `Total` counts every code read, `Error rate` is computed over the **valid** codes only (`total - invalid`).

**Constraint:** read with `while (scanf("%d", &code) == 1)`. Do not use `for` or `do while`.

**Examples**

Type the codes separated by spaces or newlines, then signal the end of the input with `Ctrl+D` (Linux/macOS) or `Ctrl+Z` then Enter (Windows). Lines starting with `$` or typed by you are shown first, the program output follows:

```
$ ./main
200 404 500 503 99 301 404 403
<Ctrl+D>
Total: 8
Client errors: 3
Server errors: 2
Invalid: 1
Error rate: 71%

$ ./main
200 301 204
<Ctrl+D>
Total: 3
Client errors: 0
Server errors: 0
Invalid: 0
Error rate: 0%

$ ./main
<Ctrl+D>
Total: 0
Client errors: 0
Server errors: 0
Invalid: 0
Error rate: 0%
```

(First example: 7 valid codes, 5 of them errors, `5 * 100 / 7 = 71`.)

The loop stops at the first thing that is not a number. Everything after it is ignored:

```
$ ./main
200 abc 404
<Ctrl+D>
Total: 1
Client errors: 0
Server errors: 0
Invalid: 0
Error rate: 0%
```

(`200` is read and counted. At `abc`, `scanf` returns `0`, so the loop ends. `404` is never read.)

Optional shortcut, so you do not have to type the codes every time: `echo "200 404 500" | ./main` sends that text to the program as if you had typed it, and ends the input for you.

**Hints**
- `scanf` returns how many values it converted: `1` when it read an integer, `EOF` at the end of the input, `0` on a token that is not a number.
- The functions return `1` or `0`, so they can be used directly in an `if`.
- `percent` needs an early `return 0;` for the case `whole == 0`, otherwise the program divides by zero.
- Call `is_client_error(code)` with the variable `code` as the actual parameter. Inside the function the formal parameter has the same or another name, both work.

## Questions to verify knowledge
- Why does the loop test `scanf(...) == 1` and not just `scanf(...)`?
- What does `scanf` return at the end of the input? What does it return when the next token is `abc`?
- What happens to the loop if you type `200 abc 404`? Which codes are counted and why?
- What is the exit code of `main` here? Where do you set it?
- Why must `percent` check `whole == 0` before dividing?
