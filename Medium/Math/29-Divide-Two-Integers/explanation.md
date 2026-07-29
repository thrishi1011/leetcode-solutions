# Divide Two Integers

**Difficulty:** Medium | **Language:** cpp

# Divide Two Integers: Solution Explanation

### Approach
The algorithm solves the division problem by using the concept of bitwise shifts, which effectively mimics long division without using multiplication, division, or modulo operators. By repeatedly doubling the divisor (shifting it left), we can quickly determine how many times it fits into the dividend. This "exponential doubling" approach allows us to subtract large chunks of the divisor from the dividend at once, significantly reducing the number of subtractions required compared to a simple linear approach.

### Step-by-step Explanation

1.  **Handle Special Cases:**
    The problem specifies that the quotient must fit within a 32-bit signed integer. The only case where an overflow occurs is when dividing `INT_MIN` (-2,147,483,648) by -1, which results in a positive value exceeding the capacity of a 32-bit integer. We catch this immediately and return `INT_MAX`.

2.  **Determine the Sign:**
    We check the signs of the dividend and divisor using the XOR operator (`^`). If one is negative and the other is positive, the result will be negative. Otherwise, it will be positive. We then convert both numbers to absolute values using `long long` to prevent potential overflow issues during calculation.

3.  **The "Doubling" Strategy:**
    Instead of subtracting the divisor one by one (which is too slow), we use a loop to see how many times the divisor can be "doubled" (shifted left) and still be less than or equal to the current dividend. For example, if we are dividing 10 by 3:
    *   3 shifted left once is 6 (fits into 10).
    *   6 shifted left once is 12 (too big).
    *   We subtract 6 from 10, leaving 4, and add the "multiple" (which is 2) to our answer.

4.  **Iterative Subtraction:**
    We repeat the doubling process until the remaining dividend is smaller than the divisor. Each iteration effectively finds the largest power of two multiple of the divisor that fits into the current remainder, building up the quotient piece by piece.

5.  **Final Cleanup:**
    Once the loop finishes, we apply the sign we calculated in step 2. Before returning the final result, we check if the answer is within the valid 32-bit integer range to satisfy the problem's constraints.

### Complexity Analysis

*   **Time Complexity: O((log N)^2)**
    In each step of the outer `while` loop, we reduce the dividend by at least half of its current value (because we subtract the largest possible shifted divisor). Within the inner loop, we perform a bitwise shift, which is logarithmic relative to the magnitude of the dividend. This results in a logarithmic number of iterations, making the complexity O((log N)^2).

*   **Space Complexity: O(1)**
    We only use a fixed number of `long long` variables to track the dividend, divisor, and current quotient, regardless of the input size. Thus, the space usage remains constant.
