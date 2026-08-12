# Length of Longest Subarray With at Most K Frequency

**Difficulty:** Medium | **Language:** C++

# Length of Longest Subarray With at Most K Frequency

### Approach Summary
This solution uses the **sliding window** technique (specifically a two-pointer approach) to find the longest valid subarray. We maintain a window defined by two pointers, `left` and `right`, and use a hash map to keep track of the frequency of each element within that window. As we expand the window by moving the `right` pointer, we check if the current element exceeds the allowed frequency `k`. If it does, the window becomes "invalid," so we contract it from the `left` until the frequency of that element is no longer greater than `k`. Throughout this process, we keep track of the maximum window size encountered.

### Step-by-Step Explanation

1.  **Initialize the Window:** We start with both `left` and `right` pointers at the beginning of the array. We also initialize an empty hash map (`freq`) to store the count of each number currently inside our window.
2.  **Expand the Window:** We iterate through the array using the `right` pointer. For every element we encounter, we add it to our `freq` map (or increment its existing count). This represents adding the element to our current "good" subarray.
3.  **Check for Validity:** After adding the element, we check if its frequency has crossed the limit `k`. If `freq[nums[right]] > k`, the subarray is no longer "good."
4.  **Contract the Window:** While the frequency of the current element is greater than `k`, we shrink the window from the left:
    *   Identify the element at the `left` pointer.
    *   Decrement its count in the `freq` map because it is being removed from the window.
    *   Move the `left` pointer forward by one.
    *   We repeat this until the frequency of the element that caused the violation drops back down to `k`.
5.  **Track the Maximum:** After the window is valid again, the current distance between `left` and `right` represents a valid subarray. We calculate its length (`right - left + 1`) and update our `max` variable if this length is larger than any we have found previously.

### Complexity Analysis

*   **Time Complexity:** **O(n)**, where *n* is the number of elements in `nums`. Although there is a `while` loop inside the `for` loop, each element is added to the hash map once and removed from the hash map at most once. Therefore, the pointers `left` and `right` each traverse the array only once.
*   **Space Complexity:** **O(m)**, where *m* is the number of unique elements in the input array. In the worst case, the hash map stores every unique number present in the array.
