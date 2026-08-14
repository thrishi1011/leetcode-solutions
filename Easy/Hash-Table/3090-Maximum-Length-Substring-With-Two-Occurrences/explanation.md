# Maximum Length Substring With Two Occurrences

**Difficulty:** Easy | **Language:** C++

# Maximum Length Substring With Two Occurrences

### Approach
To solve this problem, we use the **Sliding Window** technique. We maintain a window defined by two pointers, `i` (left) and `j` (right), which represents the current substring we are examining. As we expand the window by moving `j` to the right, we keep track of character frequencies using a hash map. If adding a character causes its frequency to exceed two, the window becomes "invalid." We then shrink the window from the left by moving `i` forward and updating the frequencies until the character count returns to two. Throughout this process, we keep track of the maximum window size achieved.

### Step-by-step Explanation

1.  **Initialize Variables:** We start with two pointers, `i` and `j`, both at the beginning of the string. We also create an `unordered_map` to store how many times each character appears in our current window and a `res` variable to store the longest valid substring length found so far.
2.  **Expand the Window:** We use a `while` loop to move the right pointer `j` across the string. In every step, we add the character at `s[j]` to our map, effectively including it in our current window.
3.  **Validate the Window:** After adding a character, we check if its frequency has exceeded the limit of two. If `m[s[j]] > 2`, the substring is no longer valid. To fix this, we enter a nested `while` loop that shrinks the window from the left by incrementing `i` and decrementing the frequency of the characters we remove until the character count at `s[j]` is back to two.
4.  **Update the Result:** Once the window is valid again, the substring from `i` to `j` satisfies the condition. We calculate its length (`j - i + 1`) and compare it against our current `res`, keeping the larger value.
5.  **Final Result:** After `j` has traversed the entire string, `res` will hold the length of the longest valid substring we encountered.

### Complexity Analysis

*   **Time Complexity:** $O(n)$, where $n$ is the length of the string. Although there is a nested loop, each pointer (`i` and `j`) only travels across the string from index 0 to $n-1$ exactly once. Each character is added to and removed from the map at most once.
*   **Space Complexity:** $O(1)$ (or $O(k)$ where $k$ is the alphabet size). The hash map stores character frequencies for lowercase English letters. Since there are only 26 possible letters, the map will never exceed 26 entries regardless of how long the input string is.
