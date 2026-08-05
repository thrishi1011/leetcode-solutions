# Find the Prefix Common Array of Two Arrays

**Difficulty:** Medium | **Language:** C++

# Find the Prefix Common Array of Two Arrays

### Approach
The problem asks us to track how many numbers have appeared in both arrays up to a specific index `i`. Since the input consists of permutations of numbers from 1 to `n`, we can efficiently track which numbers have been seen so far using a boolean array or a bitset. As we iterate through both arrays simultaneously, we check if the current element has already been marked as "seen." If a number appears and we have already seen it previously (or if it is the second time it appears in the current iteration), it confirms that this number is common to both prefixes. By maintaining a running total of these occurrences, we can construct the result array in a single pass.

### Step-by-step Explanation

1.  **Tracking State:** We use a `bitset` (which acts like a boolean array) called `seen` to keep track of every number encountered in either array `A` or `B`. Because the problem constraints state that `n` is at most 50, a bitset of size 51 is sufficient to store flags for all possible values.
2.  **The Iteration Loop:** We loop through the arrays from index `0` to `n-1`. At each step `i`, we examine the elements `A[i]` and `B[i]`.
3.  **Detecting Commonality:**
    *   When we look at `A[i]`, we check if it was already marked in the `seen` bitset. If it was, that means the number appeared earlier in `B` (or previously in `A`), so we increment our `count`. After checking, we mark `A[i]` as seen.
    *   We do the exact same check for `B[i]`. If it was already marked (which could mean it appeared earlier in `A` or earlier in `B`), we increment the `count`.
    *   *Edge Case Note:* If `A[i]` and `B[i]` are the same number, the logic naturally handles this: the first check (`A[i]`) will not increment the count because it hasn't been seen yet, but it will mark it as seen; the second check (`B[i]`) will then see it is already marked and increment the count correctly.
4.  **Recording the Result:** After processing both `A[i]` and `B[i]`, the variable `count` holds the total number of elements that have appeared in both prefixes up to index `i`. We store this value in our result array at index `i`.

### Complexity Analysis

*   **Time Complexity:** O(n), where `n` is the length of the arrays. We traverse the arrays exactly once, and inside the loop, all operations (bitset lookups and updates) are performed in constant time, O(1).
*   **Space Complexity:** O(n). We use a bitset of fixed size (51) to track seen numbers, which is effectively O(1) space, but we also allocate an output array of size `n` to store the results. Thus, the overall auxiliary space requirement scales linearly with the size of the input.
