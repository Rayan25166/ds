#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Sparse {
    int row, col, value;
    int size; 
};


void inputSparseMatrix(struct Sparse *s, int rows, int cols) {
    int i, k = 0;
    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->size);
    
    printf("Enter row, column, and value for each non-zero element:\n");
    for (i = 0; i < s->size; i++) {
        printf("Element %d (row col value): ", i + 1);
        scanf("%d %d %d", &s->row, &s->col, &s->value);
        
        if (s->row >= rows || s->col >= cols) {
            printf("Invalid row or column index!\n");
            i--;
        }
    }
}


struct Sparse addSparseMatrix(struct Sparse *s1, struct Sparse *s2, struct Sparse *result) {
    int i = 0, j = 0, k = 0;
    
    
    if (s1->row != s2->row || s1->col != s2->col) {
        printf("Matrices cannot be added due to incompatible dimensions!\n");
        result->size = 0;
        return *result;
    }
    
    
    while (i < s1->size && j < s2->size) {
        if (k >= MAX) {
            printf("Result matrix overflow!\n");
            result->size = k;
            return *result;
        }
        
        if (s1->row < s2->row || (s1->row == s2->row && s1->col < s2->col)) {
            result[k].row = s1[i].row;
            result[k].col = s1[i].col;
            result[k].value = s1[i].value;
            i++;
        } else if (s1->row > s2->row || (s1->row == s2->row && s1->col > s2->col)) {
            result[k].row = s2[j].row;
            result[k].col = s2[j].col;
            result[k].value = s2[j].value;
            j++;
        } else {
            int sum = s1[i].value + s2[j].value;
            if (sum != 0) {
                result[k].row = s1[i].row;
                result[k].col = s1[i].col;
                result[k].value = sum;
                k++;
            }
            i++;
            j++;
        }
    }
    
    
    while (i < s1->size && k < MAX) {
        result[k].row = s1[i].row;
        result[k].col = s1[i].col;
        result[k].value = s1[i].value;
        i++;
        k++;
    }
    
    
    while (j < s2->size && k < MAX) {
        result[k].row = s2[j].row;
        result[k].col = s2[j].col;
        result[k].value = s2[j].value;
        j++;
        k++;
    }
    
    result->size = k;
    return *result;
}


struct Sparse transposeSparseMatrix(struct Sparse *s, struct Sparse *result) {
    int i;
    result->size = s->size;
    for (i = 0; i < s->size; i++) {
        result[i].row = s[i].col;
        result[i].col = s[i].row;
        result[i].value = s[i].value;
    }
    return *result;
}


void displaySparseMatrix(struct Sparse *s) {
    printf("Sparse Matrix (row, col, value):\n");
    for (int i = 0; i < s->size; i++) {
        printf("%d %d %d\n", s[i].row, s[i].col, s[i].value);
    }
}

int main() {
    struct Sparse s1[MAX], s2[MAX], sum[MAX], transpose[MAX];
    int rows, cols;
    
   
    printf("Enter number of rows and columns for matrices: ");
    scanf("%d %d", &rows, &cols);
    
    
    printf("\nFor first sparse matrix:\n");
    inputSparseMatrix(s1, rows, cols);
    
    
    printf("\nFor second sparse matrix:\n");
    inputSparseMatrix(s2, rows, cols);
    
    
    printf("\nSum of sparse matrices:\n");
    addSparseMatrix(s1, s2, sum);
    displaySparseMatrix(sum);
    
    
    printf("\nTranspose of sum matrix:\n");
    transposeSparseMatrix(sum, transpose);
    displaySparseMatrix(transpose);
    
    return 0;
}
