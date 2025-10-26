#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted at beginning.\n");
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted at end (only node).\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted at end.\n");
}

// Delete by value (key)
void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    if (head->data == key) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Node with value %d deleted.\n", key);
}

// Delete at specific position (1-based)
void deleteAtPosition(int pos) {
    if (head == NULL || pos <= 0) {
        printf("Invalid position or list empty!\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; ++i) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of range.\n", pos);
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Node at position %d deleted.\n", pos);
}

// Delete entire list
void deleteList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Entire list deleted.\n");
}

// Delete node after given key
void deleteAfterKey(int key) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }
    if (temp->next == NULL) {
        printf("No node exists after the key %d.\n", key);
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Node after key %d deleted.\n", key);
}

// Delete node before given key
void deleteBeforeKey(int key) {
    if (head == NULL || head->next == NULL) {
        printf("Not enough nodes to delete before key.\n");
        return;
    }
    if (head->data == key) {
        printf("No node exists before the key %d.\n", key);
        return;
    }
    if (head->next->data == key) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL && temp->next->next->data != key) {
        temp = temp->next;
    }
    if (temp->next->next == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Node before key %d deleted.\n", key);
}

// Helper function to create a node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Main Program
int main() {
    // Pre-fill list for testing
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    int choice, key, pos;

    do {
        printf("\n--- Singly Linked List Deletion Menu ---\n");
        printf("1. Delete at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Delete by Value (Key)\n");
        printf("4. Delete at a Specific Position\n");
        printf("5. Delete Entire List\n");
        printf("6. Delete After a Given Key\n");
        printf("7. Delete Before a Given Key\n");
        printf("8. Display List\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteAtBeginning();
                break;
            case 2:
                deleteAtEnd();
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByValue(key);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 5:
                deleteList();
                break;
            case 6:
                printf("Enter key (after which node will be deleted): ");
                scanf("%d", &key);
                deleteAfterKey(key);
                break;
            case 7:
                printf("Enter key (before which node will be deleted): ");
                scanf("%d", &key);
                deleteBeforeKey(key);
                break;
            case 8:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    deleteList(); // free memory at the end
    return 0;
}
