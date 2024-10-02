// 3. Given two polynomials represented by two arrays, write a function that adds given

#include <stdio.h>
int main()
{
    int n, m;
    printf("Enter size of polynomial A: ");
    scanf("%d", &n);
    printf("Enter size of polynomial B: ");
    scanf("%d", &m);
    int A[n], B[m];
    printf("Enter coefficients of polynomial A: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("Enter coefficients of polynomial B: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &B[i]);
    if (n > m)
    {
        int Sum[n];
        for (int i = 0; i < n; i++)
        {
            Sum[i] = A[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    Sum[i] = Sum[i] + B[j];
                }
            }
        }
        printf("\nSum of coefficients of Polynomial A & B:  ");
        for (int k = 0; k < n; k++)
        {
            printf("%d ", Sum[k]);
        }
    }
    else
    {
        int Sum[m];
        for (int i = 0; i < m; i++)
        {
            Sum[i] = B[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    Sum[i] = A[i] + B[j];
                }
            }
        }
        printf("\nSum of coefficients of Polynomial A & B:  ");
        for (int k = 0; k < m; k++)
        {
            printf("%d ", Sum[k]);
        }
    }
}