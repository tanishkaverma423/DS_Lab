#include <stdio.h>
#include <stdbool.h>  // For bool and true/false

#define MAX_SIZE 100 // Maximum array size

void inputArray(int arr[], int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);

    if (*size > MAX_SIZE || *size < 0) {
        printf("Invalid size!\n");
        *size = 0;
        return;
    }

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element deleted successfully.\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while (true) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Input Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3: {
                int element, position;
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                break;
            }
            case 4: {
                int position;
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            }
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
