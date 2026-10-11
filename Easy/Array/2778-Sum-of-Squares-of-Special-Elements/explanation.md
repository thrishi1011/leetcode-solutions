# Sum of Squares of Special Elements 

**Difficulty:** Easy | **Language:** cpp

# Sum of Squares of Special Elements Solution

### Approach
The problem asks us to identify "special" elements based on their index and calculate the sum of their squares. Since the array is 1-indexed, an element at index `i` (0-indexed in code) is special if the total length `n` is divisible by `i + 1`. We use a simple linear traversal (a `for` loop) to visit every element in the array once. For each element, we perform a modulo operation to check the divisibility condition. If the condition is met, we square the value and add it to our running total.

### Step-by-step Explanation
1. **Initialize the result:** We start by creating an integer variable `ans` initialized to 0. This will act as our accumulator to keep track of the sum of the squares.
2. **Determine array length:** We store the size of the input vector `nums` in a variable `n`. This value is essential because the definition of a "special" element depends on dividing `n` by the current index.
3. **Iterate through the array:** We use a loop to check every element. Since the problem uses 1-based indexing for the definition (where index 1 is the first element), but our C++ vector uses 0-based indexing, we look at the element at position `i` and test if `n` is divisible by `i + 1`. 
4. **The Modulo Check:** The expression `n % (i + 1) == 0` checks if `i + 1` is a divisor of `n`. If the remainder is 0, the current element is "special."
5. **Accumulate squares:** If the condition in the previous step is true, we multiply the element by itself (`nums[i] * nums[i]`) and add the result to `ans`.
6. **Return the result:** Once the loop has finished checking all elements, we return `ans`, which now holds the total sum of squares of all identified special elements.

### Complexity Analysis
*   **Time Complexity: O(n)**
    We iterate through the entire array of size `n` exactly once. Inside the loop, the modulo operation, multiplication, and addition are all constant-time $O(1)$ operations, resulting in linear time complexity.
*   **Space Complexity: O(1)**
    We only use a few integer variables (`ans`, `i`, `n`) to keep track of our calculation, regardless of how large the input array is. Therefore, the extra space used is constant.
