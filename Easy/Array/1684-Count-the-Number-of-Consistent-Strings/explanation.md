# Count the Number of Consistent Strings

**Difficulty:** Easy | **Language:** python

# Solution: Count the Number of Consistent Strings

### Summary of Approach
The approach uses a "subtraction" strategy to identify consistent strings. We start by assuming that every word in the given list is consistent, setting our counter to the total number of words. We then iterate through each word and examine every character within it. If we find a single character that does not exist in the `allowed` string, we know the word is inconsistent; we decrement our counter and immediately move on to the next word to save time.

### Step-by-Step Explanation

1.  **Initialize the Counter**: We begin by assuming all words are consistent. We set `cnt` equal to the length of the `words` array.
2.  **Iterate through the Words**: We use a `for` loop to inspect every `word` in the input list one by one.
3.  **Check Characters**: Within each word, we look at every individual character (`ch`). 
4.  **Identify Inconsistency**: The logic is based on a simple check: if a character `ch` is not found in the `allowed` string, that word cannot be consistent. 
    *   When we find such an illegal character, we subtract 1 from our `cnt`.
    *   Crucially, we use `break` to stop checking the rest of the characters in that specific word. Since we only need one "bad" character to disqualify a word, there is no need to keep checking the remaining characters of that word.
5.  **Return the Result**: After checking all words, the `cnt` variable holds the number of strings that were never disqualified. We return this value.

### Complexity Analysis

*   **Time Complexity**: $O(N \times M)$, where $N$ is the number of words in the list and $M$ is the average length of the words. In the worst case, we check every character of every word once. (Note: Checking `if ch in allowed` is $O(A)$ where $A$ is the length of `allowed`; since $A \leq 26$, this is effectively a constant time operation).
*   **Space Complexity**: $O(1)$. We do not use any additional data structures that scale with the size of the input; we only use a single integer variable to keep track of the count.
