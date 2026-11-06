# Find the Distance Value Between Two Arrays

**Difficulty:** Easy | **Language:** C++

# Find the Distance Value Between Two Arrays

### Approach
The problem asks us to count elements in `arr1` that are "far enough" from every element in `arr2`. Specifically, an element `x` from `arr1` is valid if no element in `arr2` falls within the range `[x - d, x + d]`. Instead of using a nested loop that compares every pair (which would be slow), we first sort both arrays. Sorting allows us to use a two-pointer approach: as we iterate through the sorted `arr1`, we maintain a pointer in `arr2` to skip elements that are too small. By checking only the closest potential neighbors in the sorted `arr2`, we can efficiently determine if any element violates the distance condition.

### Step-by-Step Explanation

1. **Sorting**: We begin by sorting both arrays in ascending order. Sorting is the key to efficiency here; it allows us to discard elements in `arr2` that are definitively too small to satisfy the distance condition as we move through `arr1`.
2. **The Pointer `j`**: We maintain a pointer `j` that tracks our position in `arr2`. Since `arr1` is sorted, as we move to larger values of `x` in `arr1`, the range of "forbidden" values in `arr2` also moves to the right. This means we never need to reset `j` to the beginning of `arr2`.
3. **Skipping invalid elements**: For each element `x` in `arr1`, we want to find if there is any `arr2[j]` such that `|x - arr2[j]| <= d`. This is equivalent to checking if `arr2[j]` is in the interval `[x - d, x + d]`. We use a `while` loop to advance `j` until `arr2[j]` is at least `x - d`. 
4. **Validating the condition**: After the `while` loop, if `j` points to a valid index, we check if `arr2[j] > x + d`. 
    * If this is true, it means all elements in `arr2` (up to the current `j`) are smaller than `x - d`, and the current `arr2[j]` is already larger than `x + d`. Therefore, no element in `arr2` exists in the "danger zone" `[x - d, x + d]`. 
    * If `j` reached the end of the array, it means no elements in `arr2` were large enough to fall within the danger zone, which also satisfies our condition.
5. **Counting**: If the condition is met, we increment our answer counter.

### Complexity Analysis

* **Time Complexity**: **O(N log N + M log M)**, where $N$ is the length of `arr1` and $M$ is the length of `arr2`. The dominant factor is the sorting of both arrays. The subsequent pass through the arrays with two pointers takes only $O(N + M)$ time.
* **Space Complexity**: **O(1)** or **O(log N + log M)** depending on the implementation of the sort algorithm. We are sorting in-place and only using a constant amount of extra space for our pointers and counters.
