# Smallest Stable Index I

**Difficulty:** Easy | **Language:** C++

# Smallest Stable Index I

### Approach Summary
To find the smallest stable index efficiently, we avoid re-calculating the minimum and maximum values from scratch for every index, which would be slow. Instead, we use a pre-processing strategy: we first pre-calculate the minimum values for all possible suffixes (from index $i$ to the end of the array) and store them in an auxiliary array. Then, we iterate through the array once, keeping track of the running maximum from the left. By combining this running maximum with our pre-calculated suffix minimums, we can check the instability score for each index in constant time.

### Step-by-step Explanation

1.  **Suffix Minimums (`suf` array):** 
    The instability score requires finding the minimum value from index $i$ to the end of the array ($n-1$). We compute this once by working backward from the last element. We create an array `suf` where `suf[i]` stores the smallest number encountered between index $i$ and the end of the array. By starting at the last index and moving left, `suf[i]` is simply the smaller of the current element `nums[i]` and the minimum value already found for the rest of the array (`suf[i+1]`).

2.  **Tracking the Running Maximum:**
    The instability score also requires the maximum value from the start of the array to index $i$. As we iterate forward from $i = 0$ to $n-1$, we maintain a variable `maxSoFar`. At each step, we update this variable to be the maximum of its current value and `nums[i]`. This effectively gives us the `max(nums[0..i])` without needing a nested loop.

3.  **Evaluating Stability:**
    With `maxSoFar` representing the prefix maximum and `suf[i]` representing the suffix minimum, we calculate the instability score as `maxSoFar - suf[i]`. If this value is less than or equal to $k$, we have found our first (smallest) stable index, and we return it immediately.

4.  **Handling No Matches:**
    If the loop completes without ever satisfying the stability condition, it means no index qualifies as stable, so we return `-1`.

### Complexity Analysis

*   **Time Complexity: $O(n)$**
    We perform one pass backward to build the suffix minimum array ($O(n)$) and one pass forward to calculate the instability scores ($O(n)$). Since these operations are sequential, the total time complexity is linear.

*   **Space Complexity: $O(n)$**
    We use an auxiliary array `suf` of size $n$ to store the suffix minimums. While the problem constraints specify $n \le 100$, in a general case, this requires $O(n)$ extra space relative to the input size.
