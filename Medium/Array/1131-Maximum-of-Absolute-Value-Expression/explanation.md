# Maximum of Absolute Value Expression

**Difficulty:** Medium | **Language:** C++

# Maximum of Absolute Value Expression

### Approach
The problem asks us to maximize the expression $|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|$. Because the absolute value function $|x|$ can be rewritten as either $x$ or $-x$ depending on the sign of $x$, the expression can be expanded into eight possible variations. By observing symmetry, these eight variations reduce to four distinct linear combinations of the form $(\pm arr1[i] \pm arr2[i] \pm i) - (\pm arr1[j] \pm arr2[j] \pm j)$. To find the maximum value for each combination, we iterate through the arrays, calculate the value for every index $i$, and then simply subtract the minimum value from the maximum value found in that set.

### Step-by-step explanation

1.  **Deconstructing the Absolute Value:** 
    The expression includes three absolute value terms. When we remove these absolute value bars, each term $(arr1[i], arr2[i], i)$ can be either added or subtracted. Mathematically, the expression expands into:
    *   $(arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j)$
    *   $(arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)$
    *   $(arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)$
    *   $(arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j)$
    (The other four variations are just the negatives of these, which yield the same absolute range).

2.  **Transforming the Data:** 
    We create four temporary arrays (`temp1` through `temp4`). For every index $k$ in our input arrays, we compute the four linear combinations listed above. By storing these results, we transform a complex multi-variable problem into four simple "find the range" problems.

3.  **Finding the Maximum Difference:** 
    For any set of numbers, the maximum difference between any two elements is simply the `maximum element - minimum element`. We sort each of our temporary arrays (or alternatively, track the min and max in a single pass) to easily identify these values.

4.  **Final Result:** 
    After computing the maximum range for each of the four scenarios, we compare them and return the largest one. This value represents the maximum possible result for the original expression across all pairs $(i, j)$.

### Complexity Analysis

*   **Time Complexity:** $O(N \log N)$, where $N$ is the length of the arrays. We iterate through the arrays once to fill the temporary lists ($O(N)$), and then we sort each of the four temporary lists ($O(N \log N)$). 
    *Note: This can be optimized to $O(N)$ by finding the min and max of each list in a single pass instead of sorting.*
*   **Space Complexity:** $O(N)$, as we are creating four additional arrays of size $N$ to store our transformed values.
