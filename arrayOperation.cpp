#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum array size

void inputArray(int arr[], int &size) {
    cout << "Enter the number of elements (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE || size < 0) {
        cout << "Invalid size!\n";
        size = 0;
        return;
    }

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }
}

void displayArray(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertElement(int arr[], int &size, int element, int position) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }

    if (position < 0 || position > size) {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
    cout << "Element inserted successfully.\n";
}

void deleteElement(int arr[], int &size, int position) {
    if (size == 0) {
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }

    if (position < 0 || position >= size) {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "Element deleted successfully.\n";
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while (true) {
        cout << "\n--- Array Operations Menu ---\n";
        cout << "1. Input Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputArray(arr, size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3: {
                int element, position;
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position (0 to " << size << "): ";
                cin >> position;
                insertElement(arr, size, element, position);
                break;
            }
            case 4: {
                int position;
                cout << "Enter position to delete (0 to " << size - 1 << "): ";
                cin >> position;
                deleteElement(arr, size, position);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
