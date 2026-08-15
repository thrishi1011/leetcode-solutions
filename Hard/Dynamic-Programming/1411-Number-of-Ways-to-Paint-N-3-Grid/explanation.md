# Number of Ways to Paint N × 3 Grid

**Difficulty:** Hard | **Language:** cpp

# Number of Ways to Paint N × 3 Grid

### Approach Summary
The problem is solved using dynamic programming by analyzing the possible color patterns for a single row of three cells. There are two types of patterns: those where the first and third cells have the same color (e.g., ABA) and those where they have different colors (e.g., ABC). By calculating how these two pattern types transition from one row to the next, we can derive a recurrence relation to compute the total number of ways for $n$ rows without needing to simulate every individual cell.

### Step-by-step Explanation

1.  **Identify Row Patterns**: 
    A row of 3 cells using 3 colors can be painted in two distinct ways:
    *   **Same Pattern (ABA)**: The first and third cells share the same color. There are 6 such patterns (e.g., RYR, RGR, YRY, YGY, GRG, GYG).
    *   **Different Pattern (ABC)**: The first and third cells have different colors. There are also 6 such patterns (e.g., RYG, RGY, YRG, YGR, GRY, GYR).
    *   Total ways for $n=1$ is $6 + 6 = 12$.

2.  **Determine Transitions**: 
    When moving from row $i$ to row $i+1$, we must ensure no vertical adjacencies match.
    *   If the previous row was a **"Same"** pattern, we can form:
        *   3 "Same" patterns in the new row.
        *   2 "Different" patterns in the new row.
    *   If the previous row was a **"Different"** pattern, we can form:
        *   2 "Same" patterns in the new row.
        *   2 "Different" patterns in the new row.

3.  **Dynamic Programming Logic**: 
    We maintain two variables, `same` and `diff`, representing the number of valid ways to paint the grid up to the current row ending in each respective pattern type.
    *   `newSame = (same * 3) + (diff * 2)`
    *   `newDiff = (same * 2) + (diff * 2)`
    *   We apply the modulo operator at each addition to prevent integer overflow, as the number of ways grows exponentially.

4.  **Iteration**: 
    We loop from the 2nd row up to $n$. After the loop completes, the final answer is simply the sum of the ways to end with either pattern type (`same + diff`), modulo $10^9 + 7$.

### Complexity Analysis

*   **Time Complexity**: $O(n)$, where $n$ is the number of rows. We perform a single loop that runs from 2 to $n$, performing constant-time arithmetic operations in each iteration.
*   **Space Complexity**: $O(1)$. We only store a constant number of variables (`same`, `diff`, `newSame`, `newDiff`) to track the state, regardless of the input size $n$.
