#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

// Create a new node
struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Insert at beginning
void insertAtBeg(int value) {
    struct node* newnode = createNode(value);
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Inserted %d at beginning\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct node* newnode = createNode(value);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Inserted %d at end\n", value);
}

// Insert after a node with given key
void insertAfterKey(int key, int value) {
    struct node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found!\n", key);
        return;
    }
    struct node* newnode = createNode(value);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    printf("Inserted %d after %d\n", value, key);
}

// Insert before a node with given key
void insertBeforeKey(int key, int value) {
    if (head == NULL) {
        printf("List empty, cannot insert before %d\n", key);
        return;
    }
    if (head->data == key) {
        insertAtBeg(value);
        return;
    }

    struct node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found!\n", key);
        return;
    }

    struct node* newnode = createNode(value);
    newnode->prev = temp->prev;
    newnode->next = temp;
    temp->prev->next = newnode;
    temp->prev = newnode;
    printf("Inserted %d before %d\n", value, key);
}

// Insert at specific position (1-based index)
void insertAtPosition(int pos, int value) {
    if (pos <= 0) {
        printf("Position should be >= 1\n");
        return;
    }
    if (pos == 1) {
        insertAtBeg(value);
        return;
    }

    struct node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d out of bounds, inserting at end\n", pos);
        insertAtEnd(value);
        return;
    }

    struct node* newnode = createNode(value);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    printf("Inserted %d at position %d\n", value, pos);
}

// Delete at beginning
void deleteAtBeg() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted node with value %d at beginning\n", temp->data);
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = head;
    if (temp->next == NULL) {
        printf("Deleted node with value %d at end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("Deleted node with value %d at end\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Delete node with given key
void deleteKey(int key) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found!\n", key);
        return;
    }

    if (temp == head) {
        deleteAtBeg();
        return;
    }
    if (temp->next == NULL) {
        deleteAtEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted node with value %d\n", key);
    free(temp);
}

// Delete before key
void deleteBeforeKey(int key) {
    if (head == NULL || head->next == NULL) {
        printf("Not enough nodes to delete before %d\n", key);
        return;
    }
    struct node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found!\n", key);
        return;
    }
    if (temp->prev == NULL) {
        printf("No node exists before %d\n", key);
        return;
    }
    deleteKey(temp->prev->data);
}

// Delete after key
void deleteAfterKey(int key) {
    struct node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found!\n", key);
        return;
    }
    if (temp->next == NULL) {
        printf("No node exists after %d\n", key);
        return;
    }
    deleteKey(temp->next->data);
}

// Delete at given position (1-based)
void deleteAtPosition(int pos) {
    if (pos <= 0) {
        printf("Position should be >= 1\n");
        return;
    }
    if (head == NULL) {
        printf("List empty, nothing to delete\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeg();
        return;
    }

    struct node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position %d out of bounds\n", pos);
        return;
    }
    if (temp->next == NULL) {
        deleteAtEnd();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted node at position %d with value %d\n", pos, temp->data);
    free(temp);
}

// Search node with value
bool search(int value) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

// Print list forward
void printForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List (forward): ");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Print list backward
void printBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Clear entire list
void clearList() {
    struct node* temp = head;
    while (temp != NULL) {
        struct node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
    printf("Cleared the list\n");
}

// Main function for testing
int main() {
    insertAtBeg(10);
    insertAtBeg(5);
    insertAtEnd(20);
    insertAfterKey(10, 15);
    insertBeforeKey(10, 8);
    insertAtPosition(3, 9);
    printForward();
    printBackward();

    printf("\nDeleting some nodes:\n");
    deleteAtBeg();
    deleteAtEnd();
    deleteBeforeKey(10);
    deleteAfterKey(8);
    deleteAtPosition(3);
    printForward();

    printf("\nSearch tests:\n");
    printf("Is 10 in list? %s\n", search(10) ? "Yes" : "No");
    printf("Is 100 in list? %s\n", search(100) ? "Yes" : "No");

    clearList();
    return 0;
}
