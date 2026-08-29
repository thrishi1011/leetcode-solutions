# Make Lexicographically Smallest Array by Swapping Elements

**Difficulty:** Medium | **Language:** C++

# Solution Explanation: Make Lexicographically Smallest Array by Swapping Elements

### Approach Summary
The core insight of this problem is to identify groups of numbers that can be swapped with each other. If two numbers have a difference less than or equal to the `limit`, they belong to the same "swappable" component. By sorting the array, we can identify these components by checking if the difference between adjacent sorted elements exceeds the `limit`. Once these components are identified, we treat each group as a pool of numbers that can be rearranged into any position within the original indices belonging to that group. To achieve the lexicographically smallest result, we place the smallest available number from each group into the earliest possible index reserved for that group.

### Step-by-Step Explanation

1.  **Identify Swap Groups:** We first create a sorted copy of the input array. Because we can only swap numbers with a difference of `limit`, any two numbers $A$ and $B$ can be swapped (directly or indirectly) if they belong to a sequence where every adjacent pair differs by no more than `limit`. By iterating through the sorted array, if the difference between `sorted[i]` and `sorted[i-1]` is greater than `limit`, we start a new "group" (an `id` increment).
2.  **Mapping Groups:** We maintain two structures:
    *   `group`: A dictionary where each key is the group ID, and the value is a list of all numbers belonging to that group, stored in sorted order.
    *   `groupId`: A dictionary that maps every number in the input to its corresponding group ID.
3.  **Constructing the Result:** We iterate through the original `nums` array. For each number at index `i`, we look up which group it belongs to using `groupId`. 
4.  **Filling Positions:** Since we want the lexicographically smallest array, we replace the current `nums[i]` with the smallest available number from its assigned group. We use a pointer (`pos[grp]`) to keep track of which numbers from that group have already been used. Because the lists in `group` are already sorted, simply picking elements one by one ensures we always place the smallest available value in the earliest possible slot.

### Complexity Analysis

*   **Time Complexity:** $O(N \log N)$
    *   Sorting the array takes $O(N \log N)$. 
    *   The single pass to group elements and the final pass to reconstruct the array take $O(N)$ time. 
    *   Hash map operations take $O(1)$ on average, making the overall dominant factor the sorting step.

*   **Space Complexity:** $O(N)$
    *   We store the numbers in the `group` map, the `groupId` map, and the `pos` map. Each of these structures holds at most $N$ elements, resulting in linear space usage.
