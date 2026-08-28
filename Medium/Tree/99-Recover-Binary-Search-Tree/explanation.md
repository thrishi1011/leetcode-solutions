# Recover Binary Search Tree

**Difficulty:** Medium | **Language:** C++

# Recover Binary Search Tree

### Summary
The core insight for this problem is that an **in-order traversal** of a valid Binary Search Tree (BST) always results in a sorted sequence of node values. When two nodes are swapped, the sequence becomes "out of order" at exactly two points. By performing an in-order traversal and keeping track of the previous node visited, we can identify these anomalies. Specifically, whenever we encounter a node that is smaller than its predecessor, we have found a violation. The first node of the first violation and the second node of the last violation are the two nodes that need to be swapped to restore the tree's order.

### Step-by-step Explanation

1.  **Preparation**: We define three pointers: `first` and `second` to store the two nodes that were swapped, and `prev` to track the node we visited immediately before the current one during our traversal. We initialize `prev` with a very small value (`INT_MIN`) so that the very first node in the tree is always considered "larger" than its predecessor.
2.  **In-order Traversal**: We traverse the tree using the standard recursive in-order approach (Left -> Root -> Right). This ensures we visit nodes in non-decreasing order.
3.  **Detecting Swaps**: During the traversal, we compare the current node’s value with the `prev` node's value:
    *   If `root->val < prev->val`, we know we've found a "mistake" because the sequence should be strictly increasing.
    *   If `first` is still null, this current violation must involve the `prev` node, so we mark `first = prev`.
    *   Regardless of whether `first` was already set, the current `root` is always a candidate for the `second` node involved in the swap. By updating `second` every time we find a violation, we ensure that in a case where the two swapped nodes are adjacent, we capture the correct pair, and in cases where they are far apart, we capture the beginning of the first error and the end of the second error.
4.  **Recovery**: After the traversal finishes, `first` and `second` point to the two nodes that were swapped incorrectly. We simply swap their values to restore the integrity of the BST.

### Complexity Analysis

*   **Time Complexity**: **O(N)**, where N is the number of nodes in the tree. We visit each node exactly once during the in-order traversal.
*   **Space Complexity**: **O(H)**, where H is the height of the tree. This space is used by the recursion stack. In the worst case (a skewed tree), this is O(N), but for a balanced tree, it is O(log N). 
    *   *Note: While the follow-up asks for O(1) auxiliary space, the recursive approach provided uses O(H) stack space. To achieve O(1) space, one would use Morris Traversal, which uses threads to link nodes and avoids the recursion stack.*
