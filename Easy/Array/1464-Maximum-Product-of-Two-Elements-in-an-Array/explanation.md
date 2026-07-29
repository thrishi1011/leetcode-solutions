# Maximum Product of Two Elements in an Array

**Difficulty:** Easy | **Language:** cpp

# Solution: Maximum Product of Two Elements in an Array

### Summary of Approach
The problem asks us to find two distinct elements in an array that yield the maximum result when both are decremented by one and then multiplied. Since the array size is small (up to 500 elements), we can use a brute-force approach. This involves iterating through every possible pair of elements using two nested loops, calculating the product for each pair, and keeping track of the highest value found throughout the process.

### Step-by-step Explanation
1. **Initialize the result**: We start by creating a variable called `ans` to store our maximum product. We initialize it to the smallest possible integer (`INT_MIN`) to ensure that any valid product we calculate later will be larger than our starting point.
2. **Outer Loop**: We use a loop that iterates from the first element of the array up to the second-to-last element. This loop acts as our "anchor," picking the first number in our pair.
3. **Inner Loop**: We use a second loop that starts from the index immediately after our current "anchor" position (`i + 1`) and goes until the end of the array. This ensures that we look at every possible combination without picking the same index twice and without checking the same pair in a different order.
4. **Calculate and Compare**: Inside the inner loop, we calculate `(nums[i] - 1) * (nums[j] - 1)`. We then compare this result to our current `ans` using the `max` function. If the new result is larger, we update `ans` to hold this new maximum.
5. **Final Output**: Once all possible pairs have been checked, the `ans` variable will contain the largest possible product, which we then return.

### Complexity Analysis

*   **Time Complexity**: O(n²)  
    We use two nested loops to compare every possible pair of elements. In an array of size *n*, this results in roughly $n^2 / 2$ operations, which simplifies to quadratic time complexity.
*   **Space Complexity**: O(1)  
    We only use a few integer variables (`i`, `j`, `n`, `ans`) regardless of the size of the input array. Therefore, the extra space used remains constant.
