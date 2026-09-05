# Smallest Stable Index II

**Difficulty:** Medium | **Language:** C++

# Solution: Smallest Stable Index II

### Approach
The problem requires finding the first index where the difference between the running maximum from the left and the suffix minimum from the right is at most $k$. A naive approach would calculate these values for every index, leading to $O(n^2)$ or $O(n \log n)$ time. Instead, we use an efficient linear scan. The key insight is that as we iterate, we maintain the "best" possible candidate for a stable index. If we encounter an element that violates the stability condition (i.e., its value is too small compared to the current maximum), it implies that any index up to and including the current one cannot be the "smallest stable index," so we push our candidate pointer forward.

### Step-by-Step Explanation

1. **Tracking the Maximum**: We maintain `maxSoFar`, which keeps track of the maximum value encountered from the start of the array up to the current index `i`. This represents the "left part" of the instability score formula for any index `i`.
2. **Identifying the Candidate**: We use a variable `cand` to store the earliest index that *could* potentially be the smallest stable index. Initially, this is 0. 
3. **Updating the Window**: As we iterate through the array:
   - We update `maxSoFar` to include the current element.
   - We maintain `cMax`, which is the maximum value reached up to the index `cand`. This is necessary because the instability score at `cand` relies on the prefix maximum ending at `cand`, not the one at the current index `i`.
4. **Validation Logic**: If we find that `nums[i]` is smaller than `cMax - k`, it means that the current candidate (`cand`) is invalid. Why? Because the suffix minimum starting from `cand` will be at most `nums[i]`, and since `nums[i] < cMax - k`, the instability score (`cMax - min(suffix)`) would exceed `k`.
5. **Advancing**: When an invalid condition is found, we move our `cand` pointer to `i + 1` and reset `cMax` to the new `maxSoFar`. If we finish the loop and `cand` is still within the bounds of the array, `cand` is our answer; otherwise, no stable index exists, so we return -1.

### Complexity Analysis

*   **Time Complexity**: $O(n)$, where $n$ is the length of the `nums` array. We perform a single pass through the array, and every operation inside the loop (comparisons and assignments) takes constant time.
*   **Space Complexity**: $O(1)$. We only use a few integer variables (`maxSoFar`, `cand`, `cMax`) regardless of the input size, meaning the memory usage remains constant.
