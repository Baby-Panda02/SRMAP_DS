#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the head of the list (simplifies function calls)
struct Node* head = NULL;

// --- Helper Function: Create a new node ---
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// --- 1. Insertion Operations ---

void insert_begin(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", value);
}

void insert_end(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

void insert_pos(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    
    if (pos == 1) {
        insert_begin(value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    
    // Traverse to the node BEFORE the desired position
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            free(newNode); // Clean up unused memory
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
    }
}

// --- 2. Deletion Operations ---

void delete_begin() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    if (head->next == NULL) { // Only one node
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) { // Stop at second to last node
        temp = temp->next;
    }
    
    printf("Deleted %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void delete_pos(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        delete_begin();
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
    } else {
        prev->next = temp->next;
        printf("Deleted %d from position %d.\n", temp->data, pos);
        free(temp);
    }
}

// --- 3. Display Operation ---

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// --- Main Menu ---

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n--- Single Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        
        // Input validation for choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_begin(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_pos(val, pos);
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}