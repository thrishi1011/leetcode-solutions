# Maximum Product of Three Numbers

**Difficulty:** Easy | **Language:** cpp

# Maximum Product of Three Numbers

### Summary of Approach
To find the maximum product of three numbers in an array, we must account for both positive and negative values. While multiplying the three largest numbers is the most obvious path, the presence of large negative numbers (which become positive when multiplied together) creates an alternative possibility: multiplying the two smallest negative numbers by the single largest positive number. The algorithm sorts the array to easily identify these candidates, then compares these two specific scenarios to return the larger result.

### Step-by-step Explanation
1.  **Sorting the Array:** We start by sorting the input array in ascending order. This organizes the numbers so that the smallest values (including large negatives) are at the beginning and the largest values are at the end.
2.  **Identifying Candidate 1 (All Positives):** If the array contains mostly positive numbers, the maximum product is simply the product of the three largest numbers in the array. Since the array is sorted, these are located at the last three indices: `nums[n-3]`, `nums[n-2]`, and `nums[n-1]`.
3.  **Identifying Candidate 2 (Negative Pair + Largest Positive):** If the array contains significant negative numbers, multiplying two negative numbers results in a positive value. If we multiply the two most negative numbers (found at the beginning of the sorted array: `nums[0]` and `nums[1]`) by the largest positive number (at the end: `nums[n-1]`), we might get a product larger than the one produced by the three largest numbers.
4.  **Selecting the Maximum:** Finally, the code compares these two candidates using the `max()` function and returns the higher value. This ensures that whether the array is entirely positive, entirely negative, or a mix, the mathematically largest possible product is identified.

### Complexity Analysis
*   **Time Complexity:** O(N log N), where N is the number of elements in the array. This is due to the sorting step, which dominates the performance of the algorithm.
*   **Space Complexity:** O(1) or O(log N). Depending on the implementation of the sorting algorithm, it uses a constant amount of extra space (if sorting in-place) or a small amount of stack space for recursion, keeping memory usage minimal.
