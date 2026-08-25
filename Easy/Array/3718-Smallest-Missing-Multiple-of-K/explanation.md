# Smallest Missing Multiple of K

**Difficulty:** Easy | **Language:** cpp

# Solution: Smallest Missing Multiple of K

### Approach
The problem asks us to find the first positive multiple of $k$ that does not exist within the given array. Since we don't know how large the missing number might be, we use a "brute-force" search approach. We generate multiples of $k$ in increasing order ($k, 2k, 3k, \dots$) and, for each one, perform a linear scan through the input array to check if it exists. The first multiple that fails to appear in the array is our answer, and we return it immediately.

### Step-by-Step Explanation

1.  **Initialize a multiplier:** We start with a multiplier `i = 1`. This allows us to generate multiples sequentially: first $1 \times k$, then $2 \times k$, and so on.
2.  **Generate a candidate:** In each iteration of the `while` loop, we calculate `target = i * k`. This represents the current multiple of $k$ we are testing.
3.  **Search the array:** We use a `for` loop to iterate through every element in `nums`. We check if any element is equal to our `target`.
    *   If we find the `target` inside the array, we set a flag `found` to `true` and stop searching the rest of the array (using `break`) because we only need to know if the number exists at least once.
4.  **Check the result:** After checking the entire array, we look at the `found` flag. If it remains `false`, it means our `target` is missing from the list. Since we are checking multiples in increasing order, this must be the *smallest* missing multiple, so we return it.
5.  **Increment:** If the number was found, we increment `i` and repeat the process to check the next multiple.

### Complexity Analysis

*   **Time Complexity: $O(N \times M)$**
    *   $N$ is the number of elements in `nums` and $M$ is the number of multiples we check until we find the missing one. In the worst case, we might scan the entire array for each multiple until we exceed the maximum value in the array. Given the constraints (values up to 100), this is highly efficient.
*   **Space Complexity: $O(1)$**
    *   We only use a few integer variables (`i`, `target`, `found`) regardless of the size of the input array, meaning the memory usage remains constant.
