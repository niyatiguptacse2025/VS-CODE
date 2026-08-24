#include <stdio.h>

int main() {
    int rows, cols, i, j;
    
    // Arrays to store the matrices. Size 100x100 acts as a safe upper bound.
    int matrix1[100][100], matrix2[100][100], sum[100][100];

    // 1. Get matrix dimensions from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // 2. Input elements for the first matrix
    printf("\nEnter elements of the 1st matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // 3. Input elements for the second matrix
    printf("\nEnter elements of the 2nd matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // 4. Perform element-wise addition
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // 5. Display the resultant sum matrix
    printf("\nResultant Matrix (Sum):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", sum[i][j]); // '\t' creates clean column spacing
        }
        printf("\n"); // Moves to the next row
    }

    return 0;
}
