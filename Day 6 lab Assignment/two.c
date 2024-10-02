// 6.2) write a menu driven program in C to create a stack using linked list and perform the following operation using function a. Push b. Pop c. IsEmpty d. display the stack elements

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void push(Stack *stack, int element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", element);
}

int pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    int element = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return element;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void displayStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    Node *temp = stack->top;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Stack stack;
    stack.top = NULL;

    int choice, element;
    printf("Stack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Check if stack is empty\n");
    printf("4. Display stack elements\n");
    printf("5. Exit\n");

    while (1)
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(&stack, element);
            break;
        case 2:
            element = pop(&stack);
            if (element != -1)
            {
                printf("Popped %d from the stack.\n", element);
            }
            break;
        case 3:
            if (isEmpty(&stack))
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Stack is not empty.\n");
            }
            break;
        case 4:
            displayStack(&stack);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}