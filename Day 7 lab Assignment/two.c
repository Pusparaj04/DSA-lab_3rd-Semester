// Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,
// IsEmpty, Traverse using single linked list.
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct Queue
{
    struct node *front;
    struct node *rear;
} Queue;
void enqueue(Queue *queue, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
int dequeue(Queue *queue)
{
    if (queue->front == NULL && queue->rear == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        if (queue->front == queue->rear)
        {
            int temp = queue->front->data;
            queue->front = NULL;
            queue->rear = NULL;
            return temp;
        }
        else
        {
            int temp = queue->front->data;
            queue->front = queue->front->next;
            return temp;
        }
    }
}
void isEmpty(Queue *queue)
{
    if (queue->front == NULL && queue->rear == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }
}
void traverse(Queue *queue, Queue *tempQ)
{
    tempQ->front = queue->front;
    while (tempQ->front != queue->rear)
    {
        printf("%d ", tempQ->front->data);
        tempQ->front = tempQ->front->next;
    }
    printf("%d\n", queue->rear->data);
}
int main()
{
    Queue queue;
    Queue tempQ;
    queue.front = NULL;
    queue.rear = NULL;
    int choice, value;
    printf("Queue operations: \n");
    printf("1) Enqueue\n");
    printf("2) Dequeue\n");
    printf("3) isEmpty\n");
    printf("4) Traverse\n");
    printf("5) Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(&queue, value);
            break;
        case 2:
            value = dequeue(&queue);
            if (value != -1)
            {
                printf("Dequeued value: %d from queue\n", value);
            }
            break;
        case 3:
            isEmpty(&queue);
            break;
        case 4:
            traverse(&queue, &tempQ);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again!!");
        }
    }
}