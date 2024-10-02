// WAP to create a structure to store the information of n number of employees. Employee's information includes data members: Emp-id, Name,Designation, basic salary, hra%, da%. Display the information of employees with gross salary. Use array of structure.
// ------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct emp_info
{
    int Emp_id;
    char Name[20];
    char Designation[20];
    float Basic_salary;
    float Hra;
    float Da;
};
int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    printf("\n");
    struct emp_info emp[n] ;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of employee %d:\n\n", i + 1);
        printf("Enter the employee id: ");
        scanf("%d", &emp[i].Emp_id);
        printf("Enter the name: ");
        scanf("%s", &emp[i].Name);
        printf("Enter the designation: ");
        scanf("%s", &emp[i].Designation);
        printf("Enter the basic salary: ");
        scanf("%f", &emp[i].Basic_salary);
        printf("Enter the Hra percentage: ");
        scanf("%f", &emp[i].Hra);
        printf("Enter the Da percentage: ");
        scanf("%f", &emp[i].Da);
        printf("\n\n");
    }
    printf("\n\n\n");
    for (int i = 0; i < n; i++)
    {
        float Hra_amount = emp[i].Basic_salary * (emp[i].Hra / 100);
        float Da_amount = emp[i].Basic_salary * (emp[i].Da / 100);
        float Gross_salary = emp[i].Basic_salary + Hra_amount + Da_amount;
        printf("The details of employee %d:\n\n", i + 1);
        printf("Employee id: %d\n", emp[i].Emp_id);
        printf("Name: %s\n", emp[i].Name);
        printf("Designation: %s\n", emp[i].Designation);
        printf("Basic salary: %.2f\n", emp[i].Basic_salary);
        printf("Hra amount: %.2f\n", Hra_amount);
        printf("Da amount: %.2f\n", Da_amount);
        printf("Gross salary: %.2f\n", Gross_salary);
        printf("\n\n");
    }
}
