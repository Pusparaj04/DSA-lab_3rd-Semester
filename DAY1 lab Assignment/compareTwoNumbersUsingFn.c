// WAP a program to read two numbers using function call by address.
#include <stdio.h>
#include <stdlib.h>
int compare(int *, int *);
int main()

{
    int a, b, *pa, *pb;
    pa = &a;
    pb = &b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    return compare(&a, &b);
}
int compare(int *pa, int *pb)
{
   
    if (*pa > *pb)
    {
        printf("%d is greater than %d.\n", *pa, *pb );
    }
    else
    {
        printf("%d is smaller than %d.\n", *pa, *pb);
    }
}