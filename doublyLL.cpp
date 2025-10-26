#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* head = NULL;

// Create a new node
node* createNode(int value) {
    node* newnode = new node();
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Insert at beginning
void insertAtBeg(int value) {
    node* newnode = createNode(value);
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    cout << "Inserted " << value << " at beginning\n";
}

// Insert at end
void insertAtEnd(int value) {
    node* newnode = createNode(value);
    if (head == NULL) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    cout << "Inserted " << value << " at end\n";
}

// Insert after a node with given key
void insertAfterKey(int key, int value) {
    node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node with value " << key << " not found!\n";
        return;
    }
    node* newnode = createNode(value);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    cout << "Inserted " << value << " after " << key << "\n";
}

// Insert before a node with given key
void insertBeforeKey(int key, int value) {
    if (head == NULL) {
        cout << "List empty, cannot insert before " << key << "\n";
        return;
    }
    node* temp = head;
    // If head is the key node
    if (head->data == key) {
        insertAtBeg(value);
        return;
    }
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node with value " << key << " not found!\n";
        return;
    }
    node* newnode = createNode(value);
    newnode->prev = temp->prev;
    newnode->next = temp;
    temp->prev->next = newnode;
    temp->prev = newnode;
    cout << "Inserted " << value << " before " << key << "\n";
}

// Insert at specific position (1-based index)
void insertAtPosition(int pos, int value) {
    if (pos <= 0) {
        cout << "Position should be >= 1\n";
        return;
    }
    if (pos == 1) {
        insertAtBeg(value);
        return;
    }
    node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Position " << pos << " out of bounds, inserting at end\n";
        insertAtEnd(value);
        return;
    }
    node* newnode = createNode(value);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    cout << "Inserted " << value << " at position " << pos << "\n";
}

// Insert before specific position (i.e. at pos-1)
void insertBeforePosition(int pos, int value) {
    if (pos <= 1) {
        insertAtBeg(value);
        return;
    }
    insertAtPosition(pos - 1, value);
}

// Insert after specific position (i.e. at pos+1)
void insertAfterPosition(int pos, int value) {
    if (pos < 1) {
        cout << "Invalid position\n";
        return;
    }
    insertAtPosition(pos + 1, value);
}

// Delete at beginning
void deleteAtBeg() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete\n";
        return;
    }
    node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    cout << "Deleted node with value " << temp->data << " at beginning\n";
    delete temp;
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete\n";
        return;
    }
    node* temp = head;
    if (temp->next == NULL) { // Only one node
        cout << "Deleted node with value " << temp->data << " at end\n";
        delete temp;
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    cout << "Deleted node with value " << temp->data << " at end\n";
    delete temp;
}

// Delete node with given key
void deleteKey(int key) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete\n";
        return;
    }
    node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node with value " << key << " not found!\n";
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
    cout << "Deleted node with value " << key << "\n";
    delete temp;
}

// Delete before key
void deleteBeforeKey(int key) {
    if (head == NULL || head->next == NULL) {
        cout << "Not enough nodes to delete before " << key << "\n";
        return;
    }
    node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node with value " << key << " not found!\n";
        return;
    }
    if (temp->prev == NULL) {
        cout << "No node exists before " << key << "\n";
        return;
    }
    deleteKey(temp->prev->data);
}

// Delete after key
void deleteAfterKey(int key) {
    node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node with value " << key << " not found!\n";
        return;
    }
    if (temp->next == NULL) {
        cout << "No node exists after " << key << "\n";
        return;
    }
    deleteKey(temp->next->data);
}

// Delete at given position (1-based)
void deleteAtPosition(int pos) {
    if (pos <= 0) {
        cout << "Position should be >= 1\n";
        return;
    }
    if (head == NULL) {
        cout << "List empty, nothing to delete\n";
        return;
    }
    if (pos == 1) {
        deleteAtBeg();
        return;
    }
    node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Position " << pos << " out of bounds\n";
        return;
    }
    if (temp->next == NULL) {
        // last node
        deleteAtEnd();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    cout << "Deleted node at position " << pos << " with value " << temp->data << "\n";
    delete temp;
}

// Search node with value
bool search(int value) {
    node* temp = head;
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
        cout << "List is empty\n";
        return;
    }
    cout << "List (forward): ";
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Print list backward
void printBackward() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    cout << "List (backward): ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

// Clear entire list to avoid memory leaks
void clearList() {
    node* temp = head;
    while (temp != NULL) {
        node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
    cout << "Cleared the list\n";
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

    cout << "\nDeleting some nodes:\n";
    deleteAtBeg();
    deleteAtEnd();
    deleteBeforeKey(10);
    deleteAfterKey(8);
    deleteAtPosition(3);
    printForward();

    cout << "\nSearch tests:\n";
    cout << "Is 10 in list? " << (search(10) ? "Yes" : "No") << "\n";
    cout << "Is 100 in list? " << (search(100) ? "Yes" : "No") << "\n";

    clearList();

    return 0;
}
