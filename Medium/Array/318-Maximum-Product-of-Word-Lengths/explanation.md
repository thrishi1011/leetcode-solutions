# Maximum Product of Word Lengths

**Difficulty:** Medium | **Language:** C++

# Maximum Product of Word Lengths

### Approach Summary
The core challenge of this problem is efficiently checking if two strings share common letters. Instead of using nested loops to compare every character of two strings (which would be slow), we represent each word as a "bitmask." Since there are only 26 lowercase English letters, a 26-bit sequence (using `std::bitset<26>`) can perfectly track which characters are present in a word. If the bitwise AND of two masks is zero, it means the words share no common letters. By pre-calculating these bitmasks for every word, we can quickly compare pairs and keep track of the maximum product of their lengths.

### Step-by-Step Explanation

1.  **Preprocessing with Bitsets**: We iterate through the list of words once to build a collection of bitmasks. For each word, we create a `bitset<26>`. We loop through the characters of that word and flip the bit at the index corresponding to that letter (e.g., 'a' maps to 0, 'b' to 1). This turns a string into a simple, compact integer-like representation where the $k$-th bit is 1 if the $k$-th letter of the alphabet is in the word.
2.  **Iterative Comparison**: Once we have the bitmasks, we use a nested loop structure to compare every possible pair of words $(i, j)$. We only need to check each pair once (where $j < i$), which keeps the number of comparisons manageable.
3.  **Checking for Common Letters**: We use a helper function (`checkCommon`) that evaluates whether two bitsets share any set bits. Because we represented the words as bits, checking for commonality is extremely fast. If `checkCommon` returns false, it confirms the two words are "disjoint" (share no letters).
4.  **Updating the Maximum**: When a disjoint pair is found, we multiply their lengths (`words[i].size() * words[j].size()`) and compare this value against our current running maximum (`ans`). We update `ans` whenever we find a larger product.
5.  **Final Result**: After all pairs have been checked, we return the maximum product found, or 0 if no disjoint pairs were discovered.

### Complexity Analysis

*   **Time Complexity**: $O(N \cdot L + N^2)$, where $N$ is the number of words and $L$ is the maximum length of a word. Preprocessing takes $O(N \cdot L)$ to iterate through all characters, and comparing all pairs takes $O(N^2)$ (as the bitset check is constant time, $O(1)$).
*   **Space Complexity**: $O(N)$, as we store a `bitset<26>` for each of the $N$ words to facilitate fast comparisons.
