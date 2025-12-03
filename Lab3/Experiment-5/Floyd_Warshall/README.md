## Floyd-Warshall Algorithm

### Problem Statement

This program implements the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices in a given weighted graph. The graph is represented using an adjacency matrix, where direct edge weights are provided, and the algorithm computes the minimum travel cost or distance from any vertex to any other vertex.

### Related Algorithm: Floyd-Warshall Algorithm

The Floyd-Warshall algorithm is a dynamic programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph. It works for both directed and undirected graphs, provided they do not contain negative cycles. It's often referred to as an "all-pairs shortest path" algorithm.

**Key Concepts:**

*   **All-Pairs Shortest Path**: Finds the shortest distance from every vertex to every other vertex in the graph.
*   **Dynamic Programming**: The algorithm builds up a solution by considering intermediate vertices one by one. It iteratively improves distance estimates by considering whether going through an additional intermediate vertex `k` can shorten the path between any two vertices `i` and `j`.
*   **Negative Cycles**: The algorithm can correctly handle negative edge weights but will produce incorrect results if a negative cycle is present (a cycle where the sum of edge weights is negative). It can detect negative cycles if, after completion, any `dist[i][i]` is negative.

**Algorithm Steps:**

1.  **Initialization**:
    *   Create an `n x n` distance matrix, `dist`, which is a copy of the input `graph` adjacency matrix.
    *   For each pair `(i, j)`:
        *   If there is a direct edge from `i` to `j`, `dist[i][j]` is set to its weight.
        *   If `i == j`, `dist[i][j]` is 0.
        *   If there is no direct edge between `i` and `j`, `dist[i][j]` is set to `INF` (a very large number representing infinity).

2.  **Iteration (Core Algorithm)**:
    *   The algorithm uses three nested loops, where `k` iterates from `0` to `n-1` (representing the intermediate vertex), and `i` and `j` iterate from `0` to `n-1` (representing the source and destination vertices).
    *   For each combination of `i`, `j`, and `k`:
        *   `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
        *   This step checks if the path from `i` to `j` can be made shorter by passing through vertex `k`. If the current shortest path from `i` to `k` plus the current shortest path from `k` to `j` is less than the current shortest path from `i` to `j`, then `dist[i][j]` is updated.

3.  **Result**: After all `n` iterations for `k`, the `dist` matrix will contain the shortest path distances between all pairs of vertices.

**Time Complexity**: O(n³) due to the three nested loops, where `n` is the number of vertices.
**Space Complexity**: O(n²) to store the distance matrix.

### Code Details

The `q13.c` file implements the Floyd-Warshall algorithm:

*   **`INF`**: A preprocessor macro defining a large integer value (99999) representing infinity for non-existent edges.
*   **`MAX`**: A preprocessor macro defining the maximum number of vertices (set to 50).
*   **`floydWarshall(int n, int graph[MAX][MAX])`**: The core function.
    *   It takes the number of vertices `n` and the initial adjacency matrix `graph`.
    *   It initializes a `dist` matrix as a copy of `graph`.
    *   It then runs the three nested loops to compute all-pairs shortest paths.
    *   Finally, it prints the resulting `dist` matrix, replacing `INF` with the string "INF" for clarity.

The `main` function:
1.  Prompts the user to enter the number of vertices (`n`).
2.  Prompts the user to enter the adjacency matrix of the graph.
    *   If `i != j` and `graph[i][j]` is entered as `0`, it's interpreted as `INF` (no direct edge).
    *   Self-loops (`i == j`) entered as `0` remain `0`.
3.  Calls the `floydWarshall` function to compute and print the all-pairs shortest paths matrix.

### Sample Input/Output

**Input:**

```
Enter number of vertices: 4
Enter adjacency matrix (use 0 for no edge):
0 3 0 5
2 0 0 4
0 1 0 0
0 0 2 0
```
*(This represents a directed graph. For example, edge from 0 to 1 has weight 3, from 0 to 3 has weight 5, from 1 to 0 has weight 2, etc. `0` means no direct edge.)*

**Output:**

```
Shortest distance matrix:
  0   3   7   5
  2   0   6   4
  3   1   0   5
  5   3   2   0
```
*(This output shows the shortest distance from every vertex to every other vertex.)*