//Name- Daksh Joshi   Enrollment number-01414002026
//12. WAP to accept a matrix from user, find out matrix is sparse or not and convert into triplex matrix.

#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    int count = 0;

    printf("Enter matrix elements:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
                count++;
        }
    }

    printf("\nEntered Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (count <= (rows * cols) / 2)
    {
        printf("\nIt is a Sparse Matrix\n");

        int triplet[count + 1][3];

        triplet[0][0] = rows;
        triplet[0][1] = cols;
        triplet[0][2] = count;

        int k = 1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    triplet[k][0] = i;
                    triplet[k][1] = j;
                    triplet[k][2] = matrix[i][j];
                    k++;
                }
            }
        }

        printf("\nTriplet Representation:\n");
        printf("Row Col Value\n");

        for (int i = 0; i <= count; i++) {
            printf("%3d %3d %3d\n",
                   triplet[i][0],
                   triplet[i][1],
                   triplet[i][2]);
        }
    }
    else
    {
        printf("\nIt is NOT a Sparse Matrix\n");
    }

    return 0;
}

