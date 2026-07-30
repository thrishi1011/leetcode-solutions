# Sorted GCD Pair Queries

**Difficulty:** Hard | **Language:** cpp

# Sorted GCD Pair Queries Solution

### Approach Summary
The problem asks for values at specific indices in a sorted list of all possible pair GCDs. Since the constraints on `nums` (up to $50,000$) are much smaller than the number of potential pairs (which could reach $\approx 5 \times 10^9$), we cannot generate all pairs. Instead, we use a counting approach based on inclusion-exclusion. We first count how many numbers in the input are multiples of each integer $g$ (from $1$ to $50,000$). From these counts, we derive the exact number of pairs whose GCD is a multiple of $g$, and finally, subtract the overlapping counts to find exactly how many pairs have a GCD of $g$. By accumulating these counts, we can map the index queries to their corresponding GCD values using binary search or prefix sums.

### Step-by-step Explanation

1.  **Counting Multiples:** We first create a frequency array `cnt` for the input `nums`. Then, for every possible GCD value $g$ (from $50,000$ down to $1$), we count how many numbers in the original array are multiples of $g$. Let this be `multiples_of_g`.

2.  **Calculating Pairs with GCD exactly $g$:** The number of pairs $(nums[i], nums[j])$ whose GCD is a multiple of $g$ is given by the combination formula: `multiples_of_g * (multiples_of_g - 1) / 2`. Let's call this `total_pairs_divisible_by_g`. However, this count includes pairs whose GCD is $2g, 3g, 4g$, etc. To find the count of pairs where the GCD is *exactly* $g$, we subtract the counts we already calculated for $2g, 3g, 4g, \dots$ from `total_pairs_divisible_by_g`. By iterating backwards from $50,000$ to $1$, we ensure that when we are at $g$, the values for all multiples of $g$ are already computed.

3.  **Building the Distribution:** After computing the exact count of pairs for each GCD value, we store these in an array (e.g., `gcd_counts`). This array acts as a frequency map where index $g$ holds the number of times $g$ appears in the `gcdPairs` list.

4.  **Answering Queries:** To efficiently find the value at a specific index $k$ of the sorted `gcdPairs`, we calculate the prefix sums of the `gcd_counts` array. A prefix sum at index $x$ tells us how many pairs have a GCD $\le x$. For each query, we perform a binary search on this prefix sum array to find the smallest $x$ such that the prefix sum is greater than the query index.

### Complexity Analysis

*   **Time Complexity:** $O(M \log M + Q \log M)$, where $M$ is the maximum value in `nums` ($50,000$) and $Q$ is the number of queries. The $M \log M$ term comes from the harmonic series summation used to count multiples for every $g$, and $Q \log M$ comes from performing a binary search for each query.
*   **Space Complexity:** $O(M)$, as we only need frequency arrays and prefix sum arrays proportional to the maximum value in the input array.
