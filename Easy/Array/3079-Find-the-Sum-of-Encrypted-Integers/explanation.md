# Find the Sum of Encrypted Integers

**Difficulty:** Easy | **Language:** cpp

# Sum of Encrypted Integers

### Approach Summary
The algorithm processes the array by transforming each integer into its "encrypted" version and summing them up. To encrypt a number, we first identify its largest digit. We then reconstruct a new number with the same number of digits as the original, where every position is filled by that maximum digit. This is achieved mathematically: a number consisting of $n$ identical digits $d$ can be represented as $d \times \frac{10^n - 1}{9}$ (e.g., for three 5s, $5 \times 111 = 555$).

### Step-by-Step Explanation

1.  **Iterating through the array:** We initialize a running total (`ans`) to zero and loop through every integer in the input vector `nums`. For each integer, we call the `encrypt` helper function.
2.  **Finding the maximum digit:** Inside the `encrypt` function, we convert the integer into a string to easily access its individual digits. By sorting this string, the largest digit is moved to the final position (`s[n-1]`). We convert this character back into an integer (`maxnum`).
3.  **Constructing the encrypted number:** 
    *   First, we determine how many digits the original number had ($n$).
    *   We create a multiplier by calculating $10^n$. For example, if the number is 523 ($n=3$), $10^3 = 1000$.
    *   The formula `(num - 1) / 9` creates a sequence of ones equal to the length of the number (e.g., $(1000 - 1) / 9 = 111$).
    *   Finally, multiplying this sequence of ones by our `maxnum` creates the encrypted value (e.g., $111 \times 5 = 555$).
4.  **Summation:** The result of each encryption is added to the running total, which is returned after all elements have been processed.

### Complexity Analysis

*   **Time Complexity:** $O(N \cdot K \log K)$, where $N$ is the number of elements in the array and $K$ is the number of digits in the integers. Since the constraints state the numbers are at most 1000, $K$ is at most 4, making this effectively $O(N)$. The sorting step takes $O(K \log K)$ per number.
*   **Space Complexity:** $O(K)$, where $K$ is the number of digits. We store the string representation of the number to identify the maximum digit, which uses space proportional to the number of digits in the largest input integer.
