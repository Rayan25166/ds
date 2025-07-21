#include <stdio.h>

#define MAX 100

void readspars(int spars[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &spars[i][j]);
        }
    }
}

void sparsMatrix(int matrix[MAX][3], int rows, int cols, int spars[MAX][MAX]) {
    int i, j, k = 1;  
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(spars[i][j] != 0) {
                matrix[k][0] = i;
                matrix[k][1] = j;
                matrix[k][2] = spars[i][j];
                k++;
            }
        }
    }
    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = k - 1;  
}

void displaymatrix(int matrix[MAX][3], int rows) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addSparse(int a[MAX][3], int b[MAX][3], int result[MAX][3]) {
    int i = 1, j = 1, k = 1;
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Matrix dimensions do not match for addition.\n");
        result[0][2] = 0;
        return;
    }
    
    result[0][0] = a[0][0];
    result[0][1] = a[0][1];

    while(i <= a[0][2] && j <= b[0][2]) {
        if(a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++; k++;
        }
        else if(b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++; k++;
        }
        else {
            int summed = a[i][2] + b[j][2];
            if (summed != 0) {
                result[k][0] = a[i][0];
                result[k][1] = a[i][1];
                result[k][2] = summed;
                k++;
            }
            i++; j++;
        }
    }

    while(i <= a[0][2]) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }

    while(j <= b[0][2]) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;
}

int main() {
    int spars1[MAX][MAX], spars2[MAX][MAX];
    int matrix1[MAX][3], matrix2[MAX][3], result[MAX][3];
    int rows, cols;

    printf("Enter the number of rows of sparse matrices: ");
    scanf("%d", &rows);

    printf("Enter the number of columns of sparse matrices: ");
    scanf("%d", &cols);

    printf("Enter the elements of the first sparse matrix:\n");
    readspars(spars1, rows, cols);

    printf("Enter the elements of the second sparse matrix:\n");
    readspars(spars2, rows, cols);

    sparsMatrix(matrix1, rows, cols, spars1);
    sparsMatrix(matrix2, rows, cols, spars2);

    addSparse(matrix1, matrix2, result);

    printf("Resultant sparse matrix after addition:\n");
    displaymatrix(result, result[0][2] + 1);

    return 0;
}
