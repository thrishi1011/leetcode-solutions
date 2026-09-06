# Minimum Amount of Time to Fill Cups

**Difficulty:** Easy | **Language:** C++

# Minimum Amount of Time to Fill Cups

### Approach Summary
The problem asks for the fastest way to fill three types of cups given that we can fill up to two distinct cups simultaneously. This is a classic greedy problem that can be solved by considering two constraints: the most frequent cup type and the total number of cups. If one type of cup is very abundant (more than the sum of the other two), we are bottlenecked by that specific type, and the answer is simply the count of that cup. If the cups are relatively balanced, we can pair them up efficiently such that we finish in roughly half the total time (rounded up). The final answer is the maximum of these two constraints.

### Step-by-step Explanation

1.  **Identify the Constraints:** 
    *   **The "Bottleneck" Constraint:** If one type of cup has a quantity greater than the sum of the other two, we cannot pair all of those cups with others. We are forced to fill them one by one (or at best, one of them and one other). Thus, the minimum time is exactly the amount of that cup type (`mx`).
    *   **The "Efficiency" Constraint:** If no single type of cup dominates, we can almost always fill two cups every second. Since we have a total of `sum` cups and can fill two at a time, the time required will be roughly `sum / 2`. We use `(sum + 1) / 2` to perform integer division that rounds up, effectively accounting for the "leftover" cup when the total sum is odd.

2.  **Calculate the Variables:**
    *   We iterate through the `amount` array once to find two values: the maximum value present (`mx`) and the total sum of all cups (`sum`).

3.  **Determine the Result:**
    *   By returning `max(mx, (sum + 1) / 2)`, we cover both scenarios. If the largest cup count is very high, `mx` will be the answer. If the cup counts are spread out, `(sum + 1) / 2` will be the answer. This mathematical shortcut replaces the need for complex simulation or priority queues.

### Complexity Analysis

*   **Time Complexity: O(1)**
    The input size is fixed at 3. Whether the input is small or large, we perform a constant number of operations (iterating through 3 elements and basic arithmetic).
*   **Space Complexity: O(1)**
    We only use a few integer variables (`mx`, `sum`) to store our intermediate values, regardless of the values within the input array.
