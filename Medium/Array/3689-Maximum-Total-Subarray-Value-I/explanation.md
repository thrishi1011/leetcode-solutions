# Maximum Total Subarray Value I

**Difficulty:** Medium | **Language:** cpp

# Maximum Total Subarray Value I - Solution Explanation

### Approach Summary
The problem asks us to choose $k$ subarrays to maximize the sum of their "values," where the value of a subarray is defined as its maximum element minus its minimum element. Since we are allowed to pick the same subarray multiple times and the subarrays can overlap, the optimal strategy is to identify the global maximum and global minimum of the entire array. By selecting the subarray that spans the entire range (from the index of the global minimum to the index of the global maximum, or vice versa), we capture the largest possible difference. Since we can reuse this specific subarray $k$ times, the maximum total value is simply $k$ multiplied by the difference between the array's overall maximum and minimum elements.

### Step-by-step Explanation

1.  **Finding the Global Extremes:** 
    We iterate through the entire array once to identify two critical values: the global maximum (`maxnum`) and the global minimum (`minnum`). No matter which subarray we choose, its value (`max - min`) can never exceed the difference between the largest and smallest numbers available in the entire array.

2.  **Exploiting the Rules:**
    The problem constraints allow us to pick the same subarray multiple times. This is the "key" to the problem. If we find the subarray that contains the global maximum and the global minimum, we have found the subarray with the largest possible value for this array. 

3.  **Maximizing the Total:**
    Because we are required to choose $k$ subarrays and we want to maximize the sum, logic dictates that we should pick that "best" subarray all $k$ times. 

4.  **Final Calculation:**
    The total value is calculated by taking the absolute difference between the `maxnum` and `minnum` and multiplying that result by $k$. Because $k$ and the array values can be large, we use `long long` to prevent potential integer overflow during the multiplication.

### Complexity Analysis

*   **Time Complexity:** $O(n)$, where $n$ is the length of the input array. We perform a single pass through the array to determine the global maximum and minimum values.
*   **Space Complexity:** $O(1)$. We only use a constant amount of extra space for the `minnum` and `maxnum` variables, regardless of the size of the input array.
