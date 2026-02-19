
// Menu-driven program for Stack (LL) and Queue (Array & LL) with safe input handling

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/* -------- Utility -------- */
void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

/* -------- STACK USING LINKED LIST -------- */

struct stackNode
{
    int data;
    struct stackNode *next;
};

struct stackNode *top = NULL;

void stackMenu()
{
    int ch, x;
    struct stackNode *temp;

    while (1)
    {
        printf("\nSTACK (Linked List)\n1.Push 2.Pop 3.Peek 4.Display 5.Back\n");
        printf("Enter choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("Enter numbers only\n");
            clearBuffer();
            continue;
        }

        if (ch == 1)
        {
            printf("Enter value: ");
            if (scanf("%d", &x) != 1)
            {
                printf("Enter numbers only\n");
                clearBuffer();
                continue;
            }
            temp = (struct stackNode *)malloc(sizeof(struct stackNode));
            temp->data = x;
            temp->next = top;
            top = temp;
        }
        else if (ch == 2)
        {
            if (top == NULL)
                printf("Stack empty\n");
            else
            {
                temp = top;
                printf("Popped: %d\n", temp->data);
                top = top->next;
                free(temp);
            }
        }
        else if (ch == 3)
        {
            if (top == NULL)
                printf("Stack empty\n");
            else
                printf("Top: %d\n", top->data);
        }
        else if (ch == 4)
        {
            temp = top;
            if (temp == NULL)
                printf("Stack empty\n");
            while (temp != NULL)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        else if (ch == 5)
            break;
        else
            printf("Invalid choice\n");
    }
}

/* -------- QUEUE USING ARRAY -------- */

int q[SIZE], front = -1, rear = -1;

void queueArrayMenu()
{
    int ch, x, i;

    while (1)
    {
        printf("\nQUEUE (Array)\n1.Enqueue 2.Dequeue 3.Display 4.Back\n");
        printf("Enter choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("Enter numbers only\n");
            clearBuffer();
            continue;
        }

        if (ch == 1)
        {
            if (rear == SIZE - 1)
            {
                printf("Queue full\n");
                continue;
            }
            printf("Enter value: ");
            if (scanf("%d", &x) != 1)
            {
                printf("Enter numbers only\n");
                clearBuffer();
                continue;
            }
            if (front == -1)
                front = 0;
            q[++rear] = x;
        }
        else if (ch == 2)
        {
            if (front == -1 || front > rear)
                printf("Queue empty\n");
            else
                printf("Deleted: %d\n", q[front++]);
        }
        else if (ch == 3)
        {
            if (front == -1 || front > rear)
                printf("Queue empty\n");
            else
            {
                for (i = front; i <= rear; i++)
                    printf("%d ", q[i]);
                printf("\n");
            }
        }
        else if (ch == 4)
            break;
        else
            printf("Invalid choice\n");
    }
}

/* -------- QUEUE USING LINKED LIST -------- */

struct queueNode
{
    int data;
    struct queueNode *next;
};

struct queueNode *f = NULL, *r = NULL;

void queueLLMenu()
{
    int ch, x;
    struct queueNode *temp;

    while (1)
    {
        printf("\nQUEUE (Linked List)\n1.Enqueue 2.Dequeue 3.Display 4.Back\n");
        printf("Enter choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("Enter numbers only\n");
            clearBuffer();
            continue;
        }

        if (ch == 1)
        {
            printf("Enter value: ");
            if (scanf("%d", &x) != 1)
            {
                printf("Enter numbers only\n");
                clearBuffer();
                continue;
            }
            temp = (struct queueNode *)malloc(sizeof(struct queueNode));
            temp->data = x;
            temp->next = NULL;

            if (r == NULL)
                f = r = temp;
            else
            {
                r->next = temp;
                r = temp;
            }
        }
        else if (ch == 2)
        {
            if (f == NULL)
                printf("Queue empty\n");
            else
            {
                temp = f;
                printf("Deleted: %d\n", temp->data);
                f = f->next;
                if (f == NULL)
                    r = NULL;
                free(temp);
            }
        }
        else if (ch == 3)
        {
            temp = f;
            if (temp == NULL)
                printf("Queue empty\n");
            while (temp != NULL)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        else if (ch == 4)
            break;
        else
            printf("Invalid choice\n");
    }
}

/* -------- MAIN -------- */

int main()
{
    int choice;

    while (1)
    {
        printf("\nMAIN MENU\n1.Stack 2.Queue(Array) 3.Queue(LL) 4.Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Enter numbers only\n");
            clearBuffer();
            continue;
        }

        if (choice == 1)
            stackMenu();
        else if (choice == 2)
            queueArrayMenu();
        else if (choice == 3)
            queueLLMenu();
        else if (choice == 4)
            break;
        else
            printf("Invalid choice\n");
    }

    return 0;
}
