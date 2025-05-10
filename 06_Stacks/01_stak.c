#include <stdio.h>
#include <stdlib.h>

#define MAX 4

// Function declarations
void push();
void pop();
void peep();
int isFull();
int isEmpty();

unsigned char stack[MAX];
int top = -1;

int main()
{
    int num;

    while (1)
    {
        printf("------------------------\n");
        printf("Enter 1 for Push\n");
        printf("Enter 2 for Pop\n");
        printf("Enter 3 Peep\n");
        printf("Enter 4 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num);

        switch (num)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}

// Function to push element onto stack
void push()
{
    int data;

    if (isFull())
    {
        printf("Stack Overflow! Cannot push more elements.\n");
    }
    else
    {
        printf("Enter data (0-255): ");
        scanf("%d", &data);

        if (data < 0 || data > 255)
        {
            printf("Invalid input! Only unsigned 8-bit values allowed.\n");
            return;
        }

        top++;
        stack[top] = (unsigned char)data;
        printf("Pushed %d to stack.\n", data);
    }
}

// Function to pop element from stack
void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! No elements to pop.\n");
    }
    else
    {
        printf("Popped %d from stack.\n", stack[top]);
        top--;
    }
}

// Function to display elements in the stack
void peep()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Current stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--)
        {
            printf("| %d |\n", stack[i]);
        }
    }
}

// Check if stack is full
int isFull()
{
    return top == MAX - 1;
}

// Check if stack is empty
int isEmpty()
{
    return top == -1;
}
