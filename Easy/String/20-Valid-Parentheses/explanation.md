# Valid Parentheses

**Difficulty:** Easy | **Language:** cpp

# Valid Parentheses Solution Explanation

### Approach Summary
The problem is solved using a **stack** data structure (implemented here using a string) to track opening brackets. As we iterate through the input string, we push every opening bracket onto the stack. When we encounter a closing bracket, we check if it matches the most recently added opening bracket (the top of the stack). If it matches, we "pop" the opening bracket off; if it doesn't match or the stack is empty when we encounter a closing bracket, the string is invalid. By the end of the loop, the string is only valid if the stack is completely empty, ensuring all brackets were properly closed.

### Step-by-Step Explanation

1.  **Initialize a tracker:** We use a string variable named `temp` to act as our stack. It will keep track of all the opening brackets we have encountered but haven't yet closed.
2.  **Iterate through the string:** We examine each character in the input string `s` one by one.
3.  **Handle opening brackets:** If the current character is an opening bracket (`(`, `{`, or `[`), we add it to the end of our `temp` string. This signifies that we are waiting for a matching closing bracket for this specific symbol.
4.  **Handle closing brackets:** If we encounter a closing bracket, we perform two checks:
    *   **Is there a waiting bracket?** If `temp` is empty, it means we have a closing bracket with no preceding opening bracket, so we immediately return `false`.
    *   **Does it match?** We look at the most recent bracket added to `temp` (found at `temp.length() - 1`). If the current closing bracket corresponds to that last opening bracket, we remove the opening bracket from `temp` using `pop_back()`. If it does not match (e.g., we have `]` but the last open was `(`), the string is invalid, and we return `false`.
5.  **Final Validation:** After checking every character, we check if `temp` is empty. If it is empty, it means all brackets were correctly matched and closed in the right order. If `temp` is not empty, it means some opening brackets were left without a pair, so we return `false`.

### Complexity Analysis

*   **Time Complexity: O(n)**
    We iterate through the input string exactly once. Each insertion and removal operation from the end of the string (the stack) takes constant time, resulting in a linear time complexity where *n* is the length of the string.
*   **Space Complexity: O(n)**
    In the worst-case scenario (e.g., a string of all opening brackets like `((((`), we will store every character in the `temp` string. Therefore, the space required scales linearly with the input size.
