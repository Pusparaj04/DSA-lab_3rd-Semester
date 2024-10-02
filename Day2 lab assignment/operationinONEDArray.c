// (WAP to create a 1-D array of n elements and perform the following menu based
// operations using function. a. insert a given element at specific position. b. delete an element from a specific position of the array. c. linear search to search an element
// d. traversal of the array)

#include <stdio.h>

// Function to insert an element at a specific position
void insertElement(int *arr, int *n, int pos, int num)
{
    int i;
    if (pos < 0 || pos > *n)
    {
        printf("Invalid position\n");
    }
    else
    {
        // Shift elements to the right to make space for the new element
        for (i = *n - 1; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        // Insert the new element at the specified position
        arr[pos] = num;
        // Increment the size of the array
        (*n)++;
    }
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Function to delete an element from a specific position
void deleteElement(int *arr, int *n, int pos)
{
    int i;
    if (pos < 0 || pos >= *n)
    {
        printf("Invalid position\n");
    }
    else
    {
        // Shift elements to the left to fill the gap
        for (i = pos; i < *n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        // Decrement the size of the array
        (*n)--;
    }
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Function to perform linear search
int linearSearch(int *arr, int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i; // Return the position of the element
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to traverse the array
void traverseArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// exit
void finish(void)
{
    printf("\nExiting...\n");
}

int main()
{
    int n, pos, num, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    {
        printf("Menu:\n");
        printf("1. Insert an element at a specific position\n");
        printf("2. Delete an element from a specific position\n");
        printf("3. Linear search\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the position to insert the element: ");
            scanf("%d", &pos);
            printf("Enter the element to insert: ");
            scanf("%d", &num);
            insertElement(arr, &n, pos, num);
            break;
        case 2:
            printf("Enter the position to delete the element: ");
            scanf("%d", &pos);
            deleteElement(arr, &n, pos);
            break;
        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &num);
            pos = linearSearch(arr, n, num);
            if (pos != -1)
            {
                printf("Element found at position %d\n", pos);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 4:
            traverseArray(arr, n);
            break;
        case 5:
            finish();
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
