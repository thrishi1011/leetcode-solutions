# Detect Cycles in 2D Grid

**Difficulty:** Medium | **Language:** C++

# Solution: Detect Cycles in 2D Grid

### Approach
The problem is solved using **Depth-First Search (DFS)** to traverse the grid. We treat each set of connected identical characters as a graph where each cell is a node and edges exist between adjacent cells of the same value. A cycle exists if, during our traversal, we encounter a cell that has already been visited and is not the immediate parent of the current cell. By keeping track of the "parent" cell (the cell we just came from), we ensure we don't treat the move back to the previous cell as a cycle, satisfying the problem's movement constraints.

### Step-by-Step Explanation

1.  **Grid Traversal**: We iterate through every cell in the grid. If a cell hasn't been visited yet, we trigger a DFS starting from that cell. This ensures we check all connected components in the grid, even if they aren't linked to each other.
2.  **Maintaining State**: The `vis` matrix keeps track of which cells we have already processed. The `dfs` function receives the current coordinates `(r, c)` and the parent coordinates `(pr, pc)`. The parent coordinates are vital: they represent the cell we just arrived from, which we must ignore to avoid "bouncing" back and forth between two cells and falsely identifying that as a cycle.
3.  **Exploring Neighbors**: For every cell, we look at its four potential neighbors (up, down, left, right). We only proceed if:
    *   The neighbor is within the grid boundaries.
    *   The neighbor has the same character as the current cell.
4.  **Cycle Detection Logic**:
    *   **If the neighbor is unvisited**: We recursively call `dfs`. If that call eventually finds a cycle, we return `true` immediately.
    *   **If the neighbor is already visited**: We check if this neighbor is the same as our parent (`pr, pc`). If it is **not** the parent, it means we have reached a cell we have already seen through a different path. This confirms that a cycle exists.
5.  **Termination**: If we finish exploring all neighbors for a component without finding a cycle, we return `false` for that component and continue checking the rest of the grid.

### Complexity Analysis

*   **Time Complexity**: $O(M \times N)$, where $M$ is the number of rows and $N$ is the number of columns. Each cell is visited at most once by the DFS, and for each cell, we perform a constant number of operations (checking four neighbors).
*   **Space Complexity**: $O(M \times N)$. This accounts for the `vis` matrix used to store the visited state of every cell and the recursion stack, which in the worst-case scenario (e.g., a grid filled with the same character) could grow to the size of the entire grid.
