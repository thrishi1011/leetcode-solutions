# Delete the Middle Node of a Linked List

**Difficulty:** Medium | **Language:** cpp

# Deleting the Middle Node of a Linked List

### Approach Summary
To delete the middle node, we must first locate it. Since we cannot access linked list elements by index, we use the "Fast and Slow Pointer" technique. By moving a "fast" pointer twice as quickly as a "slow" pointer, the slow pointer will naturally land on the middle node when the fast pointer reaches the end of the list. Once identified, we stop at the node immediately preceding the middle one and adjust its `next` pointer to skip over the middle node, effectively removing it from the chain.

### Step-by-Step Explanation

1.  **Handling Edge Cases:** Before performing any logic, we check if the list is empty or contains only one node. If it does, we return `nullptr` because there is no middle node to delete (or the only node is the middle node).
2.  **Finding the Middle (The Helper Function):** 
    *   We initialize two pointers, `slow` and `fast`, at the head of the list.
    *   We traverse the list, moving `slow` forward by one step and `fast` by two steps in each iteration.
    *   By the time `fast` reaches the end of the list, `slow` will be positioned at the middle index. We keep a counter (`pos`) to track this index so we know how many steps we need to take later to reach the deletion point.
3.  **Navigating to the Target:** In the main `deleteMiddle` function, we iterate from the start of the list to the node just before the middle node (at index `mid - 1`). Stopping at this node is crucial because it allows us to bridge the gap left by the middle node.
4.  **Performing the Deletion:** Once we are at the node before the middle, we update its `next` pointer to point to the middle node's `next` node. This "detaches" the middle node from the list.
5.  **Return:** Finally, we return the original `head` of the list, which now represents the shortened linked list.

### Complexity Analysis

*   **Time Complexity:** O(N), where N is the number of nodes in the linked list. We traverse the list once to find the middle node and then traverse it again to reach the node before the middle. Since these operations are linear, the complexity remains O(N).
*   **Space Complexity:** O(1). We only use a fixed number of extra pointers (`slow`, `fast`, `temp`) and an integer variable regardless of the input size, meaning the algorithm uses constant extra space.
