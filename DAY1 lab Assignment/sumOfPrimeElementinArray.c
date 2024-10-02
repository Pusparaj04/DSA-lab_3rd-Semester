// WAP to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime  element of the array using function and deallocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>
int prime(int);
int sumofPrime(int *, int);

int main()
{

    int *ptr;
    int n, sum;
    int i;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed!!!\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no. %d of this array: ", i+1);
        scanf("%d", &ptr[i]);
    }

    sum = sumofPrime(ptr, n);

    printf("Sum of Prime elements from the array: %d.\n", sum);

    // ***This line (33 to 36) will print the array element as the memory allocated is still belongs to it when compilation process reach here***
    // for (int i = 0; i < n; i++)
    // {
    //     printf("The elements of array are: %d.\n", ptr[i]);
    // }
    

    free(ptr);
    

    // **** But here we can observe line (42 to 45) will print any random element in that array (sometime it may print same element it occurs when that memory location still remain to over-write by other any value)****
    // for (int i = 0; i < n; i++)
    // {
    //     printf("The elements of array are: %d.\n", ptr[i]);
    // }

    return 0;
}
int prime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int sumofPrime(int *ptr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (prime(ptr[i]))
        {
            sum += ptr[i];
        }
    }
    return sum;
}
