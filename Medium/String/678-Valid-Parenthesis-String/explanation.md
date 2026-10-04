# Valid Parenthesis String

**Difficulty:** Medium | **Language:** cpp

# Valid Parenthesis String: Solution Explanation

### Approach Summary
The solution uses a greedy strategy to track the possible range of "open" parentheses at any given point in the string. Instead of trying to guess what each `*` represents, we maintain two counters: `left`, which represents the minimum number of open parentheses we *must* close, and `right`, which represents the maximum number of open parentheses we *could* have. By treating `*` as an empty string, a left parenthesis, or a right parenthesis dynamically, we ensure that as long as our `right` count never drops below zero and our `left` count successfully reaches zero by the end, the string is valid.

### Step-by-Step Explanation

1.  **Tracking the Range**: We use two variables, `left` and `right`. 
    *   `left` tracks the minimum possible number of open parentheses. If we encounter a `)`, we decrement it. If it goes below zero, we reset it to zero because we cannot have a negative number of open parentheses (we simply treat the extra `)` as having nothing to pair with).
    *   `right` tracks the maximum possible number of open parentheses. If we encounter a `)`, we decrement it.

2.  **Handling the Characters**:
    *   **If we see `(`**: Both the minimum (`left`) and maximum (`right`) possibilities increase, because we have definitely added an open parenthesis.
    *   **If we see `)`**: Both possibilities decrease, as one open parenthesis has been closed.
    *   **If we see `*`**: This character is versatile. It could be a `)` (decreasing our count), an empty string (keeping the count the same), or a `(` (increasing our count). Therefore, we decrease `left` (treating it as `)`) and increase `right` (treating it as `(`).

3.  **Validation during the loop**: After processing each character, we check `right < 0`. If `right` becomes negative, it means even if every `*` was turned into an opening parenthesis, we still have too many closing parentheses. This makes the string invalid, so we return `false` immediately.

4.  **Final Check**: After iterating through the entire string, `left` represents the minimum number of open parentheses that must be closed. If `left` is `0`, it means we have successfully balanced all necessary parentheses.

### Complexity Analysis

*   **Time Complexity**: **O(n)**, where *n* is the length of the string. We perform a single pass through the input string, performing only constant-time arithmetic operations for each character.
*   **Space Complexity**: **O(1)**. We only use two integer variables (`left` and `right`) regardless of the size of the input string, making the space usage constant.
