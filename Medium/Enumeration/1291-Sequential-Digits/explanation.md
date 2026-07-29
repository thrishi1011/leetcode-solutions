# Sequential Digits

**Difficulty:** Medium | **Language:** cpp

# Sequential Digits Solution Explanation

### Approach Summary
The problem asks for all numbers within a range `[low, high]` where each digit is exactly one greater than the digit preceding it. Since the maximum possible number is $10^9$, there are a very limited number of such "sequential" integers. The approach uses a pre-defined reference string `"123456789"` and uses nested loops to generate all possible sequential substrings. We iterate through every possible length (from 2 to 9) and every possible starting position within the string, convert these substrings into integers, and collect those that fall within the specified `[low, high]` range.

### Step-by-step Explanation

1.  **Establishing the Source:** We create a reference string `s = "123456789"`. This string contains all digits in sequential order. Any "sequential digit" number must be a contiguous substring of this string.
2.  **Iterating by Length:** A sequential number can be as short as 2 digits (e.g., 12) or as long as 9 digits (e.g., 123456789). We use an outer loop (`len`) to define how many digits we are currently looking at.
3.  **Sliding the Window:** For each specific length, we use an inner loop (`start`) to slide a window across the string `s`. For instance, if the length is 3, the `start` index moves through the string such that we extract "123", "234", "345", and so on.
4.  **Building the Integer:** Once we have identified a substring, we convert it into an integer. We do this mathematically by starting with 0 and, for each character in the window, multiplying the current total by 10 and adding the new digit. This effectively shifts the existing digits to the left to make room for the new one at the end.
5.  **Filtering and Storing:** Finally, we check if the generated number satisfies the problem constraints (`num >= low` and `num <= high`). If it does, we add it to our result list. Since our loops naturally generate these numbers in increasing order of length and starting position, the resulting list is automatically sorted.

### Complexity Analysis

*   **Time Complexity: $O(1)$**
    While there are nested loops, the number of sequential integers is constant. The length loop runs 8 times (2–9) and the starting position loop runs at most 9 times. This results in a fixed number of operations (roughly 45 iterations) regardless of the input `low` or `high` values. Thus, the time complexity is constant.

*   **Space Complexity: $O(1)$**
    The amount of extra space used is minimal and constant. The result vector stores a maximum of 36 possible sequential integers, which does not scale with the size of the input.
