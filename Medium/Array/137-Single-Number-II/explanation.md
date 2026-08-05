# Single Number II

**Difficulty:** Medium | **Language:** C++

# Solution: Single Number II

### Approach Summary
The provided solution utilizes a hash map (specifically `unordered_map` in C++) to track the frequency of each integer in the array. By iterating through the array once, we build a frequency table that maps every number to the count of its occurrences. After the map is populated, we perform a second pass through the map to identify the unique element, which is the only entry associated with a count of one.

### Step-by-step Explanation
1.  **Initialize a Frequency Map**: We create an empty hash map where the "keys" represent the numbers from the input array, and the "values" represent how many times each number has appeared so far.
2.  **Count Occurrences**: We loop through every number in the input array. For each number, we update its corresponding count in the map. If the number is already in the map, its count increases; if it is new, it is added with an initial count of one.
3.  **Identify the Unique Element**: Once the array has been fully processed, we iterate through the key-value pairs stored in the map. Since the problem guarantees that all numbers appear three times except for one, we simply check each entry's value. When we find an entry where the count is exactly one, we have identified our target number and return it immediately.
4.  **Edge Case**: In the unlikely event that no such number is found (which contradicts the problem constraints), the function returns -1 as a fallback.

### Complexity Analysis
*   **Time Complexity: $O(N)$**
    *   We iterate through the input array once to populate the map ($O(N)$) and then iterate through the map to find the unique element. In the worst case, the map contains $N/3 + 1$ unique elements, resulting in a linear time complexity.
*   **Space Complexity: $O(N)$**
    *   We use a hash map to store the frequencies of the elements. In the worst case, we store nearly all unique elements from the array in the map, leading to linear space usage.

*Note: While this solution is clear and readable, it uses $O(N)$ extra space. To satisfy the "constant extra space" requirement strictly mentioned in the problem description, one would typically use bit manipulation techniques to count bits at each position modulo 3.*
