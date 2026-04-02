 #include <stdio.h>
 #include <stdlib.h>

 /* Structure of a doubly linked list node */
 struct node
 {
     int data;
     struct node *prev;
     struct node *next;
 };

 struct node *head = NULL;

 /* Function to create a new node */
 struct node *createNode(int value)
 {
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     if (newnode == NULL)
     {
         printf("Memory allocation failed\n");
         exit(1);
     }
     newnode->data = value;
     newnode->prev = NULL;
     newnode->next = NULL;
     return newnode;
 }

 /* Insert at beginning */
 void insertBegin(int value)
 {
     struct node *newnode = createNode(value);

     if (head != NULL)
     {
         head->prev = newnode;
         newnode->next = head;
     }
     head = newnode;
 }

 /* Insert at end */
 void insertEnd(int value)
 {
     struct node *newnode = createNode(value);
     struct node *temp = head;

     if (head == NULL)
     {
         head = newnode;
         return;
     }

     while (temp->next != NULL)
         temp = temp->next;

     temp->next = newnode;
     newnode->prev = temp;
 }

 /* Insert at specific position */
 void insertAtPosition(int value, int pos)
 {
     if (pos <= 0)
     {
         printf("Invalid position\n");
         return;
     }

     if (pos == 1)
     {
         insertBegin(value);
         return;
     }

     struct node *temp = head;
     int i;
     for (i = 1; i < pos - 1 && temp != NULL; i++)
         temp = temp->next;

     if (temp == NULL)
     {
         printf("Invalid position\n");
         return;
     }

     struct node *newnode = createNode(value);
     newnode->next = temp->next;
     newnode->prev = temp;

     if (temp->next != NULL)
         temp->next->prev = newnode;

     temp->next = newnode;
 }

 /* Delete from beginning */
 void deleteBegin()
 {
     struct node *temp;

     if (head == NULL)
     {
         printf("List is empty\n");
         return;
     }

     temp = head;
     head = head->next;

     if (head != NULL)
         head->prev = NULL;

     free(temp);
 }

 /* Delete from end */
 void deleteEnd()
 {
     struct node *temp = head;

     if (head == NULL)
     {
         printf("List is empty\n");
         return;
     }

     if (head->next == NULL)
     {
         free(head);
         head = NULL;
         return;
     }

     while (temp->next != NULL)
         temp = temp->next;

     temp->prev->next = NULL;

     free(temp);
 }

 /* Delete from specific position */
 void deleteAtPosition(int pos)
 {
     if (pos <= 0)
     {
         printf("Invalid position\n");
         return;
     }

     if (head == NULL)
     {
         printf("List is empty\n");
         return;
     }

     if (pos == 1)
     {
         deleteBegin();
         return;
     }

     struct node *temp = head;
     int i;
     for (i = 1; i < pos && temp != NULL; i++)
         temp = temp->next;

     if (temp == NULL)
     {
         printf("Invalid position\n");
         return;
     }

     temp->prev->next = temp->next;

     if (temp->next != NULL)
         temp->next->prev = temp->prev;

     free(temp);
 }

 /* Display the list */
 void display()
 {
     struct node *temp = head;

     if (head == NULL)
     {
         printf("List is empty\n");
         return;
     }

     printf("Doubly Linked List: ");
     while (temp != NULL)
     {
         printf("%d <-> ", temp->data);
         temp = temp->next;
     }
     printf("NULL\n");
 }

 /* Main function */
 int main()
 {
     int choice, value, pos;

     while (1)
     {
         printf("\n--- DOUBLY LINKED LIST MENU ---\n");
         printf("1. Insert at Beginning\n");
         printf("2. Insert at End\n");
         printf("3. Insert at Position\n");
         printf("4. Delete from Beginning\n");
         printf("5. Delete from End\n");

         printf("6. Delete from Position\n");
         printf("7. Display\n");
         printf("8. Exit\n");
         printf("Enter your choice: ");
         if (scanf("%d", &choice) != 1)
         {
             while (getchar() != '\n')
                 ;
             printf("Invalid choice\n");
             continue;
         }

         switch (choice)
         {
         case 1:
             printf("Enter value: ");
             scanf("%d", &value);
             insertBegin(value);
             break;

         case 2:
             printf("Enter value: ");
             scanf("%d", &value);
             insertEnd(value);
             break;

         case 3:
             printf("Enter value and position: ");
             scanf("%d %d", &value, &pos);
             insertAtPosition(value, pos);
             break;

         case 4:
             deleteBegin();
             break;

         case 5:
             deleteEnd();

             break;

         case 6:
             printf("Enter position: ");
             scanf("%d", &pos);
             deleteAtPosition(pos);
             break;

         case 7:
             display();
             break;

         case 8:
             exit(0);

         default:
             printf("Invalid choice\n");
             break;
         }
     }
     return 0;
 }