# Find the Largest Almost Missing Integer

**Difficulty:** Easy | **Language:** C++

# Solution: Find the Largest Almost Missing Integer

### Approach Summary
The problem asks for the largest integer that appears in exactly one subarray of size `k`. By analyzing the constraints and the nature of "subarrays of size `k`," we can observe a key pattern: any number that appears in the middle of the array will naturally appear in multiple subarrays. Specifically, if a number appears in a subarray of size `k` that is not at the very beginning or the very end of the total array, it is likely to overlap with neighbors. Consequently, the only candidates that can appear in *exactly one* subarray of size `k` (where `1 < k < n`) are the first element of the array and the last element of the array, provided they do not appear anywhere else in the entire array. The algorithm handles this by using a frequency map to identify unique elements and applying specific rules based on the size of `k` relative to the array length `n`.

### Step-by-Step Explanation

1. **Frequency Counting:** We first use an `unordered_map` to count the total occurrences of every number in the array. This helps us quickly verify if a specific number appears more than once in the entire `nums` array.
2. **Handling `k = 1`:** When the subarray size is 1, a subarray is just a single element. A number appears in exactly one subarray of size 1 if and only if it appears exactly once in the entire array. We collect all numbers with a frequency of 1 and return the largest among them. If none exist, we return -1.
3. **Handling `k = n`:** If the subarray size is equal to the length of the array, there is only one possible subarray: the entire array itself. Therefore, every number present in the array appears in exactly that one subarray. In this case, the largest number in the array is our answer.
4. **Handling `1 < k < n`:** This is the core logic. For a number to appear in *exactly one* subarray of size `k`, it must be restricted to either the very first position or the very last position of the original array. 
   - A number in the "middle" will always be shifted into at least two different windows of size `k`.
   - Therefore, we check the first element (`nums[0]`) and the last element (`nums[n-1]`). If either of these elements appears exactly once in the entire array (based on our frequency map), it is a candidate for being "almost missing."
   - We compare the valid candidates and return the largest one. If neither qualifies, we return -1.

### Complexity Analysis

*   **Time Complexity:** $O(n)$, where $n$ is the length of the input array. We iterate through the array once to build the frequency map ($O(n)$) and then perform a constant number of lookups and comparisons ($O(1)$).
*   **Space Complexity:** $O(n)$ in the worst case, as the frequency map may store up to $n$ unique elements if all numbers in the input array are distinct.
