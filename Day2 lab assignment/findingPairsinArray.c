// 2. WAP to find the number of pair of elements in the given array, whose sum is
// equal to k, given array arr and an integer k.

#include <stdio.h>
int main()
{
    int count = 0;
    int n;
    int k;

    printf("Enter the number of element in array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    // printf("Traversing provided array: ");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d  ", arr[i]);
    // }
    // printf("\n");
    printf("Enter the value of k: ");
    scanf("%d", &k);
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if (i != j && j > i && arr[i] + arr[j] == k)
            {
               count = count + 1;
            }
        
        }
    }
    printf("\n");
    printf("Number of pairs of elements in the array whose sum is equal to k is: %d", count);
    return 0;
}