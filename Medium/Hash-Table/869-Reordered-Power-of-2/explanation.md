# Reordered Power of 2

**Difficulty:** Medium | **Language:** C++

# Reordered Power of 2: Solution Explanation

### Summary
The core idea behind this solution is that two numbers are "reorderable" into each other if and only if they contain the exact same count of each digit (0–9). Since the input $N$ is limited to $10^9$, there are only a small number of powers of 2 that could possibly match the length of $N$ (specifically, powers of 2 from $2^0$ to $2^{29}$). By creating a unique "fingerprint" or signature for the input number based on its digit frequencies and comparing it to the signatures of all possible powers of 2, we can determine if a valid reordering exists without having to generate every possible permutation of $N$.

### Step-by-step Explanation

1.  **Creating the Digit Signature (`counter` function):** 
    To easily compare two numbers, we need a way to represent the count of each digit they contain. The `counter` function uses a clever mathematical trick: it treats the occurrence of each digit as a contribution to a sum. For every digit $d$ in the number, it adds $10^d$ to a total sum. For example, if a number has two 1s and one 3, the result would be $10^1 + 10^1 + 10^3$. This creates a unique "fingerprint" where each decimal position represents how many times a specific digit appeared. Using `long` ensures there is no overflow during this summation.

2.  **Iterating through Powers of 2:** 
    We know that $N$ is at most $10^9$. The largest power of 2 less than $10^9$ is $2^{29}$. Therefore, we only need to check the first 32 powers of 2 (from $2^0$ to $2^{31}$). The code loops through these values, calculating the digit fingerprint for each one.

3.  **Comparing Fingerprints:** 
    For each power of 2 generated in the loop, we call the `counter` function. If the fingerprint of a power of 2 exactly matches the fingerprint of the input $N$, it means that power of 2 contains the exact same digits as $N$. Thus, it is possible to reorder the digits of $N$ to form that power of 2, and we return `true`.

4.  **Final Result:** 
    If the loop completes and no match is found, it means no reordering of $N$ can form any power of 2, so we return `false`.

### Complexity Analysis

*   **Time Complexity:** $O(\log^2 N)$. 
    We iterate through approximately 30 powers of 2. For each power, the `counter` function performs a number of operations proportional to the number of digits in the integer, which is $O(\log N)$. Multiplying these gives us a complexity related to the square of the number of digits.
    
*   **Space Complexity:** $O(1)$. 
    We only store a few integer variables to track the counters and the loop index. The space used does not grow with the size of the input $N$.
