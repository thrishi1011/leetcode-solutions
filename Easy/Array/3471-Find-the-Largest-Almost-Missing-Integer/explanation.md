# Find the Largest Almost Missing Integer

**Difficulty:** Easy | **Language:** python

# Largest Almost Missing Integer

### Approach Summary
The problem asks us to find the largest integer that appears in exactly one subarray of size `k`. Since the constraints are small (array size up to 50), we can utilize a frequency-based observation: any number that appears in only one subarray must be located at either the very beginning or the very end of the array. If a number is positioned in the middle, it will naturally be included in multiple sliding windows of size `k`. By analyzing the frequency of these edge elements, we can determine which candidates satisfy the condition and identify the largest among them.

### Step-by-Step Explanation

1.  **Frequency Mapping:** We first count the total occurrences of every number in the array using a dictionary (`mp`). This helps us understand how many times each number appears in the entire array.
2.  **Handling Edge Cases:**
    *   **Case `k = 1`:** If the subarray size is 1, a number appears in "exactly one subarray" if and only if it appears in the original array exactly once. We collect all numbers with a frequency of 1 and return the largest one. If no such number exists, we return -1.
    *   **Case `k = n`:** If the subarray size is equal to the length of the array, there is only one subarray: the entire array itself. Therefore, every number in the array exists in exactly one subarray. In this case, the largest number in the array is the answer.
3.  **General Case (`1 < k < n`):** 
    *   A number can only appear in exactly one subarray if it is located at the extreme ends of the array. If a number in the middle appeared only once, it would be included in all windows that overlap its position, making it appear in more than one subarray.
    *   We check the first element (`nums[0]`) and the last element (`nums[n-1]`). If their total frequency in the array is exactly 1, they are guaranteed to appear in only one subarray of size `k`.
    *   We store any candidates that meet this criteria and return the maximum value. If no candidates are found, we return -1.

### Complexity Analysis

*   **Time Complexity:** $O(n)$, where $n$ is the length of the input array. We iterate through the array once to build the frequency map and perform a constant number of lookups afterwards.
*   **Space Complexity:** $O(U)$, where $U$ is the number of unique elements in the array. In the worst case, we store the frequency of every unique integer in a dictionary, which is at most $O(n)$ given the constraints.
