# Rectangle Overlap

**Difficulty:** Easy | **Language:** C++

# Solution: Rectangle Overlap

### Approach
The most efficient way to solve this problem is to identify the conditions under which two rectangles **do not** overlap and then negate that logic. Instead of trying to calculate the area of intersection, we check if one rectangle is entirely to the left, right, above, or below the other. If none of these "non-overlapping" conditions are true, then the rectangles must be overlapping. By using De Morgan's Law, we can invert these conditions to directly find when they *do* overlap, leading to a simple set of comparison operations.

### Step-by-Step Explanation
To determine if two rectangles overlap, we look at their horizontal (X-axis) and vertical (Y-axis) projections. 

1. **Horizontal Overlap:** For two rectangles to overlap horizontally, the left edge of the first rectangle must be to the left of the right edge of the second, AND the left edge of the second must be to the left of the right edge of the first. If this is not true, they are separated horizontally.
2. **Vertical Overlap:** Similarly, for a vertical overlap, the bottom edge of the first must be below the top edge of the second, AND the bottom edge of the second must be below the top edge of the first.
3. **The Logical Condition:** If both the horizontal and vertical conditions are met simultaneously, the rectangles occupy a shared space. 
   - `rec1[0] < rec2[2]` ensures `rec1` starts before `rec2` ends.
   - `rec2[0] < rec1[2]` ensures `rec2` starts before `rec1` ends.
   - `rec1[1] < rec2[3]` ensures `rec1` bottom is below `rec2` top.
   - `rec2[1] < rec1[3]` ensures `rec2` bottom is below `rec1` top.

If all four of these conditions are true, it is impossible for the rectangles to be separated, meaning they must overlap.

### Complexity Analysis

*   **Time Complexity:** O(1). We perform a constant number of comparisons (four inequalities) regardless of the input values.
*   **Space Complexity:** O(1). We do not use any extra data structures or memory proportional to the input; we only store the result of the boolean expression.
