# Process String with Special Operations II

**Difficulty:** Hard | **Language:** C++

# Approach Summary

The problem involves a string that can grow to an astronomical length (up to $10^{15}$), making it impossible to store the full string in memory. To solve this, we use a two-pass strategy. In the first pass, we simulate the operations to calculate the final total length of the string. In the second pass, we work backwards from the end of the string to the beginning. By keeping track of the "current length" as we traverse the operations in reverse, we can determine exactly which character at which index is responsible for the character at position $k$.

# Step-by-Step Explanation

### Pass 1: Calculating the Final Length
Since we only need the character at index $k$, we first need to know if $k$ is within bounds and how the operations affect the length. We iterate through the string once:
* **Lowercase letters:** Each letter increases the length by 1.
* **`*` (Remove):** Decreases the length by 1 (if the length is greater than 0).
* **`#` (Duplicate):** Doubles the total length.
* **`%` (Reverse):** Does not change the length.

After this loop, we have the final `len`. If $k$ is greater than or equal to this `len`, we immediately return `.` because the character doesn't exist.

### Pass 2: Working Backwards
This is the core of the algorithm. We imagine the final string and trace how the character at index $k$ was created by moving through the operations in reverse order:
* **Lowercase letters:** Since we are moving backward, if we encounter a character, we check if it is the one at our current index $k$. If `len - 1 == k`, this is our target character. If not, we decrement `len` because this character was part of the string before the current operation.
* **`*` (Remove):** Since removing a character reduces the length, reversing this means we "add back" a character. We increment `len` to account for the character that was previously deleted.
* **`#` (Duplicate):** When we duplicate, the string essentially becomes two identical halves. 
    * If our current $k$ is in the second half (i.e., `k >= len / 2`), we map $k$ to the first half by subtracting the length of one half. 
    * We then halve the `len` to represent the state before the duplication occurred.
* **`%` (Reverse):** Reversing a string at index $k$ simply maps $k$ to its mirrored position, which is `len - 1 - k`.

By applying these inverse operations, we effectively "un-build" the string until we land on the original character that sits at index $k$.

# Complexity

* **Time Complexity:** $O(N)$, where $N$ is the length of the input string $s$. We perform exactly two passes over the input string, performing constant-time arithmetic operations at each step.
* **Space Complexity:** $O(1)$. We do not store the resulting string or any large auxiliary data structures; we only store a few variables (`len` and `k`) to track the state.
