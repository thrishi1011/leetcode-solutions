# Find Missing Elements

**Difficulty:** Easy | **Language:** C++

# Solution: Find Missing Elements

### Approach Summary
The algorithm identifies the missing numbers in a range by first determining the boundary values of the input array. By iterating through every integer between the minimum and maximum values found in `nums`, the code checks if each integer exists within the original array. If an integer from this range is not found in the input, it is identified as "missing" and added to a result list. Since we iterate through the range in ascending order, the final list is naturally sorted, ensuring the output meets the problem requirements.

### Step-by-Step Explanation

1.  **Find the Range Boundaries:** 
    Before we can determine what is missing, we need to know the start and end of the sequence. We initialize `minnum` and `maxnum` using the first element of the array. We then iterate through the entire input array, updating `minnum` if we find a smaller value and `maxnum` if we find a larger one. This gives us the full scope of the original range.

2.  **Scan for Missing Values:** 
    Once we have the boundaries, we use a loop to check every integer `i` starting from `minnum` up to `maxnum`. For every `i`, we perform a "lookup" by iterating through the original `nums` array to see if that specific number is present.

3.  **Collect Results:** 
    If our lookup loop completes without finding the current integer `i` (signified by our `found` flag remaining `false`), we know that `i` is missing. We add it to our `ans` vector.

4.  **Final Formatting:** 
    Although the logic of checking the range from `minnum` to `maxnum` ensures the missing numbers are added in increasing order, we apply a sort at the end as a safeguard to guarantee the returned list is perfectly sorted.

### Complexity Analysis

*   **Time Complexity:** $O(N \times R)$, where $N$ is the number of elements in `nums` and $R$ is the size of the range (max - min). For each number in the range, we perform a linear scan of the input array. Given the constraints (max 100 elements), this is highly efficient.
*   **Space Complexity:** $O(R)$, as in the worst-case scenario (where almost all numbers in the range are missing), our `ans` vector will store nearly all integers within the range.
