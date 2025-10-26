#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Linked list structure
struct LinkedList {
    struct Node* head;
};

// Function prototypes
void initList(struct LinkedList* list);
void insertAtBeginning(struct LinkedList* list, int value);
void insertAtEnd(struct LinkedList* list, int value);
void deleteNode(struct LinkedList* list, int value);
void display(struct LinkedList* list);
void freeList(struct LinkedList* list);

int main() {
    struct LinkedList list;
    initList(&list);
    int choice, value;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&list, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&list, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&list, value);
                break;

            case 4:
                display(&list);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    freeList(&list);
    return 0;
}

// Initialize the list
void initList(struct LinkedList* list) {
    list->head = NULL;
}

// Insert node at beginning
void insertAtBeginning(struct LinkedList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

// Insert node at end
void insertAtEnd(struct LinkedList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Delete node by value
void deleteNode(struct LinkedList* list, int value) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = list->head;
    struct Node* prev = NULL;

    // If head node is to be deleted
    if (temp != NULL && temp->data == value) {
        list->head = temp->next;
        free(temp);
        return;
    }

    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value not found
    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display the linked list
void display(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = list->head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Free all nodes in the list
void freeList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}
