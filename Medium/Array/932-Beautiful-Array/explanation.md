# Beautiful Array

**Difficulty:** Medium | **Language:** C++

# Beautiful Array Solution Explanation

### Summary of Approach
The problem asks us to construct an array where no three elements form an arithmetic progression (i.e., $2 \times nums[k] = nums[i] + nums[j]$). The core insight is based on the properties of odd and even numbers: an odd number and an even number can never sum to an even number (which would be required to satisfy the arithmetic progression condition). By splitting the array into two halves—one containing all odd numbers and the other containing all even numbers—we ensure that no arithmetic progression can exist where one element is in the odd half and the other is in the even half. We can generate this recursively (or iteratively) by transforming an existing "beautiful" array of size $n$ into a beautiful array of size $2n$ using the linear transformation $2x - 1$ for odd numbers and $2x$ for even numbers.

### Step-by-Step Explanation

1.  **Base Case**: We start with the simplest possible beautiful array, which is `[1]`.
2.  **Iterative Growth**: Since we want to reach size $n$, we keep doubling our current array until its length meets or exceeds $n$. 
3.  **The Linear Transformation**: To create a larger beautiful array from a smaller one (`res`), we use two rules:
    *   **Odd Numbers**: Transform every number `i` in the current array to `2 * i - 1`. This generates a sequence of odd numbers. Because the original array was beautiful, this transformed version maintains those relative order properties and remains beautiful.
    *   **Even Numbers**: Transform every number `i` in the current array to `2 * i`. This generates a sequence of even numbers.
4.  **Combining**: By placing all the transformed odd numbers first and all the transformed even numbers second, we satisfy the condition. Because an odd number plus an even number always results in an odd number, the equation $2 \times nums[k] = nums[i] + nums[j]$ can never be solved if one element is odd and the other is even.
5.  **Filtering**: During each iteration, we check `if (i * 2 - 1 <= N)` and `if (i * 2 <= N)`. This ensures that as we grow the array, we don't accidentally include numbers greater than $N$. Once the loop finishes, we are left with a valid permutation of numbers from $1$ to $n$.

### Complexity

*   **Time Complexity**: $O(n \log n)$. In each step, we double the size of the array until we reach $N$. There are $\log n$ iterations, and in each iteration, we process the elements of the current array, leading to a total work proportional to $N \log N$.
*   **Space Complexity**: $O(n)$. We store the result array which contains $n$ elements, and the temporary array used during the construction also holds at most $n$ elements.
