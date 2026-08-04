# Find Missing Elements

**Difficulty:** Easy | **Language:** python

# Solution: Find Missing Elements

### Approach
The algorithm identifies the full range of integers by determining the minimum and maximum values present in the input array. Once the boundaries of the range are established, the program iterates through every integer starting from the minimum to the maximum. During each iteration, it checks whether the current integer exists in the input array; if it is absent, that integer is added to a collection of missing numbers. Finally, the list is sorted and returned.

### Step-by-step Explanation

1.  **Identify the Boundaries**: We first determine the `min` and `max` values of the provided `nums` array. These values represent the starting and ending points of the original, complete sequence.
2.  **Iterate Through the Range**: We use a loop to count every integer between the smallest and largest values (inclusive). 
3.  **Check for Existence**: For every number in this calculated range, we perform a membership check against the input list. If a number is not found within `nums`, we know it is a "missing" element.
4.  **Collect and Organize**: We store all identified missing numbers in an `ans` list. Since the loop processes numbers in increasing order, the result will inherently be sorted; however, we call `.sort()` as a safeguard to ensure the output meets the return requirements.

### Complexity Analysis

*   **Time Complexity**: O(N * M), where N is the length of the input array and M is the difference between the maximum and minimum values. This is because, for every number in the range (M), we perform a search in the array (N). Given the small constraints (up to 100), this approach is highly efficient.
*   **Space Complexity**: O(M), where M is the number of missing integers. In the worst-case scenario (where almost every number is missing), we store nearly the entire range in our results list.
