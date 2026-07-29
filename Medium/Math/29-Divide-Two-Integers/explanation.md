# Divide Two Integers

**Difficulty:** Medium | **Language:** cpp

# Divide Two Integers: Solution Explanation

### Approach Summary
Since we are forbidden from using multiplication, division, or the modulo operator, we solve this problem using **bit manipulation** and the concept of **repeated subtraction**. Instead of subtracting the divisor one by one (which is too slow), we subtract the divisor multiplied by powers of two. By doubling the divisor (using the left-shift operator `<<`) until it is as large as possible without exceeding the remaining dividend, we can efficiently "chunk" the division, effectively performing long division in binary form. This brings the time complexity down from linear to logarithmic.

### Step-by-Step Explanation

1.  **Handling Edge Cases and Signs**:
    *   There is a unique edge case: if the `dividend` is `INT_MIN` and the `divisor` is `-1`, the result would exceed the positive 32-bit integer range (`2^31`), so we manually return `INT_MAX`.
    *   We determine the final sign of the result by checking if the signs of the dividend and divisor are different using the XOR (`^`) operator. If they are different, the result must be negative.

2.  **Working with Absolute Values**:
    *   To simplify calculations, we convert both numbers to `long long` positive values. Using `long long` prevents potential overflow issues when we convert `INT_MIN` (which is `-2^31`) to a positive value (which would be `2^31`, exceeding the `int` limit).

3.  **The Bit-Shifting Logic**:
    *   We use a `while` loop that continues as long as the current dividend (`a`) is greater than or equal to the divisor (`b`).
    *   Inside, we use an inner loop to find the largest multiple of the divisor that fits into the current dividend. We repeatedly shift the divisor left (`temp <<= 1`), which is equivalent to multiplying it by 2. We keep track of this multiplier as well, starting at 1 and doubling it each time.
    *   Once we find the largest shifted value that fits, we subtract that value from our dividend and add the corresponding power of two to our running total quotient (`ans`).

4.  **Finalizing the Result**:
    *   After the loop finishes, we apply the sign we calculated in step one.
    *   Finally, we perform a safety check to ensure the result stays within the 32-bit signed integer boundaries (`INT_MIN` to `INT_MAX`) and cast the result back to an `int` before returning.

### Complexity Analysis

*   **Time Complexity**: **O(log² N)**, where N is the dividend. 
    *   In the outer loop, we reduce the dividend exponentially. In each step of the inner loop, we double the divisor. Since we are using bit shifts, the inner loop runs at most 32 times (the number of bits in an integer). Because we are essentially performing binary division, the overall complexity is logarithmic with respect to the input values.
*   **Space Complexity**: **O(1)**.
    *   We only use a few constant variables (`a`, `b`, `ans`, `temp`, `multiple`) to track the progress of the division, regardless of how large the input numbers are.
