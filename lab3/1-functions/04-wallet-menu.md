## Problem Statement

**Wallet menu**

Write a tiny terminal wallet. The balance starts at `100`. The program shows a menu, reads the user's choice, performs the action and shows the menu again, until the user chooses `0`.

```
1. Show balance
2. Deposit
3. Withdraw
0. Exit
```

Actions:

| Choice | Action |
|---|---|
| 1 | print `Balance: <balance>` |
| 2 | read an amount, if it is positive add it to the balance and print `Deposited <amount>`, otherwise print `Error: invalid amount` |
| 3 | read an amount, if it is positive and `can_withdraw` allows it, subtract it and print `Withdrawn <amount>`; if it is positive but too large print `Error: insufficient funds`; if it is not positive print `Error: invalid amount` |
| 0 | print `Bye` and stop |
| anything else | print `Error: unknown option` |

Functions:

```c
void print_menu(void);                          // prints the 4 menu lines
int can_withdraw(int balance, int amount);      // returns 1 if amount <= balance, otherwise 0
```

The balance variable lives in `main` and is changed only in `main`.

If the input ends or is not a number, stop the program with exit code `1`.

**Constraint:** the loop must be `do { ... } while (...)`. The menu is shown before every read of the choice.

**Examples**

Input `2 50 3 500 1 0` (menu lines not repeated here, but printed before every choice):

```
Deposited 50
Error: insufficient funds
Balance: 150
Bye
```

Input `3 -5 9 1 0`:

```
Error: invalid amount
Error: unknown option
Balance: 100
Bye
```

**Hints**
- A menu has to be shown at least once, before the first choice is read. This is exactly what `do while` guarantees.
- `can_withdraw` cannot change `balance`: it only receives a copy. `main` does the subtraction after the check.
- Handle the amounts with `switch (choice)`. Inside `case 2:` and `case 3:` use `if` for the checks.
- Keep the loop condition simple: `while (choice != 0)`. Declare `choice` before the `do`.

## Questions to verify knowledge
- Why is `do while` a better fit than `while` for a menu?
- What does `void print_menu(void)` mean? What is the difference to `print_menu()`?
- Could `can_withdraw` subtract the amount from `balance` itself? Why not?
- Why does the function return `1`/`0` instead of printing the error message?
- What happens if the user keeps entering `3` with an amount larger than the balance?
