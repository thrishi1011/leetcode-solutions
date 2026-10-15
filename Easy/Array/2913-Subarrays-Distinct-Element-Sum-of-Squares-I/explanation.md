# Subarrays Distinct Element Sum of Squares I

**Difficulty:** Easy | **Language:** C++

# Solution: Subarrays Distinct Element Sum of Squares I

### Approach Summary
The problem asks us to calculate the sum of squares of distinct element counts across all possible contiguous subarrays. Since the constraints are small (array length up to 100), we can use a brute-force approach with an optimized nested loop. We iterate through every possible starting position of a subarray and then expand to every possible ending position. As we expand each subarray to the right, we keep track of which numbers have already appeared using a `bitset` (or a hash set), allowing us to maintain an accurate count of distinct elements in constant time. For every subarray we define, we square that count and add it to our running total.

### Step-by-Step Explanation

1.  **Outer Loop (Starting Points):** We use an index `l` to represent the start of a subarray. By iterating `l` from 0 to the end of the array, we ensure that we eventually evaluate every possible subarray.
2.  **Resetting State:** Before starting to expand from index `l`, we clear our tracker (the `bitset`). We also reset `cnt`, which keeps track of how many *unique* numbers exist in the current window (from `l` to `r`).
3.  **Inner Loop (Expanding Subarrays):** We use an index `r` to extend the current subarray one element at a time to the right (`nums[l..r]`).
4.  **Counting Distinct Elements:** As we move `r`, we check if the current number `nums[r]` has been seen before in the current window using the `seen` bitset.
    *   If `seen[x]` is 0, this is the first time we've encountered this number in this specific subarray, so we increment our `cnt`.
    *   We then mark `seen[x]` as 1 to ensure that if this number appears again in the same subarray, we don't increment the count again.
5.  **Accumulating the Result:** Once we know the number of distinct elements in the current subarray `[l..r]`, we square that count (`cnt * cnt`) and add it to the final `ans`. Because we do this for every `r` and every `l`, we successfully cover every possible subarray in the input.

### Complexity Analysis

*   **Time Complexity:** $O(n^2)$, where $n$ is the length of the input array. We use two nested loops to traverse all possible subarrays, and inside the inner loop, all operations (checking/updating the bitset and basic arithmetic) take constant $O(1)$ time.
*   **Space Complexity:** $O(1)$ (or $O(M)$, where $M$ is the range of values). The `bitset` is of a fixed size (101 bits based on the problem constraints), meaning it does not grow with the input size $n$, effectively occupying a constant amount of memory.
