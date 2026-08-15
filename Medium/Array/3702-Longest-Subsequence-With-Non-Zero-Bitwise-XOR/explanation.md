# Longest Subsequence With Non-Zero Bitwise XOR

**Difficulty:** Medium | **Language:** cpp

# Longest Subsequence With Non-Zero Bitwise XOR

### Approach Summary
The core insight behind this problem is that if the XOR sum of all elements in the array is already non-zero, the longest possible subsequence is the entire array itself. If the total XOR sum is zero, we can achieve a non-zero XOR sum by removing exactly one element, provided that the array contains at least one non-zero number. By removing a single element that is not zero, the parity of the XOR sum changes, making it non-zero. If the array only contains zeros, it is impossible to form a non-zero XOR sum, so we return 0.

### Step-by-Step Explanation

1. **Calculate the Total XOR:** We traverse the entire array once, calculating the XOR sum of every element (`xr`). Simultaneously, we keep track of whether we have encountered any non-zero numbers using a boolean flag (`nonZero`).
2. **Case 1: Total XOR is non-zero:** If the XOR sum of all elements in `nums` is already non-zero, we don't need to remove anything. The entire array is our longest subsequence, so we return its length, `n`.
3. **Case 2: Total XOR is zero:** If the total XOR is zero, we look at our `nonZero` flag. If there is at least one non-zero number in the array, we can remove it from the set. Removing a non-zero number from a set that XORs to zero will result in a remaining XOR sum that is non-zero. Thus, the longest subsequence length becomes `n - 1`.
4. **Case 3: All elements are zero:** If the total XOR is zero and our `nonZero` flag is false, it means every element in the array is 0. Since the XOR sum of any number of zeros is always 0, it is impossible to form a non-zero XOR sum. In this case, we return 0.

### Complexity Analysis

*   **Time Complexity:** O(n), where *n* is the number of elements in `nums`. We iterate through the array exactly once to calculate the total XOR sum and check for non-zero values.
*   **Space Complexity:** O(1). We only use a few integer and boolean variables (`xr`, `nonZero`, `n`, `j`) to store the state, regardless of the size of the input array.
