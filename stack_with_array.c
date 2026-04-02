#include <stdio.h> //declaration
#define MAX 5 // X

int stack[MAX]; // global declarations
int top = -1;

/* Push operation */
void push(int value)
{
	if (top == MAX - 1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		top++; // top = top + 1;
		stack[top] = value;
		printf("%d inserted into stack\n", value);
	}
}

/* Pop operation */
void pop()
{
	if (top == -1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("%d popped from stack\n", stack[top]);
		top--; // top = top - 1
	}
}

/* Display stack */
void display()
{
	// int i;
	if (top == -1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack elements are:\n");
		for (int i = top; i >= 0; i--) // for displaying elements in FILO manner
		{
			printf("%d\n", stack[i]);
		}
	}
}

int main(void)
{
	int choice, value;
	// int x;

	while (1)
	{
		printf("\n--- Stack Menu ---\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1)
		{
			// clear invalid input
			while (getchar() != '\n');
			printf("Invalid choice\n");
			continue;
		}

		switch (choice)
		{
		case 1:
			printf("Enter an integer: ");
			while (scanf("%d", &value) != 1)
			{
				printf("Invalid input! Enter again: ");
				while (getchar() != '\n')
					; // Clear input buffer
			}
			printf("Valid input: %d\n", value);
			push(value);
			break;

		case 2:
			pop();
			break;

		case 3:
			display();
			break;

		case 4:
			return 0;

		default:
			printf("Invalid choice\n");
			break;
		}
	}
}