#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
int main()
{
    int n;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    struct node *head = NULL;
    struct node *last = NULL;
    for (int i = 1; i <= n; i++)
    {
        int data;
        printf("Enter value at node %d: ", i);
        scanf("%d", &data);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("\nMemory allocation failed!!!\n");
            return 1;
        }
        else if (head == NULL)
        {
            head = newNode;
            newNode->data = data;
            last = head;
            newNode->prev = NULL;
            newNode->next = NULL;
        }
        else
        {
            newNode->prev = last;
            newNode->data = data;
            newNode->next = NULL;
            last = newNode;
        }
    }
    //    last = head;
    struct node *temp = head;
    printf("\nDisplaying Linked List: ");
    while (temp->next != NULL)
    {
        
        printf("%d ", temp->data);
        temp = temp->next;
    }
}