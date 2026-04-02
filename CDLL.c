#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Clear buffer
void clearBuffer() {
    while (getchar() != '\n');
}

// Create node
struct node* createNode(int x) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

// Insert at beginning
void insertBeginning() {
    int x;
    printf("Enter data: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input\n");
        clearBuffer();
        return;
    }

    struct node *n = createNode(x);

    if (head == NULL) {
        n->next = n->prev = n;
        head = n;
        return;
    }

    struct node *last = head->prev;

    n->next = head;
    n->prev = last;

    last->next = n;
    head->prev = n;

    head = n;
}

// Insert at end
void insertEnd() {
    int x;
    printf("Enter data: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input\n");
        clearBuffer();
        return;
    }

    struct node *n = createNode(x);

    if (head == NULL) {
        n->next = n->prev = n;
        head = n;
        return;
    }

    struct node *last = head->prev;

    n->next = head;
    n->prev = last;

    last->next = n;
    head->prev = n;
}

// Insert at position
void insertPosition() {
    int x, pos;
    printf("Enter position: ");
    if (scanf("%d", &pos) != 1) {
        printf("Invalid position\n");
        clearBuffer();
        return;
    }

    printf("Enter data: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input\n");
        clearBuffer();
        return;
    }

    if (pos == 1) {
        insertBeginning();
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Invalid position\n");
            return;
        }
    }

    struct node *n = createNode(x);

    n->next = temp->next;
    n->prev = temp;

    temp->next->prev = n;
    temp->next = n;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct node *last = head->prev;
    struct node *temp = head;

    head = head->next;

    last->next = head;
    head->prev = last;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *last = head->prev;

    if (last == head) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct node *newLast = last->prev;

    newLast->next = head;
    head->prev = newLast;

    printf("Deleted: %d\n", last->data);
    free(last);
}

// Delete from position
void deletePosition() {
    int pos;
    printf("Enter position: ");
    if (scanf("%d", &pos) != 1) {
        printf("Invalid position\n");
        clearBuffer();
        return;
    }

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Invalid position\n");
            return;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Display
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Main
int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR DLL MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice\n");
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertPosition(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deletePosition(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}