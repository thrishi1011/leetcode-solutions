# Stone Game

**Difficulty:** Medium | **Language:** cpp

# Stone Game Solution Explanation

### Approach Summary
The problem is a classic game theory scenario that can be solved using Dynamic Programming (or specifically, minimax optimization). Since Alice and Bob play optimally, we want to determine if the "relative score" (Alice's total minus Bob's total) is greater than zero by the end of the game. Instead of tracking each player's score separately, we use a recursive function that calculates the maximum *net gain* a player can achieve from a given sub-segment of the piles. By using memoization to store previously computed results for specific pile ranges, we efficiently explore all optimal paths to determine if Alice (the first player) always has a winning strategy.

### Step-by-Step Explanation

1.  **Understanding the Goal:** Since the game is zero-sum (what Alice gains, Bob effectively loses relative to her), we can simplify the problem. If it is currently a player's turn with piles from index `i` to `j`, they want to maximize `(their points) - (opponent's points)`. 
2.  **The Recursive Choice:** When a player faces the array `piles[i...j]`, they have two choices:
    *   Pick the leftmost pile (`piles[i]`): They get `piles[i]` points, but then the *next* player will play optimally on the remaining piles `[i+1...j]`. The net gain for the current player is `piles[i] - (net gain of the next player)`.
    *   Pick the rightmost pile (`piles[j]`): Similarly, the net gain is `piles[j] - (net gain of the next player on [i...j-1])`.
3.  **Memoization:** Because different sequences of moves can lead to the same sub-array being left over, we use a 2D array `dp[i][j]` to store the result of the range `[i, j]`. If we encounter this range again, we return the stored result instead of recomputing it, which prevents the function from running in exponential time.
4.  **Base Case:** When `i == j`, only one pile remains. The current player must take it, so the net gain is simply the value of that pile.
5.  **Final Decision:** The `stoneGame` function initializes the DP table and calls the solver for the full range of the array. If the final result is greater than or equal to 0, it means Alice has achieved a score equal to or higher than Bob's, so we return `true`.

### Complexity Analysis

*   **Time Complexity:** $O(N^2)$, where $N$ is the number of piles. There are $N \times N$ possible states in our DP table, and each state takes $O(1)$ time to compute because it only performs a simple comparison of two pre-computed values.
*   **Space Complexity:** $O(N^2)$ to store the DP table. This is necessary to keep track of the results for all sub-segments of the array to ensure the algorithm remains efficient.
