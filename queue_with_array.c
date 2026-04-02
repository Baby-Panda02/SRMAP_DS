#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

/* Function to insert an element into the queue */
void enqueue() {
	int item;
	if (rear == MAX - 1) {
		printf("Queue Overflow! Cannot insert.\n");
		return;
	}

	//printf("Enter element to insert: ");
	//scanf("%d", &item);

	printf("Enter an integer: ");

	while (scanf("%d", &item) != 1)
	{
		printf("Invalid input! Enter again: ");

		// Clear input buffer
		while (getchar() != '\n');
	}
	printf("Valid input: %d\n", item);

	if (front == -1)
		front = 0;

	rear++;
	queue[rear] = item;
	printf("Element inserted successfully.\n");
}

/* Function to delete an element from the queue */
void dequeue() {
	if (front == -1 || front > rear) {
		printf("Queue Underflow! Cannot delete.\n");
		return;
	}

	printf("Deleted element: %d\n", queue[front]);
	front++;
}

/* Function to display the queue */
void display() {
	int i;
	if (front == -1 || front > rear) {
		printf("Queue is empty.\n");
		return;
	}

	printf("Queue elements: ");
	for (i = front; i <= rear; i++) {
		printf("%d ", queue[i]);
	}
	printf("\n");
}

/* Main function */
int main() {
	int choice;

	while (1) {
		printf("\n--- Queue Operations ---\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
			while (getchar() != '\n');
			printf("Invalid choice! Try again.\n");
			continue;
		}

		switch (choice) {
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("Invalid choice! Try again.\n");
				break;
		}
	}
}