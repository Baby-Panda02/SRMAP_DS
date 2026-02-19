// Program to implement stack operations using array and functions

#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push();
void pop();
void peek();
void display();
void clearBuffer();

int main()
{
    int choice;

    while (1)
    {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Enter numbers only\n");
            clearBuffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Wrong choice\n");
        }
    }
}

void push()
{
    int x;

    if (top == SIZE - 1)
    {
        printf("Stack full\n");
        return;
    }

    printf("Enter value: ");
    if (scanf("%d", &x) != 1)
    {
        printf("Enter numbers only\n");
        clearBuffer();
        return;
    }

    stack[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        return;
    }

    printf("Deleted: %d\n", stack[top--]);
}

void peek()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        return;
    }

    printf("Top: %d\n", stack[top]);
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack empty\n");
        return;
    }

    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}
