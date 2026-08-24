#include <stdio.h>

int main() {
    int rows, cols;

    // Get matrix dimensions from the user
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    int transpose[cols][rows]; // Flipped dimensions for the transpose matrix

    // Input original matrix elements
    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Core logic: Compute the transpose matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }

    // Display the transposed matrix
    printf("\nTranspose of the Matrix:\n");
    for (int i = 0; i < cols; i++) {       // Loop runs up to 'cols'
        for (int j = 0; j < rows; j++) {   // Loop runs up to 'rows'
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
