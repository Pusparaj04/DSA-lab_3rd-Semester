//  WAP to Write a program to perform the following operations on a given square
// matrix using functions:
// i. Find the no.of nonzero elements
// ii. Display upper triangular matrix
// iii. Display the elements of just above and below the main diagonal

#include <stdio.h>

// Function to find the number of nonzero elements in the matrix
int count_nonzero_elements(int matrix[][10], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void display_upper_triangular_matrix(int matrix[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i > j)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to display the elements just above and below the main diagonal
void display_elements_around_diagonal(int matrix[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                // printf(" ");
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    int matrix[10][10];
    printf("\nEntering matrix elements...\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Enter the %d %d element of the matrix: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nDisplaying the matrix you've entered..\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Number of nonzero elements: %d\n", count_nonzero_elements(matrix, size));
    printf("Upper triangular matrix:\n");
    display_upper_triangular_matrix(matrix, size);
    printf("Elements just above and below the main diagonal:\n");
    display_elements_around_diagonal(matrix, size);

    return 0;
}