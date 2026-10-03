# Generate Parentheses

**Difficulty:** Medium | **Language:** C++

# Generate Parentheses: Solution Explanation

### Approach Summary
The problem is solved using a **Backtracking (Depth-First Search)** approach. We build the parentheses string character by character, keeping track of how many opening and closing parentheses we have left to place. By enforcing specific rules at each step—we can only add an opening parenthesis if we have some remaining, and we can only add a closing parenthesis if there are more open ones currently in the string than closed ones—we ensure that every generated combination is "well-formed" by construction, avoiding the need to validate the strings at the end.

### Step-by-Step Explanation

1.  **Tracking State:** The algorithm uses two variables, `l` (left) and `r` (right), representing the number of open and closing parentheses we still need to add. We initialize both to `n`.
2.  **Base Case:** If both `l` and `r` reach zero, it means we have successfully placed all $n$ pairs. We add the completed string `path` to our result list `ans` and stop exploring that path.
3.  **Adding Opening Parentheses:** We can add an opening parenthesis `(` as long as `l > 0`. After adding it, we recursively call the function, decrementing `l` to signify one less opening parenthesis is available. Once the recursion returns, we "backtrack" by removing the character we just added (`pop_back`) to reset the state for the next possible branch.
4.  **Adding Closing Parentheses:** This is the key to well-formed strings. We can only add a closing parenthesis `)` if `l < r`. This condition ensures that we never place a closing bracket before its corresponding opening bracket. Just like before, we recurse after adding the character and backtrack once the recursion finishes.
5.  **Efficiency:** Because we check the validity rules before placing a character, the algorithm never explores invalid branches, making the generation process very efficient.

### Complexity Analysis

*   **Time Complexity:** $O(\frac{4^n}{\sqrt{n}})$. The number of well-formed parentheses combinations is defined by the $n$-th Catalan number, which grows at this rate. Since we generate each valid combination once, the complexity is proportional to the total number of valid outputs.
*   **Space Complexity:** $O(n)$. This is determined by the maximum depth of the recursion stack, which is $2n$ (since we add $n$ open and $n$ close brackets). We also store the current path string, which has a maximum length of $2n$.
