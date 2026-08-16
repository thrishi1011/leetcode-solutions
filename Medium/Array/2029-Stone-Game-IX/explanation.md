# Stone Game IX

**Difficulty:** Medium | **Language:** C++

# Stone Game IX Explanation

### Approach Summary
The key to solving this problem lies in the observation that the exact values of the stones do not matter, only their remainders when divided by 3. We categorize the stones into three buckets based on `value % 3` (0, 1, and 2). Stones divisible by 3 are "neutral" because they don't change the sum's divisibility by 3, but they do allow the current player to force a change in the turn order. The game's outcome is then determined by comparing the counts of stones with remainder 1 and remainder 2, while accounting for whether there is an even or odd number of "neutral" stones (remainder 0) available to swap turns.

### Step-by-Step Explanation

1.  **Categorization:** We iterate through the input array and count how many stones fall into three categories:
    *   `x`: Remainder 0 (divisible by 3).
    *   `y`: Remainder 1.
    *   `z`: Remainder 2.

2.  **Handling Remainder 0 (The "Swap" Stones):**
    *   These stones are unique because adding one to the sum does not change the sum's modular status. However, they effectively "pass" the turn to the other player.
    *   If `x` is **even**, these stones don't change the parity of the game. Alice can essentially ignore them. In this scenario, Alice wins if there is at least one stone of remainder 1 and one stone of remainder 2 available to keep the game going without hitting a sum divisible by 3.
    *   If `x` is **odd**, the player who takes the last "0" stone essentially changes who is forced to take the next "risky" stone (remainder 1 or 2).

3.  **Analyzing the "Risky" Stones (Remainders 1 and 2):**
    *   If we have no remainder 0 stones, the game is purely a race between the 1s and 2s. If you take a 1, the next person wants to take a 2 to avoid hitting a sum divisible by 3. 
    *   If `x` is **even**, Alice can win only if she has both 1s and 2s to play with (`y > 0 && z > 0`).
    *   If `x` is **odd**, Bob is at a disadvantage if the difference between the count of 1s and 2s is large enough (`abs(y - z) > 2`). This is because the imbalance forces the players into a sequence where one is eventually forced to pick a stone that makes the total sum divisible by 3.

### Complexity Analysis

*   **Time Complexity:** $O(N)$, where $N$ is the number of stones. We traverse the input array exactly once to count the remainders, and all subsequent logic uses simple arithmetic comparisons.
*   **Space Complexity:** $O(1)$. We only store three integer counters (`x`, `y`, and `z`) regardless of the size of the input array.
