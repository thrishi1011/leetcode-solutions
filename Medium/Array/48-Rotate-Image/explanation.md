# Rotate Image

**Difficulty:** Medium | **Language:** cpp

# Solution: Rotate Image

### Approach Summary
To rotate an $n \times n$ matrix 90 degrees clockwise in-place, we can decompose the rotation into two fundamental matrix operations: a transpose followed by a horizontal reflection. Transposing the matrix involves swapping elements across the main diagonal (where $row$ and $column$ indices are equal), which turns rows into columns. Once transposed, reversing each individual row effectively mirrors the matrix horizontally, resulting in a perfect 90-degree clockwise rotation. This method avoids the need for extra memory allocation by performing all swaps and reversals directly within the original matrix.

### Step-by-step Explanation

1.  **Transpose the Matrix:** 
    The first step is to transform rows into columns. We iterate through the matrix using two nested loops. The outer loop tracks the current row (`i`), and the inner loop starts at `i + 1` (`j`). By swapping `matrix[i][j]` with `matrix[j][i]`, we flip the matrix over its top-left-to-bottom-right diagonal. We start the inner loop at `i + 1` to ensure we only swap elements above the diagonal with those below it; if we started at 0, we would swap everything twice, effectively returning the matrix to its original state.

2.  **Reverse the Rows:**
    After transposing, the matrix is "tilted." To achieve the final 90-degree clockwise rotation, we need to reorder the elements within each row. By reversing each row individually (flipping the left side to the right side), the elements land in their correct rotated positions. The built-in `reverse` function handles this efficiently for every row in the matrix.

### Complexity Analysis

*   **Time Complexity:** $O(n^2)$, where $n$ is the side length of the matrix. We visit each element exactly once during the transpose phase and once during the reverse phase. Since the total number of elements is $n^2$, the time complexity is proportional to the size of the matrix.
*   **Space Complexity:** $O(1)$. We perform the rotation in-place by swapping existing elements within the original matrix. No additional data structures (like a second matrix) are created, regardless of the input size.
