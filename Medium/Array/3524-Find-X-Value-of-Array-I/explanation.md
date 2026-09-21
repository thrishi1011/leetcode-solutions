# Find X Value of Array I

**Difficulty:** Medium | **Language:** C++

### Approach Summary
The problem asks us to consider all possible subarrays created by removing a prefix and a suffix. Since a subarray is defined by its start index $i$ and end index $j$, every possible subarray can be uniquely identified. Instead of iterating through all $O(N^2)$ subarrays, we can observe that for every element `nums[j]`, the subarrays ending at `j` are formed by starting at any index $i \le j$. We use a dynamic programming approach (specifically, a frequency array) to maintain the counts of products of all subarrays ending at the previous index. As we iterate through the array, we update the frequency of possible products modulo $k$ by multiplying the current element with the previous results, which allows us to calculate the contribution of all subarrays ending at the current position in $O(N \cdot k)$ time.

### Step-by-Step Explanation

1.  **Understanding the Subarray Property**: Any subarray `nums[i...j]` can be formed by removing the prefix `nums[0...i-1]` and the suffix `nums[j+1...N-1]`. Because we want to find the remainder of the product of these subarrays modulo $k$, and $k$ is very small ($k \le 5$), we only need to track the remainder of the product of elements.

2.  **Maintaining Frequencies**: We use an array `freq` of size $k$ to store how many subarrays *ending at the previous index* produce a product with remainder $x$ (for $0 \le x < k$).

3.  **The Iteration Logic**:
    *   For each new number `n` in the input array:
    *   `n %= k`: We only care about the remainder of the current number to calculate the product modulo $k$.
    *   `cur` array: This temporary array tracks the remainders of all subarrays ending at the *current* position. 
    *   **Updating `cur`**: 
        *   A subarray consisting of just the current element `n` will have a remainder of `n % k`.
        *   Any subarray ending at the *previous* index can be extended by the current element `n`. If a previous subarray had a product remainder `x`, the new subarray will have a remainder `(x * n) % k`. We add the counts from `freq` into the corresponding `cur` slots.
    *   **Updating `res`**: After calculating all possible products ending at the current index, we add these counts to our global `res` array. This effectively aggregates the number of ways to achieve each remainder across all possible subarrays in the entire array.

4.  **Final Result**: After traversing the entire array, `res[x]` contains the total number of subarrays whose product leaves a remainder of $x$ when divided by $k$.

### Complexity Analysis

*   **Time Complexity**: $O(N \cdot k)$, where $N$ is the number of elements in `nums` and $k$ is the divisor. Since we iterate through the array once and perform a constant number of operations (looping $k$ times) for each element, this is highly efficient given the constraints.
*   **Space Complexity**: $O(k)$. We only use a few arrays of size $k$ (`freq`, `cur`, and `res`) to keep track of the remainder counts, regardless of the size of the input array.
