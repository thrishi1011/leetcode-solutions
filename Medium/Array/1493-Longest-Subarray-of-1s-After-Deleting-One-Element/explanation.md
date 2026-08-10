# Longest Subarray of 1's After Deleting One Element

**Difficulty:** Medium | **Language:** C++

# Longest Subarray of 1's After Deleting One Element

### Approach Summary
The problem is solved using the **Sliding Window** technique. We maintain a window `[l, r]` that keeps track of a subarray containing at most one zero. Since the problem requires us to delete exactly one element, a window with one zero effectively represents the longest possible sequence of 1s we can achieve by deleting that single zero. By expanding the right boundary (`r`) to include elements and shrinking the left boundary (`l`) whenever we encounter more than one zero, we can efficiently scan the array once to find the maximum possible length.

### Step-by-Step Explanation

1.  **Initialize Pointers and State**: We use two pointers, `l` (left) and `r` (right), both starting at the beginning of the array. We also track the count of zeros currently inside our window using the variable `zeros`. `res` stores the maximum length found so far.
2.  **Expand the Window**: We iterate through the array using the `r` pointer. Every time we encounter a `0`, we increment our `zeros` counter.
3.  **Maintain the Constraint**: Because we are only allowed to delete one element, our window can contain at most one `0`. If `zeros` exceeds 1, we must shrink the window from the left. We move the `l` pointer forward, and if the element we are removing is a `0`, we decrement the `zeros` counter. We repeat this until the window is valid again (i.e., `zeros <= 1`).
4.  **Calculate the Result**: At each step, the length of the subarray containing only 1s (after the required deletion) is calculated as `r - l`. 
    *   *Why `r - l`?* If the window contains one zero, the length of the window is `r - l + 1`. Since we delete that one zero, the length of the remaining 1s is `(r - l + 1) - 1`, which simplifies to `r - l`.
    *   If the window contains zero zeros, `r - l` still effectively measures the current length of 1s (though this technically requires us to delete an extra '1', the logic holds for finding the maximum).
5.  **Return**: After the loop finishes, `res` will hold the length of the longest subarray of 1s possible.

### Complexity Analysis

*   **Time Complexity**: **O(n)**, where *n* is the length of the array. Even though there is a nested `while` loop, each element in the array is visited at most twice (once by the `r` pointer and once by the `l` pointer).
*   **Space Complexity**: **O(1)**. We only use a constant amount of extra space for integer variables (`l`, `r`, `zeros`, `res`), regardless of the input array size.
