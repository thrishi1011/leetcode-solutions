# Evaluate the Bracket Pairs of a String

**Difficulty:** Medium | **Language:** C++

# Evaluate the Bracket Pairs of a String

### Approach Summary
The problem is solved using an efficient lookup strategy combined with a single-pass string scan. First, we store the `knowledge` array in an `unordered_map` to allow for $O(1)$ average-time access to key-value pairs. Then, we iterate through the input string character by character, using a boolean flag to track whether we are currently "inside" a bracket pair. As we scan, we either build up a temporary key string, append known values from our map to a result string, or simply copy characters that are outside of brackets.

### Step-by-step Explanation

1.  **Preparation (Preprocessing):** 
    We convert the 2D `knowledge` vector into an `unordered_map<string, string>`. This allows us to instantly check if a key exists and retrieve its corresponding value without having to search through the original list repeatedly.

2.  **Tracking State:**
    We initialize three variables: `res` (to store the final string), `key` (to capture the text inside brackets), and `flag` (a boolean that acts as a switch). The `flag` is `false` by default, indicating we are currently reading plain text.

3.  **The Iteration Logic:**
    As we loop through every character in the string `s`:
    *   **Finding a key:** When we encounter an opening bracket `(`, we set `flag` to `true`. This tells our logic that subsequent characters are part of a key rather than literal text.
    *   **Capturing the key:** While `flag` is `true`, every character we hit is appended to our temporary `key` variable.
    *   **Evaluating the key:** When we encounter a closing bracket `)`, we know we have finished reading a key. We check if this key exists in our map:
        *   If it exists, we append the mapped value to our result string `res`.
        *   If it does not exist, we append a `?` instead.
        *   After this, we reset `key` to an empty string and turn `flag` off, preparing to look for the next bracket pair.
    *   **Plain text:** If we are not inside brackets (`flag` is `false`), we simply append the current character directly to our result string.

4.  **Completion:**
    Once the loop finishes, all bracket pairs have been replaced or resolved to `?`, and the `res` string contains the fully evaluated message.

### Complexity Analysis

*   **Time Complexity: $O(N + M)$**
    *   Building the map takes $O(M)$, where $M$ is the number of elements in the `knowledge` array.
    *   Scanning the string `s` takes $O(N)$, where $N$ is the length of the string. Each character is visited exactly once.
*   **Space Complexity: $O(N + M)$**
    *   We store the `knowledge` map, which takes $O(M)$ space. 
    *   The result string `res` takes $O(N)$ space, as it will eventually hold the evaluated version of the input string.
