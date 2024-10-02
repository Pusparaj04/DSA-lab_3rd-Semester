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
    printf("Enter the number of nodes: ");
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
        else
        {
            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;

            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                last->next = newNode;
            }

            last = newNode;
        }
    }

    printf("\nDisplaying Linked List: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }

    return 0;
}