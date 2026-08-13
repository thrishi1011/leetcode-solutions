# Count the Number of Consistent Strings

**Difficulty:** Easy | **Language:** C++

# Solution: Count the Number of Consistent Strings

### Approach
The problem asks us to determine how many strings in a given list consist solely of characters found in a provided `allowed` string. To solve this efficiently, we use a boolean array of size 26 to act as a "lookup table." This table allows us to check in constant time whether any specific character is allowed. We initialize our count to the total number of words and then subtract from this total whenever we encounter a word containing an unauthorized character.

### Step-by-step Explanation

1.  **Preprocessing the Allowed Characters:** 
    Since there are only 26 lowercase English letters, we create a boolean array (`alpha`) of size 26, initialized to `false`. We iterate through the `allowed` string and mark the index corresponding to each character as `true` (e.g., 'a' maps to index 0, 'b' to 1, etc.). This gives us an ultra-fast way to verify if a character is permitted.

2.  **Tracking Consistent Words:** 
    We start by assuming every word in the array is consistent by setting our counter (`cnt`) to the total number of words. 

3.  **Validation:** 
    We iterate through each word in the `words` list. For every word, we check its characters one by one. If we find a character that is marked as `false` in our `alpha` lookup table, we know the word is "inconsistent." 

4.  **Updating the Result:** 
    If an inconsistent character is found, we decrement our `cnt` by one and immediately stop checking the rest of that word (using `break`) to save time. 

5.  **Final Result:** 
    After checking all words, the remaining value in `cnt` represents the total number of consistent strings.

### Complexity Analysis

*   **Time Complexity: O(N * L)**
    Where *N* is the number of words in the array and *L* is the average length of the words. We iterate through every character of every word exactly once to perform the validation, and the lookup operation in the boolean array takes constant O(1) time.

*   **Space Complexity: O(1)**
    We use a fixed-size boolean array of size 26 to store the `allowed` characters. Since this size does not scale with the input size of `words`, it is considered constant space.
