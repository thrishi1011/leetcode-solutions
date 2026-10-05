# Score of Parentheses

**Difficulty:** Medium | **Language:** C++

# Score of Parentheses

### Approach Summary
The algorithm uses a "depth-tracking" strategy to calculate the total score without needing a complex recursive structure or a stack. Since the score of any base-level pair `()` is $2^{\text{depth}-1}$, we can iterate through the string and identify exactly where these base pairs occur. By keeping track of how many nested parentheses we are currently inside, we can add $2^{\text{depth}-1}$ to our running total whenever we encounter an immediate `()` pair.

### Step-by-step Explanation

1.  **Initialize State**: We start with `ans = 0` to store the final score and `depth = 0` to keep track of how many opening parentheses are currently "open" (i.e., how deeply nested we are).
2.  **Iterate Through the String**: As we loop through each character in the string:
    *   **When we see an opening parenthesis `(`**: This means we are going one level deeper into a nested structure, so we increment `depth`.
    *   **When we see a closing parenthesis `)`**: We have finished a level, so we decrement `depth`.
3.  **Identify Base Pairs**: The core logic happens when we find a closing parenthesis `)`. We check the character immediately preceding it (`s[i - 1]`):
    *   If the previous character was `(`, it means we have found a "base pair" `()`. 
    *   According to the rules, a `()` at a certain depth has a specific value. Because each nesting level multiplies the score by 2, a base pair at `depth` contributes $2^{\text{depth}}$ to the total. (For example, at depth 0, `()` is $2^0=1$; inside one pair, `(())`, the `()` is at depth 1, so it is $2^1=2$).
    *   We add this calculated value to our `ans`.
4.  **Final Result**: After the loop completes, `ans` contains the sum of all base pairs adjusted for their nesting levels, which matches the required score for the entire string.

### Complexity Analysis

*   **Time Complexity**: $O(n)$, where $n$ is the length of the string. We perform a single pass through the string, performing constant-time operations for each character.
*   **Space Complexity**: $O(1)$. We only use two integer variables (`ans` and `depth`) regardless of how large the input string is, making this an highly efficient space-optimized solution.
