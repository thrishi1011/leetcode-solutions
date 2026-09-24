# Smallest Index With Digit Sum Equal to Index

**Difficulty:** Easy | **Language:** cpp

### Approach
To solve this problem, we iterate through the array from left to right, checking each index to see if it satisfies the given condition. For every element at index `i`, we calculate the sum of its digits using a helper function. By comparing this sum to the current index `i`, we can identify the first (smallest) index that meets the requirement. If we finish the entire loop without finding a match, we return -1.

### Step-by-step explanation

1.  **Helper Function (`sumofdigits`)**: Since we need to calculate the sum of digits for various numbers, we create a small utility function. It uses the modulo operator (`% 10`) to extract the last digit of a number and adds it to a running total. We then divide the number by 10 (`/= 10`) to move to the next digit, repeating this process until the number becomes zero.
2.  **Iterating through the array**: We use a `for` loop to traverse the array `nums` starting from index 0 up to `nums.size() - 1`. Because we are moving linearly from the beginning of the array, the first index that satisfies our condition is guaranteed to be the smallest index.
3.  **Checking the condition**: Inside the loop, we pass the current element `nums[i]` into our helper function. We compare the returned sum to the loop's current index `i`.
4.  **Returning the result**: If the sum equals the index, we immediately return `i` as the answer. If the loop completes entirely without finding a match, it means no element satisfies the condition, so we return `-1`.

### Complexity Analysis

*   **Time Complexity**: $O(N \times D)$, where $N$ is the number of elements in the array and $D$ is the number of digits in the largest element. Since each element has at most 4 digits (as the constraint is `nums[i] <= 1000`), the digit-sum calculation is essentially constant time, making the overall complexity $O(N)$.
*   **Space Complexity**: $O(1)$. We only use a few integer variables to store the sum and the loop index, regardless of the size of the input array.
