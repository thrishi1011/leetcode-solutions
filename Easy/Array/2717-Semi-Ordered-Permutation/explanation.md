# Semi-Ordered Permutation

**Difficulty:** Easy | **Language:** cpp

# Solution: Semi-Ordered Permutation

### Approach Summary
To make a permutation "semi-ordered," we need to move the number `1` to the very beginning (index `0`) and the number `n` to the very end (index `n-1`). Since we are only allowed to swap adjacent elements, the number of operations required to move an element from its current position to a target position is simply the absolute difference between the indices. We calculate the moves needed to bring `1` to the start and `n` to the end, then subtract one operation if the paths of these two numbers "cross" (i.e., if `1` starts to the right of `n`), as a single swap can potentially move both elements closer to their destinations simultaneously.

### Step-by-step Explanation

1.  **Locate the targets**: First, we identify the current index of `1` and the index of `n` in the array. Since the array is a permutation containing all numbers from `1` to `n`, these two values are guaranteed to exist.
2.  **Calculate moves for `1`**: The number of swaps needed to move `1` from its current index to the first position (index `0`) is exactly equal to its current index. For example, if `1` is at index `3`, it takes 3 swaps to bring it to index `0`.
3.  **Calculate moves for `n`**: To move `n` to the last position (index `n-1`), we look at how many steps it is away from the end. This is calculated as `(array length - 1) - current index of n`.
4.  **Account for the "cross-over"**: A special case arises if the original index of `1` is greater than the original index of `n`. In this scenario, moving `1` toward the left will eventually involve swapping it with `n`. This single swap helps `1` get closer to the start *and* helps `n` get closer to the end. Because this single action counts for both goals, we reduce the total swap count by 1 to avoid double-counting that specific move.

### Complexity Analysis

*   **Time Complexity**: O(n), where *n* is the length of the input array. We perform two linear searches using `std::find` to locate the positions of `1` and `n`, both of which take O(n) time. The subsequent arithmetic operations are performed in constant time.
*   **Space Complexity**: O(1). We only use a few integer variables to store the indices and the final result, regardless of the size of the input array.
