# Minimum Add to Make Parentheses Valid

**Difficulty:** Medium | **Language:** C++

# Minimum Add to Make Parentheses Valid

### Approach Summary
The problem is solved using a greedy approach by tracking the balance of parentheses as we traverse the string. We maintain two counters: one to track "open" parentheses that are currently waiting for a matching closing parenthesis, and another to track "ans" (the number of moves required), which accounts for unmatched closing parentheses that appear without a preceding open pair. By the end of the iteration, any remaining open parentheses that never found a partner must also be accounted for, leading to a final result that combines the unmatched closing and unmatched opening parentheses.

### Step-by-step Explanation

1.  **Initialize Tracking Variables**: We use `open` to represent the number of active '(' characters that haven't been closed yet, and `ans` to represent the number of parentheses we are forced to add to fix the string.
2.  **Iterate through the string**: We examine each character one by one:
    *   **If we see an opening parenthesis '('**: This adds to our pool of potential matches. We increment `open`.
    *   **If we see a closing parenthesis ')'**: We need to see if there is an available '(' to pair it with. 
        *   If `open > 0`, it means we have a preceding '(' waiting. We decrement `open` to "use up" that match.
        *   If `open == 0`, we have a closing parenthesis with no matching opening one. This is invalid, so we must add a move to fix it; thus, we increment `ans`.
3.  **Final Calculation**: After looping through the entire string, the `ans` variable holds the total number of closing parentheses that were invalid. However, we might still have leftover `open` parentheses that never found a closing pair (e.g., in the string `"((("`). To balance the string, we would need to add exactly that many closing parentheses. Therefore, we return `ans + open` as the final count of minimum moves.

### Complexity Analysis

*   **Time Complexity**: O(n), where *n* is the length of the string. We perform a single pass through the input string, performing constant-time operations for each character.
*   **Space Complexity**: O(1). We only use two integer variables (`open` and `ans`) regardless of the size of the input, meaning the memory usage remains constant.
