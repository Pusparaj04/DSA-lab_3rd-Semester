// 5.3) WAP in C to represent the given sparse matrix using header single linked list and display it.

#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a sparse matrix element
typedef struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int row, int col, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(Node **head, int row, int col, int value)
{
    Node *newNode = createNode(row, col, value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the sparse matrix in tuple form
void displaySparseMatrix(Node *head)
{
    while (head != NULL)
    {
        printf("%d  %d  %d\n ", head->row, head->col, head->value);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int rows, cols, numElements;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numElements);

    Node *head = NULL;

    for (int i = 0; i < numElements; i++)
    {
        int row, col, value;
        printf("Enter row, column, and value for element %d: ", i + 1);
        scanf("%d %d %d", &row, &col, &value);
        insertNode(&head, row, col, value);
    }

    printf("Sparse matrix in tuple form: ");
    displaySparseMatrix(head);

    return 0;
}