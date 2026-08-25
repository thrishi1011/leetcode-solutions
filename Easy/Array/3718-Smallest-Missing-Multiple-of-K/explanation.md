# Smallest Missing Multiple of K

**Difficulty:** Easy | **Language:** Python

### Approach Summary
The algorithm uses a brute-force search to identify the smallest multiple of `k` that is not present in the input array. It iteratively generates multiples of `k` starting from $1 \times k$ and checks whether each value exists within the given list. By incrementing a counter and multiplying it by `k` at each step, the algorithm effectively "scans" the sequence of multiples ($k, 2k, 3k, \dots$) and stops as soon as it encounters a value that is missing from the `nums` collection.

### Step-by-Step Explanation

1.  **Initialize a Multiplier:** We start with an integer `i = 1`. This variable represents the "step" of the multiple we are currently checking.
2.  **Continuous Checking:** We enter a `while` loop that checks the condition `i * k in nums`. 
    *   If the current multiple (e.g., $1 \times k$, $2 \times k$, etc.) is already found inside the `nums` array, we know it is not the missing number we are looking for.
    *   Consequently, we increment `i` by 1 to move to the next multiple in the sequence.
3.  **Termination:** The loop continues to run as long as the current multiple exists in the list. Because the list is finite, this loop is guaranteed to terminate once we reach a multiple of `k` that is not present in the array.
4.  **Return the Result:** As soon as the condition `i * k in nums` becomes `False`, the loop stops. The value `i * k` is the smallest multiple of `k` missing from the array, so we return it.

### Complexity Analysis

*   **Time Complexity:** $O(N \cdot M)$, where $N$ is the length of `nums` and $M$ is the number of multiples checked until we find one that is missing. In the worst case, we check each multiple against the entire list, resulting in a linear scan of the array for each multiple tested. Given the constraints (length up to 100), this is very efficient.
*   **Space Complexity:** $O(1)$. We only use a single integer variable (`i`) to track our progress, regardless of the size of the input array. (Note: Using a `set` to store `nums` would improve look-up time to $O(1)$, but would increase space complexity to $O(N)$).
