# Largest Rectangle in Histogram

**Difficulty:** Hard | **Language:** cpp

# Largest Rectangle in Histogram: Explanation

### Approach Summary
The algorithm uses the concept of "Next Smaller Element" to determine the boundaries of the largest rectangle that can be formed using each bar as the height. For any given bar of height $H$, the maximum rectangle with that height extends to the left and right until it hits a bar shorter than $H$. By pre-calculating these boundaries for every index using a monotonic stack, we can compute the width of the rectangle for each bar in constant time and find the maximum overall area.

### Step-by-step Explanation

1.  **Understanding the Goal**: For every bar at index `i`, we want to find the largest rectangle that uses `heights[i]` as its height. To do this, we need to know the index of the first bar to the left that is shorter than `heights[i]` and the first bar to the right that is shorter. Everything in between these two boundaries can be part of the rectangle.
2.  **Finding Right Boundaries**: We iterate from right to left using a stack to keep track of the indices of bars in increasing order of height. When we encounter a bar shorter than the bar at the top of the stack, it means we’ve found the "right boundary" for the bars currently in the stack. We pop them and store the current index as their boundary.
3.  **Finding Left Boundaries**: We repeat a similar process, but iterating from left to right. This time, we look for the first bar to the left that is shorter than our current bar. If the stack is empty, it means the current bar is the shortest one seen so far, extending all the way to the beginning (index -1).
4.  **Calculating the Area**: Once we have the `left` boundary index and `right` boundary index for every bar `i`, the width of the rectangle is calculated as `(right[i] - left[i] - 1)`. We multiply this by `heights[i]` to get the area. We track the maximum value found across all indices to return the final answer.

### Complexity Analysis

*   **Time Complexity**: $O(n)$, where $n$ is the number of bars. Even though there are nested `while` loops, each index is pushed onto the stack exactly once and popped at most once during the boundary calculations, ensuring linear time processing.
*   **Space Complexity**: $O(n)$. We use two arrays of size $n$ to store the left and right boundaries, and a stack that can hold up to $n$ elements in the worst case (e.g., when the heights are in strictly increasing or decreasing order).
