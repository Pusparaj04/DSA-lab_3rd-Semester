// 2. WAP to add two sparse matrix (using array). 

#include <stdio.h>
int main()
{
    int row, col;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of coumn: ");
    scanf("%d", &col);
    int sparse_mat1[row][col];
    int sparse_mat2[row][col];
    int count = 0;
    {
        printf("\nEntering sparse matrix 1...\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("Enter element [%d][%d]: ", i, j);
                scanf("%d", &sparse_mat1[i][j]);
            }
        }
        printf("\nEntering Sparse matrix 2...\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("Enter element [%d][%d]: ", i, j);
                scanf("%d", &sparse_mat2[i][j]);
            }
        }
    }
    {

        printf("\nDisplaying sparse matrix 1...\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d   ", sparse_mat1[i][j]);
            }
            printf("\n");
        }
        printf("\nDisplaying sparse matrix 2...\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d   ", sparse_mat2[i][j]);
            }
            printf("\n");
        }
    }
    int sparse_Sum[row][col];
    printf("\nDisplaying sum of sparse matrix...\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sparse_Sum[i][j] = sparse_mat1[i][j] + sparse_mat2[i][j];
            printf("%d   ", sparse_Sum[i][j]);
        }
        printf("\n");
    }

    int n = 0;
    int k = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (sparse_Sum[i][j] != 0)
            {
                count++;
            }
        }
    }
    n = count + 1;
    int tuple_Sum[n][3];

    tuple_Sum[0][0] = row;
    tuple_Sum[0][1] = col;
    tuple_Sum[0][2] = count;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (sparse_Sum[i][j] != 0)
            {
                tuple_Sum[k][0] = i;
                tuple_Sum[k][1] = j;
                tuple_Sum[k][2] = sparse_Sum[i][j];
                k++;
            }
        }
    }

    printf("\nDisplaying in 3-Tuple format...\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", tuple_Sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}