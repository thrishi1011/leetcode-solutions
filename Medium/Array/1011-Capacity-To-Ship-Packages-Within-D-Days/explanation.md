# Capacity To Ship Packages Within D Days

**Difficulty:** Medium | **Language:** cpp

### Approach: Binary Search on the Answer

The problem asks for the *minimum* capacity that satisfies a constraint. This structure is a classic indicator for **Binary Search on the Answer**. Instead of trying to guess the capacity, we define a range of possible capacities: the lower bound is the weight of the heaviest single package (since the ship must be at least that large to carry it), and the upper bound is the sum of all weights (where the ship carries everything in one day). For any given capacity `mid` within this range, we can simulate the shipping process to see if it takes more or fewer than the allowed `D` days. By checking these results, we can narrow down the search range until we find the smallest possible capacity that successfully ships all packages in time.

### Step-by-Step Explanation

1.  **Defining the Search Range**: 
    *   The smallest possible capacity (`left`) must be at least the weight of the heaviest package; otherwise, that package could never be shipped. 
    *   The largest possible capacity (`right`) is the total sum of all package weights, which would allow us to ship everything in a single day.
2.  **Binary Search Loop**: 
    *   We calculate the midpoint (`mid`) between our `left` and `right` boundaries. This `mid` represents a "test" capacity for the ship.
3.  **Simulation (`canShip` logic)**: 
    *   For a chosen `mid`, we simulate the shipping process. We keep a running total of the current load (`cur`) and a count of the days used (`need`). 
    *   As we iterate through the `weights`, we add them to the ship one by one. If adding the next package exceeds the `mid` capacity, we increment our day counter and reset the current load to zero, effectively starting a new day with that package.
4.  **Adjusting Boundaries**: 
    *   If the simulation shows that we need more than `D` days, our current `mid` is too small to handle the packages in the required timeframe, so we set `left = mid + 1`.
    *   If the simulation shows that we finish within or exactly on `D` days, the capacity might be the correct one, or we might be able to find an even smaller one. Therefore, we set `right = mid` to keep looking in the lower half of our range.
5.  **Termination**: 
    *   The loop continues until `left` and `right` converge. At this point, `left` represents the minimum capacity required to meet the shipping deadline.

### Complexity Analysis

*   **Time Complexity**: O(N log(S)), where N is the number of packages and S is the sum of all weights. 
    *   We perform a binary search over the range of possible weights (size S), which takes O(log S) iterations. Inside each iteration, we traverse the entire list of weights once, which takes O(N).
*   **Space Complexity**: O(1). 
    *   We only use a few variables (`left`, `right`, `mid`, `cur`, `need`) to manage our binary search and simulation. No extra data structures are created that grow with the input size.
