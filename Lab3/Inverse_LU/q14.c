#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10   // Max matrix size

// Function to perform LU decomposition
int luDecomposition(double A[N][N], double L[N][N], double U[N][N], int n) {
    for (int i = 0; i < n; i++) {
        // Upper Triangular
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);
                if (U[i][i] == 0) return 0; // Singular matrix
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
    return 1;
}

// Forward substitution: solve LY = B
void forwardSubstitution(double L[N][N], double B[N], double Y[N], int n) {
    for (int i = 0; i < n; i++) {
        Y[i] = B[i];
        for (int j = 0; j < i; j++)
            Y[i] -= L[i][j] * Y[j];
    }
}

// Backward substitution: solve UX = Y
void backwardSubstitution(double U[N][N], double Y[N], double X[N], int n) {
    for (int i = n - 1; i >= 0; i--) {
        X[i] = Y[i];
        for (int j = i + 1; j < n; j++)
            X[i] -= U[i][j] * X[j];
        X[i] /= U[i][i];
    }
}

// Function to compute inverse using LU
void inverseMatrix(double A[N][N], double inverse[N][N], int n) {
    double L[N][N] = {0}, U[N][N] = {0};

    if (!luDecomposition(A, L, U, n)) {
        printf("Matrix is singular, inverse doesn't exist!\n");
        return;
    }

    // Solve AX = I column by column
    for (int i = 0; i < n; i++) {
        double e[N] = {0}, Y[N], X[N];
        e[i] = 1; // ith column of identity matrix

        forwardSubstitution(L, e, Y, n);   // LY = e
        backwardSubstitution(U, Y, X, n);  // UX = Y

        for (int j = 0; j < n; j++)
            inverse[j][i] = X[j]; // Store solution in inverse matrix
    }
}

// Print matrix
void printMatrix(double A[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%8.4f ", A[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    double A[N][N], inverse[N][N];

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    inverseMatrix(A, inverse, n);

    printf("\nInverse Matrix:\n");
    printMatrix(inverse, n);

    return 0;
}
