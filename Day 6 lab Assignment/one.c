// 6.1) Write a menu driven program to create a stack using array and perform the following operation using function a. Push b. Pop c. check stack is empty or not d. check stack is full or not e. display stack elements

#include <stdio.h>

#define MAX_SIZE 9

int top = -1;
int stack[MAX_SIZE];

void push(int element)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full. Cannot push %d.\n", element);
        return;
    }
    stack[++top] = element;
    printf("Pushed %d onto the stack.\n", element);
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX_SIZE - 1;
}

void displayStack()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 1; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice, element;
    printf("Stack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Check if stack is empty\n");
    printf("4. Check if stack is full\n");
    printf("5. Display stack elements\n");
    printf("6. Exit\n");

    while (1)
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            if (element != -1)
            {
                printf("Popped %d from the stack.\n", element);
            }
            break;
        case 3:
            if (isEmpty())
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Stack is not empty.\n");
            }
            break;
        case 4:
            if (isFull())
            {
                printf("Stack is full.\n");
            }
            else
            {
                printf("Stack is not full.\n");
            }
            break;
        case 5:
            displayStack();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}