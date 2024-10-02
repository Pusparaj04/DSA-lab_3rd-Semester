#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new linked list node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list of size n
Node *createLinkedList(int n)
{
    Node *head = NULL;
    Node *current = NULL;
    int i;

    for (i = 1; i <= n; i++)
    {
        int data;
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        Node *newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// void insertNode(Node *head)
// {
//     Node *current = head;
//     int pos;
//     printf("Enter position to insert node: ");
//     scanf("%d", &pos);
//     int data;
//     printf("Enter data for new node: ", );
//     scanf("%d", &data);

//     Node *newNode = createNode(data);
//     for (int i = 1; i <= pos; i++)
//     {
//         current = current->next;
//     }
//     newNode->next = current;

// }

// Function to traverse and print the linked list
void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    int n;
    printf("Enter the length of the linked list: ");
    scanf("%d", &n);

    Node *head = createLinkedList(n);

    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}