# Single Number

**Difficulty:** Easy | **Language:** C++

# Solution: Single Number

### Approach
To find the single number while meeting the requirement of linear time complexity and constant extra space, we utilize the **XOR (exclusive OR) bitwise operator**. The XOR operation has three key properties that make it perfect for this problem: any number XORed with 0 is itself (`a ^ 0 = a`), any number XORed with itself is 0 (`a ^ a = 0`), and XOR is commutative and associative (the order of operations does not matter). By XORing every number in the array together, all pairs will cancel each other out, leaving behind only the unique number.

### Step-by-Step Explanation
1. **Initialize a tracker:** We start by creating an integer variable named `result` and setting it to 0. This variable will store the cumulative XOR sum of all numbers in the array.
2. **Iterate through the array:** We use a range-based loop to visit every integer `val` in the input vector `nums`.
3. **Apply the XOR operation:** During each step of the loop, we update `result` by XORing it with the current value (`result ^= val`).
   - Because `a ^ a = 0`, every time we encounter a number that has appeared before, it effectively removes its own previous contribution from the `result`.
   - Because `a ^ 0 = a`, the very first time we see a number, it is stored in `result`. If we see it again, it cancels out to 0.
4. **Return the result:** Once the loop finishes, all duplicate pairs have neutralized each other, leaving only the single, non-repeating number stored in `result`.

### Complexity Analysis
*   **Time Complexity: O(n)**
    We perform a single pass through the array of size `n`, where each XOR operation is performed in constant time.
*   **Space Complexity: O(1)**
    We only use a single integer variable (`result`) to track the calculation, regardless of the input size, satisfying the constant extra space requirement.
