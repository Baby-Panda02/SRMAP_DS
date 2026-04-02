#include <stdio.h>
#include <stdlib.h>

struct node /* Node creation */
{
	int data;
	struct node *next;
};

struct node *head = NULL;

void insert_begin() /* Insert at beginning */
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));

	if (newnode == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}

	printf("Enter data: ");
	scanf("%d", &newnode->data);

	newnode->next = head;
	head = newnode;

	printf("Node inserted at beginning\n");
}

/* Insert at end */
void insert_end()
{
	struct node *newnode, *temp;
	newnode = (struct node *)malloc(sizeof(struct node));

	if (newnode == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}

	printf("Enter data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}

	printf("Node inserted at end\n");
}

/* Delete from beginning */
void delete_begin()
{
	struct node *temp;

	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	temp = head;
	head = head->next;
	printf("Deleted element: %d\n", temp->data);
	free(temp);
}

/* Display list */
void display()
{
	struct node *temp;

	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	printf("Linked List: ");
	temp = head;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

/* Main function */
int main()
{
	int choice;

	while (1)
	{
		printf("\n--- Singly Linked List ---\n");
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Delete from beginning\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insert_begin();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			delete_begin();
			break;
		case 4:
			display();
			break;
		case 5:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
		}
	}
}