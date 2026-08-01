# Predict the Winner

**Difficulty:** Medium | **Language:** C++

# Predict the Winner: Solution Explanation

### Approach Summary
This problem is solved using **Dynamic Programming with Recursion and Memoization**. Since the players want to maximize their own scores, each player's move affects the future state of the game. Instead of tracking two separate scores, we calculate the "net score" (the difference between the current player's score and the opponent's score). By recursively choosing the move that results in the maximum net score, we can determine if Player 1's final net score is greater than or equal to zero, which indicates a win or a tie.

### Step-by-step Explanation

1.  **The Net Score Strategy**: Instead of keeping track of Player 1 and Player 2’s scores separately, we frame the problem as finding the maximum relative advantage. When a player picks a number, they add that number to their total and subtract the opponent's future potential gain from the remainder of the array. The formula `value = choice - solve(remaining array)` effectively calculates: *(My score this turn) - (The maximum lead the opponent can get from the rest of the game)*.

2.  **Base Case**: The recursion stops when only one number is left in the array (when `i == j`). At this point, the current player must take that remaining number, so we return `nums[i]`.

3.  **Recursive Choices**: At any state defined by the range `[i, j]`, the current player has two options:
    *   Pick `nums[i]` (the left end): The opponent will then play optimally starting from `i + 1` to `j`. The net score for the current player is `nums[i] - solve(i + 1, j)`.
    *   Pick `nums[j]` (the right end): The opponent will then play optimally starting from `i` to `j - 1`. The net score for the current player is `nums[j] - solve(i, j - 1)`.
    *   The player will choose the `max` of these two options to ensure they play optimally.

4.  **Memoization**: Since the same sub-problems (sub-arrays) are calculated repeatedly, we store the results in a 2D array `dp[21][21]`. Before performing a calculation, we check if the result for the current range `[i, j]` is already saved. If it is, we return that value immediately, which significantly improves performance.

5.  **Final Result**: The main function initiates the recursion for the entire array range `[0, n-1]`. If the resulting net score is $\ge 0$, it means Player 1's score is at least equal to Player 2's, so we return `true`.

### Complexity Analysis

*   **Time Complexity**: $O(N^2)$, where $N$ is the length of the array. There are $N^2$ possible states defined by the indices `i` and `j`, and each state is computed exactly once thanks to memoization.
*   **Space Complexity**: $O(N^2)$. This is the space required for the 2D memoization table to store the results of each state, plus the stack space for the recursion, which is $O(N)$ deep.
