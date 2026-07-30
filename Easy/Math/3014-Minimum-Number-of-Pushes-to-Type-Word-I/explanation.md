# Minimum Number of Pushes to Type Word I

**Difficulty:** Easy | **Language:** C++

# Minimum Number of Pushes to Type Word I

### Approach Summary
The problem asks us to minimize the total number of key presses required to type a word using a telephone keypad (keys 2–9). Since each letter in the input string is distinct, we want to assign the most frequently typed letters (which, in this case, are all typed exactly once) to the "cheapest" positions on the keypad. A standard telephone keypad has 8 available keys (2 through 9). The first 8 letters can be typed with 1 push each, the next 8 letters require 2 pushes each, and so on. This solution uses mathematical grouping to determine how many letters fall into each "push tier" and calculates the total cost accordingly.

### Step-by-step Explanation

1.  **Determining the Tiers:** Since there are 8 keys available, we can assign 8 unique letters to the "first position" on each key (costing 1 push each). If the word has more than 8 letters, the 9th through 16th letters must be assigned to the "second position" on those keys (costing 2 pushes each).
2.  **Calculating `q` and `r`:** 
    *   `q = A.size() >> 3`: This is a bitwise way of dividing the word length by 8. It tells us how many full sets of 8 keys are completely filled. For example, if the word has 10 letters, `q` is 1, meaning one full set of 8 keys is used at cost 1, and the remaining 2 letters move to the next tier.
    *   `r = A.size() & 7`: This is a bitwise way of finding the remainder when dividing by 8 (`word.length % 8`). It tells us how many letters are left over after filling the full sets of 8.
3.  **Calculating the Total Pushes:** 
    *   The variable `ans` represents the number of letters that will be pressed at the current "base cost" tier.
    *   The total cost is calculated by multiplying the number of letters in a tier by the number of pushes required for that tier. Because the problem asks for the minimum, we fill the 1-push tier first, then the 2-push tier, and so on. The logic `(ans * (q + 1))` effectively aggregates these costs by multiplying the count of characters by their respective multiplier (1, 2, 3, etc.) based on how many full cycles of 8 keys were completed.

### Complexity Analysis

*   **Time Complexity: O(1)**
    The algorithm performs a constant number of arithmetic and bitwise operations. It does not iterate through the string, making the runtime independent of the input size.
*   **Space Complexity: O(1)**
    The algorithm only uses a few integer variables to store the results of the calculation, requiring no additional data structures that scale with input size.
