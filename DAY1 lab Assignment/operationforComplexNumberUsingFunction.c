// Write a menu driven program to create a structure to represent a complex number and perform the following operation using function:
// i) addition of two complex number (call by value)
// ii) multiplication of two complex number (call by address)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ComplexNum
{
    int real;
    int imaginary;
};

void complex_Addition(int a, int b, int c, int d)
{
    int sum_real, sum_imaginary;
    sum_real = a + c;
    sum_imaginary = b + d;
    printf("Sum of two complex number is: %d + %di\n", sum_real, sum_imaginary);
}

void complex_Multiplication(int *e, int *f, int *g, int *h)
{
    int mul_real, mul_imaginary;
    mul_real = (*e * *g) - (*f * *h);
    mul_imaginary = (*e * *h) + (*f * *g);
    printf("Product of two complex number is: %d + %di\n", mul_real, mul_imaginary);
}

int main()
{
    int opt = 0;
    struct ComplexNum complexNum1, complexNum2;

    printf("Enter the First Complex number : \n");
    printf("Enter real part: ");
    scanf("%d", &complexNum1.real);
    printf("Enter imaginary part: ");
    scanf("%d", &complexNum1.imaginary);

    printf("Enter the Second Complex number : \n");
    printf("Enter real part: ");
    scanf("%d", &complexNum2.real);
    printf("Enter imaginary part: ");
    scanf("%d", &complexNum2.imaginary);

    printf("Enter 1 for Addtion and 2 for multiplication: ");
    scanf("%d", &opt);

    if (opt == 1)
    {
        complex_Addition(complexNum1.real, complexNum1.imaginary, complexNum2.real, complexNum2.imaginary);
    }
    else if (opt == 2)
    {
        complex_Multiplication(&complexNum1.real, &complexNum1.imaginary, &complexNum2.real, &complexNum2.imaginary);
    }
    else
    {
        printf("Please enter either 1 or 2");
    }

    return 0;
}
