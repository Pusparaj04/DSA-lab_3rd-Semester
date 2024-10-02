// 6.3) Write a program in C to convert infix expression to postfix expression using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack
{
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char element)
{
    stack->data[++stack->top] = element;
}

char pop(Stack *stack)
{
    return stack->data[stack->top--];
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
    {
        return 1;
    }
    else if (operator== '*' || operator== '/')
    {
        return 2;
    }
    else if (operator == '^')
    {
        return 3;
    }
    
    else
    {
        return 0;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack stack;
    stack.top = -1;

    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (infix[i] == ' ')
        {
            i++;
            continue;
        }

        if (infix[i] >= '0' && infix[i] <= '9' || infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '(')
        {
            push(&stack, infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(')
            {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.data[stack.top] == '(')
            {
                pop(&stack);
            }
            i++;
        }
        else
        {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(' && precedence(infix[i]) <= precedence(stack.data[stack.top]))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
    }

    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}