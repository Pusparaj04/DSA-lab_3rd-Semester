#include <stdio.h>
#define MAX_SIZE 12
int Queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(int element)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Overflow codition, enqueue is not possible!!");
        return;
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            Queue[rear] = element;
            printf("Enqueue %d successfully in queue.\n", element);
        }
        else
        {
            front = 0;
            rear++;
            Queue[rear] = element;
            printf("Enqueue %d successfully in queue.\n", element);
        }
    }
}
int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty, dequeue is not possible!!\n");
        return -1;
    }
    else
    {
        if (front == rear)
        {
            int temp = Queue[front];
            front = -1;
            rear = -1;
            return temp;
        }
        else
        {
            int temp = Queue[front];
            front++;
            return temp;
        }
    }
}
void isEmpty()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Queue is not Empty.\n");
    }
}
void isFull()
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is Full.\n");
    }
    else 
    {
        printf("Queue is not full.\n");
    }
    
}
void Traverse()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!\n");
        return;
    }
    else
    {
        printf("Printing Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice, element;
    printf("Queue operations: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. isEmpty\n");
    printf("4. isFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            element = dequeue();
            if (element != -1)
            {
                printf("Dequeue %d from queue\n", element);
            }
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            Traverse();
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\nPlease try again.\n");
        }
    }
    return 0;
}