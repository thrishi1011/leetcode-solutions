# Smallest Missing Integer Greater Than Sequential Prefix Sum

**Difficulty:** Easy | **Language:** C++

# Solution: Smallest Missing Integer Greater Than Sequential Prefix Sum

### Approach Summary
The algorithm finds the longest "sequential prefix"—a sub-array starting at the first element where each subsequent number is exactly one greater than the previous—and calculates its total sum. Once the sum is determined, the algorithm checks if that sum exists within the input array. If it is present, the algorithm increments the sum repeatedly until it finds the first value not contained in the original set of numbers, which is the smallest missing integer.

### Step-by-Step Explanation

1.  **Store the array for quick lookups:** We first insert all elements of the input array into an `unordered_set`. This allows us to check if a specific number exists in the array in constant time, rather than searching the entire list every time we need to verify a number.
2.  **Calculate the sum of the longest sequential prefix:** We start a variable `sum` with the value of the first element (`A[0]`). We then iterate through the array starting from the second element. For each index, we check if the current element is exactly one greater than the previous one. 
    *   If the condition holds, we add the current element to our `sum`.
    *   If the condition fails, the sequential pattern is broken, and we stop looking.
3.  **Find the smallest missing integer:** We now have the starting target `sum`. We use a `while` loop to check if this `sum` exists in our `seen` set. 
    *   If the `sum` is found in the set, it means the number is already present in the array, so we increment the `sum` by 1 and check again.
    *   As soon as we find a `sum` that is *not* in the set, we stop. This value is our answer, as it is the smallest possible integer greater than or equal to the prefix sum that is not present in the array.

### Complexity Analysis

*   **Time Complexity: $O(N)$**
    *   Building the `unordered_set` takes $O(N)$ time.
    *   Finding the sequential prefix sum takes $O(N)$ time as we traverse the array at most once.
    *   The `while` loop for finding the missing integer runs at most $O(N)$ times because the constraints on the input size and values are small (the sum will not exceed the range significantly). Overall, the complexity remains linear relative to the input size.

*   **Space Complexity: $O(N)$**
    *   We store all $N$ elements of the input array into an `unordered_set` to allow for $O(1)$ average time lookups.
