# Zigzag Conversion

**Difficulty:** Medium | **Language:** cpp

# Zigzag Conversion Solution

### Approach
The problem asks us to map characters of a string into a vertical zigzag pattern and then read them row by row. Instead of calculating the coordinates of each character mathematically, we can simulate the process by creating a "bucket" for each row. By iterating through the string once and maintaining a pointer to the current row, we can toggle the direction (up or down) whenever we hit the first or last row. This allows us to distribute characters into their respective rows naturally as if we were physically writing them out, after which we simply concatenate the contents of all buckets to form the final result.

### Step-by-Step Explanation

1.  **Handling Edge Cases**: If `numRows` is 1, the zigzag pattern is just a straight line. The output would be identical to the input, so we return the original string immediately to save processing time.
2.  **Initializing Rows**: We create a `vector<string>` of size `numRows`. Each element in this vector acts as a container (a bucket) for the characters that belong to that specific row.
3.  **Tracking Movement**: We use a variable `curRow` to keep track of where we are currently placing a character, and a boolean flag `goingDown` to track whether we are moving toward the bottom row or back up toward the top row.
4.  **The Simulation Loop**:
    *   For every character in the string, we append it to the current row’s bucket.
    *   **Direction Logic**: If we reach the top row (`curRow == 0`), we set `goingDown` to true. If we reach the bottom row (`curRow == numRows - 1`), we flip `goingDown` to false. This ensures the index correctly bounces between 0 and `numRows - 1`.
    *   **Moving**: Based on the `goingDown` flag, we increment or decrement `curRow`.
5.  **Reconstruction**: Once all characters have been distributed into their respective rows, we iterate through the `rows` vector and append every string bucket to a final answer string. Because the rows are stored in order from top to bottom, joining them directly gives us the correct zigzag-read string.

### Complexity Analysis

*   **Time Complexity**: $O(n)$, where $n$ is the length of the string `s`. We iterate through each character in the input string exactly once to distribute them into rows, and then traverse the rows to build the result, making the operation linear relative to the input size.
*   **Space Complexity**: $O(n)$. Although we are using a vector of strings, the total number of characters stored across all rows is equal to the length of the input string `s`. Therefore, the space required scales linearly with the input size.
