# Smallest Divisible Digit Product I

**Difficulty:** Easy | **Language:** C++

# Solution: Smallest Divisible Digit Product I

### Approach Summary
The problem asks us to find the smallest integer starting from $n$ that satisfies a specific digit-based condition. Given the small constraints of the input ($n \le 100$), we can use a "brute-force" approach. We iterate through every integer starting from $n$ upwards, calculate the product of its digits for each number, and check if that product is evenly divisible by $t$. The first number we encounter that satisfies this condition is guaranteed to be our answer.

### Step-by-step Explanation

1.  **Helper Function (`product`)**: 
    To evaluate a number, we first need a way to calculate the product of its digits. We create a helper function that takes an integer `x`. Inside, we use a loop that repeatedly extracts the last digit using the modulo operator (`x % 10`), multiplies it into a running total (`prod`), and then removes that digit by dividing the number by 10 (`x /= 10`). This process continues until all digits have been processed.

2.  **Iterative Search**: 
    In the `smallestNumber` function, we initiate a `for` loop that starts at `n` and goes up to 100. Since the constraints state that $n$ is at most 100, we know the answer will not exceed a reasonable range, allowing us to safely check numbers one by one.

3.  **Checking the Condition**: 
    Inside the loop, we call our helper function for the current number `i`. We check if the resulting product is divisible by `t` using the condition `product(i) % t == 0`. 

4.  **Returning the Result**: 
    Because we are iterating in increasing order, the very first number that satisfies the `if` condition is mathematically guaranteed to be the smallest one. As soon as we find this match, we store it in `ans` and immediately `break` out of the loop, returning the result.

### Complexity Analysis

*   **Time Complexity**: $O(K \times D)$, where $K$ is the number of integers checked (at most 100) and $D$ is the number of digits in those integers (at most 3). Since $K$ and $D$ are very small constants, this effectively performs in constant time $O(1)$.
*   **Space Complexity**: $O(1)$. We only use a few integer variables to store the current product and loop index; we do not allocate any additional data structures that scale with the input size.
