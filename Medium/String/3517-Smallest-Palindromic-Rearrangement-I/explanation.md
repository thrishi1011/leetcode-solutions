# Smallest Palindromic Rearrangement I

**Difficulty:** Medium | **Language:** cpp

### Approach Summary
To find the lexicographically smallest palindromic permutation, we must arrange the characters such that the smallest available characters are placed as close to the beginning of the string as possible. Since a palindrome is symmetric, placing a character at the start automatically dictates its position at the end. By counting the frequency of each character, we can greedily fill the string from the outside in (moving from 'a' to 'z'). We pair up identical characters to occupy the symmetric positions at the start and end of the string, while any remaining single character (which must exist if the string length is odd) is placed directly in the middle.

### Step-by-Step Explanation

1.  **Frequency Counting**: We first use a frequency array of size 26 to count how many times each letter appears in the string. This tells us exactly which characters we have at our disposal.
2.  **Preparing the Skeleton**: We initialize an empty string `ans` of the same length as the input. We also set two pointers, `left` at the start (index 0) and `right` at the end (last index), to track where we will place our characters.
3.  **Greedy Construction**: We iterate through the alphabet from 'a' to 'z':
    *   **Pairing Characters**: While we have at least 2 of the current character, we place one at the `left` index and one at the `right` index. We then move `left` forward and `right` backward. This ensures the smallest possible characters are anchored at the outermost positions, creating the lexicographically smallest result.
    *   **Handling the Middle**: If a character has a remaining count of 1 after all possible pairs are placed, it must be the "center" character of the palindrome. Because the problem guarantees the input is already a palindrome, there will be exactly one such character in an odd-length string, which we place at the middle index (`n / 2`).
4.  **Final Result**: Once the loop completes, the `ans` string is fully populated and represents the smallest possible palindromic rearrangement.

### Complexity Analysis

*   **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies ($O(N)$) and then iterate through the frequency array and build the string ($O(N + 26)$). Since 26 is a constant, this simplifies to linear time.
*   **Space Complexity**: $O(1)$ (or $O(26)$). We use a fixed-size frequency array of 26 integers regardless of the input string length, which is considered constant extra space. (Note: The output string space is typically not counted toward auxiliary space complexity).
