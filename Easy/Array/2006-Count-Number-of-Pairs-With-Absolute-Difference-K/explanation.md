# Count Number of Pairs With Absolute Difference K

**Difficulty:** Easy | **Language:** cpp

# Solution: Count Number of Pairs With Absolute Difference K

### Approach Summary
The problem asks us to find the total number of unique pairs `(i, j)` in an array where the absolute difference between the values at those indices equals `k`. Since the constraints are small (the array size is at most 200), we can use a **Brute Force** approach. We iterate through every possible pair in the array using two nested loops, calculate the absolute difference for each pair, and increment a counter whenever that difference matches `k`.

### Step-by-Step Explanation

1.  **Initialize a counter:** We create an integer variable `cnt` starting at 0 to keep track of how many valid pairs we find.
2.  **Outer Loop:** We use a loop that runs from the first element up to the second-to-last element (`i`). This represents the first index of our pair.
3.  **Inner Loop:** We use a second loop that starts one position ahead of the outer loop (`j = i + 1`) and runs to the end of the array. Starting at `i + 1` ensures that we only check pairs where `i < j`, which prevents us from counting the same pair twice (e.g., counting both index 0 and 1, and index 1 and 0) and avoids comparing an element with itself.
4.  **Check Condition:** Inside the inner loop, we calculate `abs(nums[i] - nums[j])`. The `abs()` function handles the absolute difference, ensuring the result is always positive regardless of which number is larger. 
5.  **Increment:** If the calculated difference is exactly equal to `k`, we increment our `cnt` variable by 1.
6.  **Return:** Once both loops have completed, we return the final value of `cnt`.

### Complexity Analysis

*   **Time Complexity:** $O(n^2)$, where $n$ is the length of the array. Because we are using nested loops to compare every pair of elements, the number of operations grows quadratically relative to the size of the input. Given the constraint of $n \le 200$, this approach is well within the acceptable limits.
*   **Space Complexity:** $O(1)$. We only use a constant amount of extra space for the integer counter (`cnt`) and the loop indices, regardless of how large the input array is.
