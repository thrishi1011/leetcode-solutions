# Minimum Sum of Squared Difference

**Difficulty:** Medium | **Language:** C++

# Minimum Sum of Squared Difference

### Approach Summary
To minimize the sum of squared differences, we want to reduce the largest absolute differences as much as possible. Since squaring a number grows exponentially, reducing a large difference (e.g., $10^2 \to 9^2$) yields a much greater reduction in the total sum than reducing a small difference (e.g., $2^2 \to 1^2$). We combine the total number of allowed modifications $k1$ and $k2$ into a single pool $k$, calculate the initial absolute differences, and use a frequency array (a form of counting sort) to track how many pairs have a specific difference. We then iteratively move "counts" from larger differences down to smaller ones until we run out of modifications.

### Step-by-step Explanation

1.  **Calculate Initial Differences:**
    First, we observe that it doesn't matter whether we modify `nums1` or `nums2`; what matters is the absolute difference between the pairs. We calculate $d_i = |nums1[i] - nums2[i]|$ for all $i$. The total number of operations we can perform is simply $k = k1 + k2$.

2.  **Use Frequency Mapping:**
    Instead of sorting the differences (which would be slow if many are identical), we count the frequency of each difference using a `freq` array. The index of the array represents the difference value, and the value at that index represents how many pairs share that difference.

3.  **Greedy Reduction:**
    We iterate from the largest possible difference down to 1. At each step, we have `freq[i]` items with difference `i`. We want to reduce these to `i-1` to minimize the squared sum. 
    *   We determine how many of these items we can reduce using our remaining operations `k`. This is `min(freq[i], k)`.
    *   We subtract that amount from the current difference level (`freq[i]`) and add it to the next lower level (`freq[i-1]`). 
    *   We decrement our total available operations `k` accordingly.
    *   This process effectively "shaves off" the top layers of our differences until we run out of modifications.

4.  **Calculate Final Sum:**
    Once we have exhausted our modifications or reached a difference of zero, the `freq` array contains the final count of each difference. We calculate the sum of squares by iterating through the `freq` array and computing $\sum (\text{count} \times \text{value}^2)$.

### Complexity Analysis

*   **Time Complexity:** $O(n + M)$, where $n$ is the number of elements and $M$ is the maximum difference (up to $10^5$). We iterate through the arrays once to calculate initial differences and populate the frequency array ($O(n)$), and then iterate through the frequency array at most once ($O(M)$).
*   **Space Complexity:** $O(n + M)$. We store the initial differences in an array of size $n$ and maintain a frequency array of size $M$ to track the counts of those differences.
