## Problem Statement

**Colors**

An RGB color is written `#RRGGBB`: three bytes (red, green, blue), each as two hexadecimal digits. Example: `#FF8000` is red `FF` (255), green `80` (128), blue `00` (0).

Each channel goes from 0 to 255, where 255 means 100% intensity. Read a color in this exact format and print the intensity of each channel as a percentage with exactly 1 decimal.

If the input does not match the format, print an error message and return `1`.

**Examples**

```
#FF8000  ->  Red: 100.0%
             Green: 50.2%
             Blue: 0.0%

#1A2B3C  ->  Red: 10.2%
             Green: 16.9%
             Blue: 23.5%

#000000  ->  Red: 0.0%
             Green: 0.0%
             Blue: 0.0%
```

**Hints**
- `%x` reads a hexadecimal number. Add a width to read exactly 2 digits.
- Percentage = `value / 255 * 100`. Careful with integer division.
- To print a literal `%` with `printf`, write `%%`.

## Questions to verify knowledge
- What does `128 / 255 * 100` give if all values are `int`? Why?
- How do you force a division to use real numbers?
- What does `%%` print, and why is it needed?
- What does `scanf` return for `#GG0000`? For `#FF80`?
- Why `%2x` during `scanf` and not just `%x`?
