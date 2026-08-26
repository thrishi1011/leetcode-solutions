# Shortest and Lexicographically Smallest Beautiful String

**Difficulty:** Medium | **Language:** C++

# Shortest and Lexicographically Smallest Beautiful String

### Approach Summary
The problem is solved using a brute-force approach with two nested loops to examine every possible substring of the input string $s$. We iterate through every possible starting position of a substring and expand it character by character, keeping track of the count of '1's encountered. Whenever a substring contains exactly $k$ ones, we compare it against our current best result ("best" being defined first by shortest length, and then by lexicographical order). This approach is efficient enough given the constraint that the string length is at most 100.

### Step-by-step Explanation

1.  **Initialize Result:** We start with an empty string `ans`. This will act as a placeholder for the best beautiful substring found so far.
2.  **Outer Loop (Starting Point):** The outer loop iterates through every index $i$ from 0 to $n-1$, treating each as the beginning of a potential substring.
3.  **Inner Loop (Expansion):** For each starting index $i$, we create a new empty string `cur` and a counter `oneCnt`. We then iterate forward through the string starting from $i$ using index $j$.
    *   **Accumulate:** With each step $j$, we add the character `s[j]` to `cur`.
    *   **Count '1's:** If the current character is '1', we increment `oneCnt`. 
    *   **Pruning:** If `oneCnt` exceeds $k$, we stop expanding this specific substring immediately, as it can no longer be "beautiful."
4.  **Evaluate:** When `oneCnt` exactly equals $k$, we have found a "beautiful" substring. We then perform a check to see if this `cur` is better than our previous `ans`:
    *   If `ans` is currently empty (meaning this is our first beautiful substring), we accept `cur`.
    *   If `cur` is shorter than `ans`, we replace `ans` with `cur` because the problem prioritizes shorter lengths.
    *   If `cur` has the same length as `ans` but is lexicographically smaller (e.g., "10" is smaller than "11"), we update `ans` to `cur`.
5.  **Conclusion:** After checking all possible substrings, we return `ans`. If no beautiful substring was found, `ans` will remain an empty string, which matches the problem requirements.

### Complexity Analysis

*   **Time Complexity:** $O(n^2)$, where $n$ is the length of string $s$. We use two nested loops to traverse possible substrings. Since $n \le 100$, $n^2$ results in at most 10,000 operations, which easily fits within the time limit.
*   **Space Complexity:** $O(n)$. In the worst case, the string `cur` can grow to size $n$, and we store at most one such string (`ans`) at a time. Therefore, the additional space used is proportional to the input length.
