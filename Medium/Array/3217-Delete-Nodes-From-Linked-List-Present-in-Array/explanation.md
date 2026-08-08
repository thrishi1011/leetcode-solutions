# Delete Nodes From Linked List Present in Array

**Difficulty:** Medium | **Language:** C++

# Solution: Delete Nodes From Linked List Present in Array

### Approach
The core strategy for this problem is to use a hash set for efficient lookups combined with a "dummy node" technique to traverse and modify the linked list. First, we store all the values from the `nums` array into an `unordered_set`. This allows us to check if a specific node's value needs to be deleted in constant $O(1)$ time. We then iterate through the linked list using two pointers: one tracking the current node and one tracking the previous node. If the current node's value exists in our set, we skip it by updating the previous node's `next` pointer to bypass the current node. Otherwise, we simply move forward.

### Step-by-step Explanation

1.  **Preparation (Hash Set):** We convert the `nums` vector into an `unordered_set`. Since the problem asks us to frequently check if a node's value exists in `nums`, using a set is much faster than searching through the vector repeatedly.
2.  **The Dummy Node:** Linked list problems can be tricky when the head of the list itself needs to be deleted. To simplify this, we create a `dummy` node and point its `next` to the `head` of the list. By doing this, we ensure that every actual node in the list has a "previous" node, allowing us to use the same deletion logic even if the first node of the list is removed.
3.  **Traversing and Deleting:** We maintain two pointers: `curr` (the node we are currently checking) and `prev` (the node immediately before it).
    *   **If the value is found:** If `curr->val` is in the set, it means the node should be deleted. We perform the deletion by setting `prev->next` to `curr->next`. This effectively "cuts" the current node out of the list. We then update `curr` to the new `next` node.
    *   **If the value is not found:** The node is safe to keep. We simply advance the `prev` pointer to `curr` and move `curr` one step forward to continue the traversal.
4.  **Final Result:** After the loop completes, all unwanted nodes have been bypassed. We return `dummy.next`, which points to the new head of the modified list.

### Complexity Analysis

*   **Time Complexity:** $O(N + M)$, where $N$ is the number of elements in `nums` and $M$ is the number of nodes in the linked list. We spend $O(N)$ time inserting elements into the set and $O(M)$ time traversing the list once.
*   **Space Complexity:** $O(N)$. This is the space required to store the `nums` array elements in the `unordered_set`. We do not use any significant extra space that scales with the size of the linked list itself.
