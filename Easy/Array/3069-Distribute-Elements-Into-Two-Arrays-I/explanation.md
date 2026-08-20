# Distribute Elements Into Two Arrays I

**Difficulty:** Easy | **Language:** cpp

# Solution Explanation: Distribute Elements Into Two Arrays I

### Approach Summary
The problem asks us to distribute numbers into two separate arrays based on a comparison rule involving their last elements. We initialize two arrays, `vec1` and `vec2`, with the first two elements of the input array. For all remaining elements, we compare the last added element of `vec1` with the last added element of `vec2`. If the element in `vec1` is larger, we append the current number to `vec1`; otherwise, we append it to `vec2`. Finally, we concatenate `vec2` to the end of `vec1` to form the resulting array.

### Step-by-step Explanation

1.  **Initialization**: We start by creating two empty vectors, `vec1` and `vec2`. Since the rules specifically require the first two operations to place the first two numbers into their respective arrays, we immediately `push_back` the first element of `nums` into `vec1` and the second element into `vec2`.
2.  **Iterative Distribution**: We loop through the input array starting from the third element (index 2). This covers all remaining operations from the 3rd operation up to the *n*-th operation.
3.  **The Comparison Logic**: Inside our loop, we use `.back()` to check the most recently added value in both vectors. 
    *   If `vec1.back() > vec2.back()`, the current number from `nums` is added to `vec1`. 
    *   If `vec1.back() <= vec2.back()`, it is added to `vec2`.
    *   This logic perfectly mimics the "greater than" rule specified in the problem description.
4.  **Final Concatenation**: After the loop finishes, all numbers have been sorted into their correct arrays. We create a new vector `ans` initialized with all elements from `vec1`. Then, we append every element from `vec2` to the end of `ans` and return the result.

### Complexity Analysis

*   **Time Complexity**: **O(n)**
    *   We iterate through the `nums` array exactly once to distribute the elements. Concatenating the two vectors takes time proportional to the number of elements they contain, which is also linear relative to *n*.
*   **Space Complexity**: **O(n)**
    *   We use two additional vectors (`vec1` and `vec2`) to store the distributed elements. The total number of elements stored across these two vectors is exactly *n*, leading to linear space usage.
