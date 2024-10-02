// 3. Write a program to represent the polynomial equation of single
// variable using single linked list and
// perform the addition of two polynomial equations.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int num)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main()
{
    struct node *e1 = NULL, *e2 = NULL;
    int p1, p2;
    printf("Polynomial 1-\nEnter the Maximum power of x: ");
    scanf("%d", &p1);
    for (int x = p1; x >= 0; x--)
    {
        printf("Enter the coefficient of degree %d: ", x);
        int n;
        scanf("%d", &n);
        insert(&e1, n);
    }
    printf("\nPolynomial 2-\nEnter the Maximum power of x: ");
    scanf("%d", &p2);
    for (int x = p2; x >= 0; x--)
    {
        printf("Enter the coefficient of degree %d: ", x);
        int n;
        scanf("%d", &n);
        insert(&e2, n);
    }
    int diff = abs(p1 - p2);
    struct node *t2 = e2;
    struct node *t1 = e1;
    if (p2 > p1)
    {
        for (int i = 0; i < diff; i++)
        {
            t2 = t2->next;
        }
        while (t2 != NULL && t1 != NULL)
        {
            t2->data = (t2->data) + (t1->data);
            t2 = t2->next;
            t1 = t1->next;
        }
        t2 = e2;
        while (t2 != NULL)
        {
            printf("%dx^%d", t2->data, p2--);
            if (t2->next != NULL)
                printf(" + ");
            t2 = t2->next;
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            t1 = t1->next;
        }
        while (t2 != NULL && t1 != NULL)
        {
            t1->data = (t1->data) + (t2->data);
            t2 = t2->next;
            t1 = t1->next;
        }
        t1 = e1;
        while (t1 != NULL)
        {
            printf("%dx^%d", t1->data, p1--);
            if (t1->next != NULL)
                printf(" + ");
            t1 = t1->next;
        }
        printf("\n");
    }
}
