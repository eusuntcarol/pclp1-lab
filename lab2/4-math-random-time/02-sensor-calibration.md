## Problem Statement

**Sensor calibration**

A temperature sensor is calibrated against a reference thermometer. The sensor is read, a correction (the **offset**) is added to the reading, and the corrected value must match the value shown by the reference thermometer.

Read three real numbers from the keyboard, in this order:
1. the raw sensor reading
2. the calibration offset
3. the reference value

The calibration **passes** if `reading + offset` is equal to the reference with a precision of **4 decimals**, which means the absolute value of their difference is **strictly smaller than `0.0001`**.

Print two lines: the verdict using a plain `==`, then the verdict using the 4-decimals rule. Each verdict is `EQ` or `NOT EQ`.

**Examples**

```
15.2 0.1 15.3
->  Plain ==: NOT EQ
    4 decimals: EQ

15.3 0.3 15.6
->  Plain ==: NOT EQ
    4 decimals: EQ

21.5 0.25 21.75
->  Plain ==: EQ
    4 decimals: EQ

20.1 0.2 20.5
->  Plain ==: NOT EQ
    4 decimals: NOT EQ
```

The first two cases are the interesting ones: the calibration is correct, but a plain `==` says it failed.

**Hints**
- Read `double` values with `%lf`.
- The absolute value of a real is `fabs`, from `<math.h>`. Link with `-lm`.

## Questions to verify knowledge
- Why does `15.2 + 0.1 == 15.3` give false, while `21.5 + 0.25 == 21.75` gives true? How are reals stored in memory?
- Which of the two verdicts would you trust in a real program, and why?
- What is the type of `fabs`' argument and return value? What would `abs` do instead?
- Would a threshold of `0.0001` still make sense for values around `1000000`?
