# Single Number II

**Difficulty:** Medium | **Language:** C++

# Solution: Single Number II

### Approach Summary
The provided solution utilizes a hash map (specifically `std::unordered_map`) to track the frequency of every integer in the input array. By iterating through the array once, the code populates the map with the counts of each number. A second iteration through the map allows us to identify the entry where the count is exactly one, which corresponds to the "single number" we are looking for. This approach is intuitive and leverages the efficiency of hash-based lookups to solve the problem by treating it as a frequency counting exercise.

### Step-by-Step Explanation
1. **Initialize a tracker:** We create an `unordered_map` where the "key" represents the numbers found in the input array and the "value" represents how many times that specific number has appeared.
2. **Count occurrences:** We loop through each integer in the `nums` array. For every number we encounter, we increment its corresponding value in the map. If the number is new to the map, it is added with an initial count of 1; if it has been seen before, its count is increased.
3. **Identify the unique element:** After the map is fully populated, every number except one will have a value of 3 in the map. We loop through the map's key-value pairs and inspect the counts. The moment we find a key associated with a value of 1, we know we have found the single number.
4. **Return the result:** Once the unique number is identified, we return it immediately. The function includes a default return of -1 to handle cases where no such number exists, though the problem constraints guarantee one will always be found.

### Complexity Analysis
*   **Time Complexity: O(N)**
    We iterate through the `nums` array of size $N$ exactly once to build the map, and then we iterate through the map. In the worst case, the map contains approximately $N/3 + 1$ elements. Since hash map operations (insertion and lookup) are $O(1)$ on average, the total time complexity remains linear.

*   **Space Complexity: O(N)**
    We store the counts of the elements in a hash map. Because we must store approximately $N/3$ unique elements from the input array, the space required grows linearly with the size of the input. 

*Note: While this solution is highly readable and performs well, it does not strictly meet the "constant extra space" constraint requested in the problem description, as it uses O(N) space. A true constant-space solution would require bitwise manipulation to track the bits at each position.*
