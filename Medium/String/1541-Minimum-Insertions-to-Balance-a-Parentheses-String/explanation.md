# Minimum Insertions to Balance a Parentheses String

**Difficulty:** Medium | **Language:** C++

# Minimum Insertions to Balance a Parentheses String

### Approach Summary
The problem requires balancing parentheses where every opening bracket `(` must be matched by two consecutive closing brackets `))`. To solve this, we track the number of required closing brackets using a counter `p` and the number of necessary insertions using a counter `k`. As we traverse the string, we treat `(` as adding two required closing brackets to our "debt" and `)` as reducing that debt. If we encounter a `)` when no debt exists, or an odd number of closing brackets when an opening one arrives, we perform an immediate insertion to maintain the balancing rules, ultimately returning the total count of required additions.

### Step-by-step Explanation

1.  **Tracking State:** We use two variables: `p` to represent the number of right parentheses needed to balance the current opening brackets, and `k` to track the total number of characters we have manually inserted.
2.  **Processing an Opening Bracket `(`:** 
    *   An opening bracket requires two closing brackets, so we increment `p` by 2.
    *   **The Odd Constraint:** Because we need pairs of `))`, `p` should ideally be even. If `p` becomes odd after adding 2, it means we were in the middle of a pair of closing brackets when a new opening bracket appeared. To fix this, we increment our insertion count `k` (adding one `)`) and decrement `p` to make it even.
3.  **Processing a Closing Bracket `)`:**
    *   When we see a `)`, we decrease the required count `p` by 1.
    *   **Handling Excess `)`:** If `p` drops below 0, it means we encountered a closing bracket without a preceding opening bracket. We must insert an opening bracket to balance this, which adds 2 to our future `p` requirement (net +1 after accounting for this `)`) and increments our insertion count `k` by 1.
4.  **Final Calculation:** After iterating through the string, `p` represents any remaining closing brackets that were never provided for our opening brackets. We add this remaining `p` to our total insertions `k` to ensure all open brackets are properly closed.

### Complexity Analysis

*   **Time Complexity: O(n)**
    We perform a single pass through the string of length `n`, performing constant-time arithmetic operations at each step.
*   **Space Complexity: O(1)**
    We only use a few integer variables (`p`, `k`, `n`, `i`) regardless of the size of the input string, resulting in constant auxiliary space usage.
