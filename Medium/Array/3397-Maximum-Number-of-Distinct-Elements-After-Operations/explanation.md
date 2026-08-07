# Maximum Number of Distinct Elements After Operations

**Difficulty:** Medium | **Language:** C++

# Maximum Number of Distinct Elements After Operations

### Approach
The problem asks us to transform an array by shifting each element within a range $[-k, k]$ to maximize the count of unique numbers. The optimal strategy is to sort the array first, allowing us to process the numbers in increasing order. By maintaining the value of the "previously used" number, we greedily assign the smallest possible value to each element that is still greater than the previous choice and within the valid range $[nums[i] - k, nums[i] + k]$. This ensures we keep our options open for future, larger numbers while maximizing the count of distinct elements.

### Step-by-Step Explanation

1.  **Sorting:** We start by sorting the input array. Sorting is crucial because it allows us to handle smaller numbers first. By fixing the smaller numbers at the lowest possible valid values, we leave "more room" in the number line for larger numbers to find a unique value.
2.  **Tracking Progress:** We use a variable `prev` to keep track of the value assigned to the most recently processed element. We initialize `prev` to a very small number (effectively negative infinity) because no numbers have been assigned yet.
3.  **Greedy Assignment:** We iterate through the sorted array. For each number, its allowable range is $[nums[i] - k, nums[i] + k]$.
    *   To be as efficient as possible, we want to pick the smallest value for the current element that is still strictly greater than `prev`.
    *   We calculate the candidate value `l` as the maximum of either the start of the current element's range (`nums[i] - k`) or the value immediately following the previous one (`prev + 1`).
4.  **Validation:** Once we determine our candidate `l`, we check if it falls within the allowed range of the current number (i.e., is `l <= nums[i] + k`?).
    *   If it is, we have successfully found a new distinct value. We update `prev` to this new value `l` and increment our `ans` counter.
    *   If `l` exceeds the upper bound, it means all values in the range for the current number have already been "used up" by previous elements. In this case, we simply skip this element as it cannot contribute to a new distinct value.

### Complexity Analysis

*   **Time Complexity: $O(N \log N)$**
    The bottleneck of the algorithm is sorting the array, which takes $O(N \log N)$ time. The subsequent single pass through the array takes only $O(N)$ time.
*   **Space Complexity: $O(1)$**
    (Or $O(N)$ depending on the sorting implementation's stack space). Aside from the input array, we only use a few integer variables (`ans`, `prev`, `l`) to store state, satisfying constant extra space requirements.
