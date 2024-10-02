// 2. perform following operations using function on the single linked
// list:
// i. search an element in the list
// ii. sort the list in ascending order
// iii. reverse the list

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head)
{
    struct node *temp = *head;
    int num, pos;
    printf("Enter element: ");
    scanf("%d", &num);
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        struct node *begin = (struct node *)malloc(sizeof(struct node));
        begin->data = num;
        begin->next = *head;
        *head = begin;
    }
    else
    {
        for (int i = 2; i < pos; i++)
        {
            temp = temp->next;
        }
        struct node *end = (struct node *)malloc(sizeof(struct node));
        end->data = num;
        end->next = temp->next;
        temp->next = end;
    }
}

void delete(struct node **head)
{
    int delete;
    printf("Enter position of element to be deleted: ");
    scanf("%d", &delete);
    if (delete == 1)
    {
        struct node *del = *head;
        *head = (*head)->next;
        free(del);
    }
    else
    {
        struct node *temp = *head;
        for (int i = 2; i < delete; i++)
        {
            printf("%d : ", temp->data);
            temp = temp->next;
        }
        struct node *del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }
}

int count(struct node *head)
{
    int c = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

void traverse(struct node *head)
{
    printf("The list is : ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void search(struct node *head)
{
    int key;
    printf("Enter the element to be found ");
    scanf("%d", &key);
    int c = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        c++;
        if (temp->data == key)
        {
            printf("Element found at %d\n", c);
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

void sort(struct node *head)
{
    struct node *outer = head;
    while (outer->next != NULL)
    {
        struct node *inner = head;
        while (inner->next != NULL)
        {
            if (inner->data > inner->next->data)
            {
                int temp = inner->data;
                inner->data = inner->next->data;
                inner->next->data = temp;
            }
            inner = inner->next;
        }
        outer = outer->next;
    }
}

struct node *reverse(struct node *head)
{
    struct node *p = head;
    struct node *q = NULL;
    struct node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node *head = NULL;
    if (n >= 1)
    {
        struct node *n1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter data at node 1: ");
        scanf("%d", &n1->data);
        n1->next = NULL;
        head = n1;
    }
    struct node *temp = head;
    for (int i = 1; i < n; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data at node %d: ", (i + 1));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }

    int ch;
    printf("MENU:\n1. Insert the node at a position\n2. Delete a node from specific position\n3. Count\n4. Traversal\n5. Search\n6. Sort\n7. Reverse\n8. Exit\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(&head);
            break;

        case 2:
            delete (&head);
            break;

        case 3:
            printf("Number of nodes is %d\n", count(head));
            break;

        case 4:
            traverse(head);
            break;

        case 5:
            search(head);
            break;

        case 6:
            sort(head);
            break;

        case 7:
            head = reverse(head);
            break;

        default:
            printf("Exit\n");
        }

    } while (ch < 8);

    while (head != NULL)
    {
        struct node *del = head;
        head = head->next;
        free(del);
    }
}