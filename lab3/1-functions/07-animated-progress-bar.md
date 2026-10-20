## Problem Statement

**Animated progress bar**

Build a progress bar that updates in place instead of printing one new line
for every percentage.

Write this function:

```c
void animate_progress(int width, int delay_ms);
```

The function must display a bar that starts at `0%` and advances to `100%`,
one percentage point at a time. The bar has `width` cells:

- filled cells are `#`
- empty cells are `-`
- the percentage is displayed after the bar

The function must overwrite the previous display on the same terminal line.
After reaching `100%`, print a newline.

`main` reads `width` and `delay_ms`. The width must be in [10, 80], and the
delay must be in [1, 1000] milliseconds. Call `animate_progress(width,
delay_ms)` after validating the input.

**Errors** (print a message and return the code):

| Code | Condition |
|---|---|
| 1 | the input is invalid, or `width` / `delay_ms` is outside its range |

**Examples**

```
$ ./main
20 25
[####################] 100%
```

The bar changes in place during the run, so only the final line is shown in
the example. With a width of `20` and a delay of `25`, the animation takes
approximately 2.5 seconds.

**Constraints**

- Use `\r` to return to the beginning of the current line.
- Call `fflush(stdout)` after drawing each frame.
- Wait `delay_ms` milliseconds between frames. Use `usleep` on Linux/macOS or
  `Sleep` on Windows.
- Use a `for` loop to draw the cells and another loop to advance from 0 to
  100 percent.
- Declare the prototype above `main` and define `animate_progress` below
  `main`.

**Hints**

- The filled cell count is `percent * width / 100`.
- Print `\r` before each frame. It does not print a visible character.
- Terminal output is buffered; `fflush(stdout)` makes each frame visible
  immediately.
- On Linux/macOS, include `<unistd.h>` and wait with:

  ```c
  usleep(delay_ms * 1000);
  ```

- On Windows, include `<windows.h>` and wait with:

  ```c
  Sleep(delay_ms);
  ```

- `usleep` receives microseconds, while `Sleep` receives milliseconds.
- Compile on Linux/macOS with:

  ```sh
  gcc -Wall -Wextra main.c -o main
  ```

  On Windows with MinGW, use:

  ```sh
  gcc -Wall -Wextra main.c -o main.exe
  ```

## Questions to verify knowledge

- Why does `\r` overwrite the current line instead of starting a new one?
- Why is `fflush(stdout)` needed for an animation?
- Why does `usleep` use `delay_ms * 1000`, while `Sleep` uses `delay_ms`?
- What would happen if the delay were placed before drawing the first frame?
- Why does the function print a newline after the final frame?
- Why is `percent * width / 100` calculated with integer arithmetic?
- What happens if the bar width is greater than the terminal width?
