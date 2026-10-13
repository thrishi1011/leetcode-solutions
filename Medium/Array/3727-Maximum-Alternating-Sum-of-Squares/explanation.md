# Maximum Alternating Sum of Squares

**Difficulty:** Medium | **Language:** cpp

# Maximum Alternating Sum of Squares

### Approach
To maximize the alternating score, we observe that every number in the array is squared, meaning the sign of the original number does not matter; we should treat all numbers as their absolute values. Since the formula alternates between adding squares and subtracting squares, we want to pair the largest possible numbers with the addition positions and the smallest possible numbers with the subtraction positions. The algorithm sorts the absolute values of the input in descending order and greedily assigns the largest available numbers to the addition slots and the smallest to the subtraction slots.

### Step-by-step Explanation

1. **Absolute Values**: Because every term in the score is squared (e.g., $x^2$), the original sign of any integer is irrelevant. We convert every number in the array to its absolute value to simplify our calculations.
2. **Determine Partitioning**: In the alternating sequence $a_0^2 - a_1^2 + a_2^2 - a_3^2 \dots$, the number of terms added is always greater than or equal to the number of terms subtracted. Specifically, if the array has $N$ elements, there will be `(N + 1) / 2` terms added. We calculate this count first.
3. **Sorting**: We sort the array of absolute values in descending order. By doing this, we ensure that the largest numbers are at the beginning of the list and the smallest are at the end.
4. **Greedy Assignment**:
    * **Additions**: We iterate through the sorted list and add the squares of the first `(N + 1) / 2` largest numbers to our total score. This maximizes the positive portion of the expression.
    * **Subtractions**: We take the remaining (smaller) numbers and subtract their squares from the total score. Since these numbers are the smallest available, subtracting them results in the least possible reduction to our total score.

### Complexity Analysis

* **Time Complexity: $O(N \log N)$**
  The dominant operation is sorting the input array, which takes $O(N \log N)$ time. The subsequent iterations through the array take $O(N)$ time.
  
* **Space Complexity: $O(N)$**
  We create a `temp` vector to store the sorted absolute values, which requires $O(N)$ space. Depending on the sorting implementation, additional stack space for recursion might be used, but the primary storage is linear.
