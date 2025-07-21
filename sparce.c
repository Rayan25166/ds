#include <stdio.h>

int main() {
    int r1, c1, n1,r2, c2, n2,i;
    printf("Enter rows, columns and number of non-zero elements of Matrix 1: ");
    scanf("%d %d %d", &r1, &c1, &n1);
    int mat1[3][100];
    printf("Enter the elements (row column value) of Matrix 1:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d %d %d", &mat1[0][i], &mat1[1][i], &mat1[2][i]);
    }
    printf("Enter rows, columns and number of non-zero elements of Matrix 2: ");
    scanf("%d %d %d", &r2, &c2, &n2);
    int mat2[3][100];
    printf("Enter the elements (row column value) of Matrix 2:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d %d %d", &mat2[0][i], &mat2[1][i], &mat2[2][i]);
    }
    if (r1 != r2 || c1 != c2) {
        printf("Error: Matrices dimensions do not match for addition.\n");
        return 1;
    }
    printf("\nSparse Matrix 1 (row column value):\n");
    for(i = 0; i < n1; i++) {
        printf("%d %d %d\n", mat1[0][i], mat1[1][i], mat1[2][i]);
    }
    printf("\nSparse Matrix 2 (row column value):\n");
    for(i = 0; i < n2; i++) {
        printf("%d %d %d\n", mat2[0][i], mat2[1][i], mat2[2][i]);
    }
    int res[3][200];
    int i1 = 0, i2 = 0, k = 0;
    while(i1 < n1 && i2 < n2) {
        int r1_pos = mat1[0][i1];
        int c1_pos = mat1[1][i1];
        int r2_pos = mat2[0][i2];
        int c2_pos = mat2[1][i2];
        if (r1_pos < r2_pos || (r1_pos == r2_pos && c1_pos < c2_pos)) {
            res[0][k] = r1_pos;
            res[1][k] = c1_pos;
            res[2][k] = mat1[2][i1];
            i1++; k++;
        } else if (r2_pos < r1_pos || (r2_pos == r1_pos && c2_pos < c1_pos)) {
            res[0][k] = r2_pos;
            res[1][k] = c2_pos;
            res[2][k] = mat2[2][i2];
            i2++; k++;
        } else {
            int summed = mat1[2][i1] + mat2[2][i2];
            if (summed != 0) { 
                res[0][k] = r1_pos;
                res[1][k] = c1_pos;
                res[2][k] = summed;
                k++;
            }
            i1++; i2++;
        }
    }
    while(i1 < n1) {
        res[0][k] = mat1[0][i1];
        res[1][k] = mat1[1][i1];
        res[2][k] = mat1[2][i1];
        i1++; k++;
    }
    while(i2 < n2) {
        res[0][k] = mat2[0][i2];
        res[1][k] = mat2[1][i2];
        res[2][k] = mat2[2][i2];
        i2++; k++;
    }
    printf("\nSum of Sparse Matrices (row column value):\n");
    for(i = 0; i < k; i++) {
        printf("%d %d %d\n", res[0][i], res[1][i], res[2][i]);
    }
    return 0;
}
