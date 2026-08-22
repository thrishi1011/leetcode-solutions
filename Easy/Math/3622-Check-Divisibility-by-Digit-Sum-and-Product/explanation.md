# Check Divisibility by Digit Sum and Product

**Difficulty:** Easy | **Language:** C++

# Check Divisibility by Digit Sum and Product

### Approach Summary
To determine if a number is divisible by the sum of its own digits and the product of its own digits, we use a digit-extraction algorithm. By repeatedly applying the modulo operator (`% 10`), we isolate the last digit of the number, update a running sum and a running product, and then remove the last digit using integer division (`/ 10`). Once all digits have been processed, we check if the original number is divisible by the calculated total (sum + product) using the modulo operator.

### Step-by-Step Explanation

1.  **Initialization**: We prepare three variables. `a` is initialized to 1 to track the product of digits (multiplying by 1 maintains the product), `b` is initialized to 0 to track the sum, and `l` creates a copy of the input `n` so we can extract its digits without losing the original value.
2.  **Digit Extraction Loop**: We enter a `while` loop that runs as long as `l` is greater than 0. 
    *   **Isolate Digit**: The expression `l % 10` gives us the rightmost digit of the current number.
    *   **Update Tracking**: We multiply this digit into `a` (our product) and add it to `b` (our sum).
    *   **Reduce Number**: We perform `l /= 10` to discard the digit we just processed. This shifts the decimal place, effectively moving to the next digit to the left.
3.  **Final Check**: After the loop finishes, we have the total product in `a` and the total sum in `b`. We check if `n` is divisible by the sum of these two values (`a + b`). If the remainder of `n / (a + b)` is 0, the number is divisible, and we return `true`; otherwise, we return `false`.

### Complexity Analysis

*   **Time Complexity**: **O(d)**, where *d* is the number of digits in *n*. Since we process each digit exactly once, and the number of digits is proportional to $\log_{10}(n)$, the algorithm scales logarithmically with the size of the input.
*   **Space Complexity**: **O(1)**. We only use a fixed number of integer variables (`a`, `b`, `l`, `k`) regardless of the size of the input, meaning the memory usage remains constant.
