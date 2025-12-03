## Inverse of a Matrix using LU Decomposition

### Problem Statement

This program calculates the inverse of a given square matrix using its LU (Lower-Upper) Decomposition. Matrix inversion is a fundamental operation in linear algebra with applications in solving systems of linear equations, least squares optimization, and various scientific computations. This method is numerically stable and efficient compared to direct calculation for larger matrices.

### Related Algorithm: Matrix Inverse using LU Decomposition

To find the inverse of a square matrix `A`, denoted as `A⁻¹`, we need to find a matrix `A⁻¹` such that `A * A⁻¹ = I`, where `I` is the identity matrix. Using LU Decomposition, this problem can be efficiently solved by breaking it down into a series of simpler steps.

The overall algorithm consists of two main phases:

1.  **LU Decomposition**:
    *   The first step is to decompose the given matrix `A` into a lower triangular matrix `L` and an upper triangular matrix `U`, such that `A = LU`. This decomposition is achieved through a process similar to Gaussian elimination.
    *   In the context of this program, the diagonal elements of `L` are set to 1.
    *   If a pivot element during decomposition is zero, the matrix is singular, and its inverse does not exist.

2.  **Solving `A * A⁻¹ = I` for Each Column**:
    *   We can think of `A⁻¹` and `I` as collections of column vectors. Let `A⁻¹ = [x1, x2, ..., xn]` and `I = [e1, e2, ..., en]`, where `ei` is the `i`-th standard basis vector (a column vector with 1 at the `i`-th position and 0s elsewhere).
    *   Then, the problem `A * A⁻¹ = I` can be broken down into `n` separate systems of linear equations: `A * xi = ei` for `i = 1, ..., n`.
    *   Since `A = LU`, each system becomes `LU * xi = ei`. Each of these systems is solved in two steps:
        *   **Forward Substitution (`L * yi = ei`)**: First, an intermediate vector `yi` is found by solving the lower triangular system `L * yi = ei`. This is done using forward substitution, which is computationally inexpensive.
        *   **Backward Substitution (`U * xi = yi`)**: Next, the desired column `xi` of `A⁻¹` is found by solving the upper triangular system `U * xi = yi`. This is done using backward substitution, also an inexpensive operation.

By solving these `n` pairs of triangular systems, we construct all columns of `A⁻¹`, thus obtaining the inverse matrix.

### Code Details

The `q14.c` file implements the matrix inversion process using LU decomposition:

*   **`N`**: A preprocessor macro defining the maximum size of the square matrices (set to 10).
*   **`luDecomposition(double A[N][N], double L[N][N], double U[N][N], int n)`**:
    *   Takes the input matrix `A` and empty matrices `L` and `U` as parameters, along with the size `n`.
    *   It performs LU decomposition. The elements of `U` are calculated row by row, and the elements of `L` are calculated column by column.
    *   It explicitly sets the diagonal elements of `L` to 1.
    *   Returns `0` if the matrix is singular (a diagonal element of `U` becomes zero during calculation), `1` otherwise.
*   **`forwardSubstitution(double L[N][N], double B[N], double Y[N], int n)`**:
    *   Solves a lower triangular system `LY = B` for `Y`.
    *   It takes `L`, the right-hand side vector `B`, an empty solution vector `Y`, and size `n`.
*   **`backwardSubstitution(double U[N][N], double Y[N], double X[N], int n)`**:
    *   Solves an upper triangular system `UX = Y` for `X`.
    *   It takes `U`, the right-hand side vector `Y`, an empty solution vector `X`, and size `n`.
*   **`inverseMatrix(double A[N][N], double inverse[N][N], int n)`**:
    *   The main function for computing the inverse.
    *   It calls `luDecomposition` to get the `L` and `U` factors.
    *   If decomposition is successful, it iterates `n` times, each time creating a column of the identity matrix `e`.
    *   For each `e`, it calls `forwardSubstitution` to solve `Ly = e` for `Y`, and then `backwardSubstitution` to solve `Ux = Y` for `X`.
    *   The resulting `X` vector is stored as a column in the `inverse` matrix.
*   **`printMatrix(double A[N][N], int n)`**: A utility function to print a matrix.

The `main` function:
1.  Prompts the user to enter the order (`n`) of the square matrix.
2.  Takes input for the elements of matrix `A`.
3.  Calls `inverseMatrix` to compute the inverse of `A`.
4.  Prints the calculated `inverse` matrix.

### Sample Input/Output

**Input:**

```
Enter order of matrix: 3
Enter matrix elements:
1 2 0
3 4 4
5 6 3
```

**Output:**

```
Inverse Matrix:
  1.5000  -0.7500   0.6667
 -1.5000   0.7500  -0.3333
  0.0000   0.3333  -0.3333
```
*(You can verify this by multiplying the original matrix `A` by the calculated `inverse` matrix; the result should be close to the identity matrix.)*