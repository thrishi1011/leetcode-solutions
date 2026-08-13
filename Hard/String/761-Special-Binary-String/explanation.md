# Special Binary String

**Difficulty:** Hard | **Language:** cpp

# Special Binary String Solution

### Approach
The problem asks us to find the lexicographically largest string by swapping adjacent "special" substrings. A special binary string is essentially equivalent to a balanced set of parentheses (where '1' is an opening bracket and '0' is a closing bracket). Because these substrings can be nested, we can treat the problem as a recursive decomposition: any special string can be broken down into a sequence of smaller, independent special substrings. By recursively finding the largest version of each inner component and then sorting all top-level special substrings in descending lexicographical order, we ensure the largest possible values appear at the beginning of the string.

### Step-by-Step Explanation

1.  **Decomposition into Substrings**: A special binary string is made up of multiple "mountain-like" components. We iterate through the string, keeping a `balance` counter (increment for '1', decrement for '0'). Every time the balance returns to zero, we have identified a complete, top-level special substring.
2.  **Recursive Processing**: Once we identify a segment, we know it starts with '1' and ends with '0'. To make this segment as large as possible, we recursively call the function on the content *inside* the outer '1' and '0'. By sorting the components found inside recursively, we optimize the inner structure before finalizing the current segment.
3.  **Constructing the Pieces**: For each independent component found, we wrap the processed inner content with a '1' at the start and a '0' at the end. We store these transformed components in a list.
4.  **Sorting for Lexicographical Maximization**: Lexicographical order means "11" is larger than "10". To achieve the largest total string, we sort the list of these special components in descending order (`greater<string>`). 
5.  **Reassembly**: Finally, we concatenate the sorted components. Because each component is already internally optimized and we have placed the largest components as early as possible in the sequence, the resulting concatenation is the lexicographically largest permutation possible.

### Complexity Analysis

*   **Time Complexity**: $O(N^2 \log N)$, where $N$ is the length of the string. In the worst case, we decompose the string into many small substrings at each level of recursion. The sorting step takes $O(K \log K)$ where $K$ is the number of substrings, and string comparisons/concatenations can take up to $O(N)$. Given the constraints ($N \le 50$), this approach is well within the efficient range.
*   **Space Complexity**: $O(N^2)$. We store the decomposed substrings in a vector and use the system call stack for recursion. In the worst case of highly nested strings, the recursion depth and the memory used to store intermediate substrings results in quadratic space usage relative to the input length.
