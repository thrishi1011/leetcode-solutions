# Remove Outermost Parentheses

**Difficulty:** Easy | **Language:** C++

# Remove Outermost Parentheses

### Approach Summary
The algorithm uses a counter-based tracking strategy to identify and strip the outermost parentheses of each primitive component. By maintaining a balance counter (`count`) that tracks the nesting depth of the parentheses, we can distinguish between "inner" characters and "outer" boundary characters. When we encounter an opening parenthesis that increases the depth beyond zero, or a closing parenthesis that keeps the depth above zero, we know those characters are part of the inner content and should be included in the result.

### Step-by-step Explanation

1.  **Tracking Depth:** We initialize a variable `count` to 0. This variable keeps track of the current nesting level. Every time we encounter an opening parenthesis `(`, the level increases; every time we encounter a closing parenthesis `)`, the level decreases.
2.  **Processing Opening Parentheses `(`:** 
    *   If we see an opening parenthesis, we check if `count > 0`. If it is, it means this `(` is *not* the outermost one of a primitive block (it is nested inside), so we append it to our answer. 
    *   After the check, we increment `count` to signify we have gone one level deeper.
3.  **Processing Closing Parentheses `)`:**
    *   First, we decrement `count` because a closing parenthesis completes a pair. 
    *   After decrementing, we check if `count > 0`. If it is, it means this `)` is *not* the outermost boundary of a primitive block (because it hasn't closed the entire primitive string yet), so we append it to our answer.
4.  **Result:** By strictly following these rules, the outermost `(` (which occurs when `count` is 0) and the outermost `)` (which occurs when `count` hits 0 after the decrement) are effectively ignored, leaving only the inner components.

### Complexity Analysis

*   **Time Complexity: O(n)**
    We perform a single pass through the input string of length *n*, where each character is processed in constant time O(1).
*   **Space Complexity: O(n)**
    In the worst case, we store almost all characters of the original string in the `ans` result string (excluding the two outer parentheses per primitive block). Therefore, the space required is proportional to the size of the input.
