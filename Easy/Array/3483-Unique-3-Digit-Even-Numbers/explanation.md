# Unique 3-Digit Even Numbers

**Difficulty:** Easy | **Language:** C++

# Unique 3-Digit Even Numbers

### Summary of Approach
The algorithm uses a frequency counting technique to determine how many valid 3-digit even numbers can be formed. Since the range of possible digits is small (0-9), we first count the occurrences of each digit in the input array. We then iterate through all possible 3-digit numbers (from 100 to 998) by nested loops representing the hundreds, tens, and units places. For each potential number, we verify if it can be formed by checking if the required count of each digit is available in our frequency array, ensuring we respect the constraints that each digit can only be used as many times as it appears in the input.

### Step-by-Step Explanation

1.  **Count Digit Frequencies**: We initialize an array `f` of size 10 to store the frequency of each digit (0-9) present in the input. This allows us to quickly check if a specific digit is available and how many times we can use it.
2.  **Iterate Through All Possible Numbers**: We use three nested loops to test every possible combination of digits:
    *   **The Hundreds Place (`i`)**: Ranges from 1 to 9. We start at 1 because a 3-digit number cannot have a leading zero.
    *   **The Tens Place (`j`)**: Ranges from 0 to 9.
    *   **The Units Place (`k`)**: Ranges from 0 to 8, incrementing by 2 (0, 2, 4, 6, 8). This ensures that every number we test is automatically even.
3.  **Validate Digit Availability**: Inside the nested loops, we check if the current combination `(i, j, k)` is valid. We compare the number of times each digit is needed against the frequency count `f`:
    *   We need `f[i]` to be at least 1.
    *   If `j` is the same as `i`, we need at least 2 copies of that digit.
    *   If `k` matches `i` or `j`, we need even more copies of that digit. 
    *   The logic `f[j] > (i == j)` and `f[k] > (i == k) + (j == k)` concisely calculates if the remaining supply of a digit is sufficient after accounting for the digits already "used" in the previous positions of the number.
4.  **Accumulate Results**: If the conditions are met, the number is valid, and we increment our result counter `res`.

### Complexity Analysis

*   **Time Complexity**: **O(1)**. Although there are three nested loops, they always iterate a constant number of times (9 × 10 × 5 = 450 iterations). Since the number of operations does not grow with the input size (beyond the initial frequency count which is capped at 10), the time complexity is constant.
*   **Space Complexity**: **O(1)**. We use a fixed-size array of 10 integers to store digit frequencies, which takes a constant amount of space regardless of the input size.
