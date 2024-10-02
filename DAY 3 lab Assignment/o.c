// 1. WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
#include <stdio.h>
int main()
{
    int row, col;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of coumn: ");
    scanf("%d", &col);
    int sparse_mat[row][col];
    int count = 0;
    printf("\nEntering sparse matrix...\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &sparse_mat[i][j]);
        }
    }
    printf("\nDisplaying sparse matrix...\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", sparse_mat[i][j]);
        }
        printf("\n");
    }
    int n = 0;
    int k = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (sparse_mat[i][j] != 0)
            {
                count++;
            }
        }
    }
    n = count + 1;
    int tuple_mat[n][3];

    tuple_mat[0][0] = row;
    tuple_mat[0][1] = col;
    tuple_mat[0][2] = count;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (sparse_mat[i][j] != 0)
            {
                tuple_mat[k][0] = i;
                tuple_mat[k][1] = j;
                tuple_mat[k][2] = sparse_mat[i][j];
                k++;
            }
        }
    }

    printf("\nDisplaying in 3-Tuple format...\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", tuple_mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
