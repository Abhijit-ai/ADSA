## Simple Graph Input Format (SIF) Processor

### Problem Statement

This program is designed to read graph edge information provided in a specific text-based format (`node1 relation node2`) and convert it into an adjacency matrix representation. The "relation" part of the input is ignored; the program solely focuses on establishing a directed edge from `node1` to `node2`. The goal is to demonstrate how to parse such a format and construct a common graph data structure.

### Related Concept: Graph Representation (Adjacency Matrix)

A graph is a data structure consisting of a finite set of vertices (or nodes) and a set of edges connecting these vertices. Graphs are widely used to model relationships between entities.

One common way to represent a graph in computer memory is using an **Adjacency Matrix**.

*   **Definition**: An adjacency matrix is a square matrix used to represent a finite graph. The elements of the matrix indicate whether pairs of vertices are adjacent or not.
*   **Structure**: For a graph with `N` vertices, the adjacency matrix `A` will be an `N x N` matrix.
*   **Directed Graphs**: For a directed graph, if there is an edge from vertex `i` to vertex `j`, then the entry `A[i][j]` is 1 (or the weight of the edge if it's a weighted graph); otherwise, it is 0 (or infinity). Note that `A[i][j]` being 1 does not necessarily mean `A[j][i]` is also 1.
*   **Space Complexity**: O(V^2), where V is the number of vertices. This can be memory-intensive for sparse graphs (graphs with few edges).
*   **Time Complexity**: Checking if an edge exists between two vertices is O(1). Finding all neighbors of a vertex is O(V).

This program specifically handles a "Simple Input Format" where each line describes a directed relationship between two nodes. The output adjacency matrix will reflect these relationships, with `1` indicating a direct edge.

### Code Details

The `q11.c` file processes the custom SIF input to build an adjacency matrix:

*   **`MAX`**: A preprocessor macro defining the maximum number of vertices (100) and the maximum length for vertex names (20).
*   **`Vertex` struct**: A simple structure to hold the `name` of a vertex.
*   **`vertices[MAX]`**: A global array to store the `Vertex` objects, effectively mapping string names to integer indices.
*   **`adjMatrix[MAX][MAX]`**: A global 2D array representing the adjacency matrix, initialized to all zeros implicitly.
*   **`vertexCount`**: A global integer to keep track of the number of unique vertices found so far.
*   **`getIndex(char *name)`**: This crucial helper function maps a vertex name (string) to a unique integer index.
    *   It iterates through the `vertices` array to check if the `name` already exists. If so, it returns its index.
    *   If the `name` is new, it adds the name to the `vertices` array, increments `vertexCount`, and returns the new index.
*   **`main()` function**:
    1.  Prompts the user to enter edges in the format `node1 relation node2`.
    2.  Enters a loop that reads three strings (`v1`, `rel`, `v2`).
    3.  If `v1` is "END", the loop breaks.
    4.  It calls `getIndex` for `v1` and `v2` to get their corresponding integer indices (`i` and `j`).
    5.  It sets `adjMatrix[i][j] = 1`, indicating a directed edge from `i` to `j`. The `rel` string is read but not used.
    6.  After input termination, it prints the constructed adjacency matrix to the console. Each row corresponds to a source vertex, and each column to a destination vertex.

### Sample Input/Output

**Input:**

```
Enter edges in SIF format: node1 relation node2 (type END to stop)
A connected B
B relatesTo C
C knows A
END
```

**Output:**

```
Adjacency Matrix:
0 1 0
0 0 1
1 0 0
```
*(In this output, assuming A=0, B=1, C=2, the matrix shows edges (A->B), (B->C), and (C->A).)*