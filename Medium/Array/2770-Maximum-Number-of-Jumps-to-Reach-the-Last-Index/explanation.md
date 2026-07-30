# Maximum Number of Jumps to Reach the Last Index

**Difficulty:** Medium | **Language:** cpp

# Solution: Maximum Number of Jumps to Reach the Last Index

### Approach Summary
To solve this problem, we use **Dynamic Programming (DP)**. We define an array `dp` where `dp[i]` represents the maximum number of jumps needed to reach index `i` starting from index 0. By iterating through each index `i` and checking all previous indices `j`, we determine if a valid jump exists according to the `target` constraint. If it is possible to reach index `j` (i.e., `dp[j] != -1`) and the jump condition is met, we update `dp[i]` with the maximum path length found so far.

### Step-by-Step Explanation

1.  **Initialization**: We create a `dp` array of size `n` initialized to `-1`. A value of `-1` indicates that an index is currently unreachable. We set `dp[0] = 0` because we start at index 0 and need zero jumps to be there.
2.  **Outer Loop (Target Index)**: We iterate through every index `i` from 1 to `n-1`. This represents the destination we are trying to reach.
3.  **Inner Loop (Source Index)**: For every destination `i`, we look back at all possible previous indices `j` (where `j < i`). This allows us to check every possible jump that could land us on `i`.
4.  **Verification**: For each pair `(i, j)`, we perform two checks:
    *   **Is `j` reachable?**: We check `dp[j] != -1`. If it's `-1`, it means there is no valid path to `j`, so we cannot jump from it to `i`.
    *   **Is the jump valid?**: We verify the condition `-target <= nums[j] - nums[i] <= target` using the `abs()` function. This ensures the difference between the values at the two indices is within the allowed threshold.
5.  **State Update**: If both conditions are met, we update `dp[i]` by taking the maximum of its current value and `dp[j] + 1` (the number of jumps to reach `j` plus the current jump).
6.  **Result**: After filling the table, `dp[n-1]` contains the maximum jumps to the end. If it remains `-1`, it means the last index is unreachable.

### Complexity Analysis

*   **Time Complexity**: **O(n²)**, where `n` is the length of the `nums` array. This is because we use nested loops to iterate through all possible pairs of indices `(i, j)`.
*   **Space Complexity**: **O(n)**, as we use a single `dp` array of size `n` to store the maximum jumps for each index.
