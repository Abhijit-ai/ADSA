## Dijkstra's Algorithm

### Problem Statement

This program implements Dijkstra's algorithm to find the shortest path from a single source vertex to all other vertices in a given weighted graph. The graph is represented using an adjacency matrix, and all edge weights are assumed to be non-negative.

### Related Algorithm: Dijkstra's Algorithm

Dijkstra's algorithm is a popular and efficient algorithm used to solve the single-source shortest path problem for a graph with non-negative edge weights. It finds the shortest paths from a starting node to all other nodes in the graph, producing a shortest-path tree.

**Key Concepts:**

*   **Weighted Graph**: A graph where each edge has a numerical value (weight) associated with it, representing a cost, distance, or time.
*   **Non-Negative Weights**: A critical constraint for Dijkstra's algorithm is that all edge weights must be non-negative. If negative weights are present, algorithms like Bellman-Ford or SPFA should be used.
*   **Greedy Approach**: Dijkstra's algorithm uses a greedy approach, always selecting the unvisited vertex with the smallest known distance from the source.

**Algorithm Steps:**

1.  **Initialization**:
    *   Assign a tentative distance value to every vertex: 0 for the source vertex and infinity (`INF`) for all other vertices.
    *   Mark all vertices as unvisited. Create a set of unvisited vertices.

2.  **Iteration**:
    *   While the set of unvisited vertices is not empty:
        *   Select an unvisited vertex `u` that has the smallest tentative distance value.
        *   Mark `u` as visited and remove it from the set of unvisited vertices.
        *   For each unvisited neighbor `v` of `u`:
            *   Calculate the distance from the source to `v` *through* `u` (`dist[u] + graph[u][v]`).
            *   If this calculated distance is less than the current tentative distance assigned to `v` (`dist[v]`), update `dist[v]` to the new, shorter distance. This process is called "relaxing" the edge.

3.  **Termination**: The algorithm terminates when all vertices have been visited, or when the smallest tentative distance among the unvisited vertices is infinity (meaning the remaining unvisited vertices are unreachable from the source). The `dist` array will then contain the shortest distances from the source to all other vertices.

### Code Details

The `q12.c` file implements Dijkstra's algorithm using an adjacency matrix to represent the graph.

*   **`V`**: A preprocessor macro defining the maximum number of vertices (set to 100).
*   **`INF`**: A large integer value (99999) representing infinity for initial distances.
*   **`minDistance(int dist[], int visited[], int n)`**: This helper function finds the vertex with the minimum distance value among the set of vertices not yet included in the shortest path tree.
    *   It iterates through all vertices.
    *   It checks if a vertex is unvisited (`!visited[v]`) and if its distance (`dist[v]`) is less than the current minimum.
    *   Returns the index of the vertex with the minimum distance.
*   **`dijkstra(int graph[V][V], int src, int n)`**: The core function that implements Dijkstra's algorithm.
    *   Initializes `dist` array (distances from source) to `INF` for all vertices and 0 for the `src`.
    *   Initializes `visited` array (shortest path tree set) to `0` (false) for all vertices.
    *   Iterates `n-1` times (as one vertex is the source, and we need to find `n-1` paths).
    *   In each iteration, it calls `minDistance` to get the unvisited vertex `u` with the smallest distance.
    *   Marks `u` as visited.
    *   Then, it relaxes the edges from `u` to all its unvisited neighbors `v`, updating `dist[v]` if a shorter path is found.
    *   Finally, it prints the shortest distances from the source to all vertices.

The `main` function:
1.  Prompts the user to enter the number of vertices (`n`).
2.  Prompts the user to enter the adjacency matrix of the graph. It uses `0` to denote no direct edge, which is then converted to `INF` internally, unless it's a self-loop (`i == j`).
3.  Prompts the user to enter the source vertex (`src`).
4.  Calls the `dijkstra` function to compute and print the shortest paths.

### Sample Input/Output

**Input:**

```
Enter number of vertices: 5
Enter adjacency matrix (use 0 for no edge):
0 10 0 0 5
0 0 1 0 0
0 0 0 4 0
0 0 0 0 0
0 0 9 2 0
Enter source vertex: 0
```
*(This represents a graph with 5 vertices. For instance, from vertex 0 to 1, the weight is 10; from 0 to 4, it's 5. No direct edge means `0` is entered for weight, which is then treated as infinity.)*

**Output:**

```
Vertex	Distance from Source
0	0
1	10
2	15
3	7
4	5
```
*(This output shows the shortest distance from source vertex 0 to each other vertex.)*