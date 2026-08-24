#include <stdio.h>

#define MAX_CAPACITY 100 // Maximum size of the array

// Function Declarations
void traverseArray(int arr[], int size);
int insertElement(int arr[], int *size, int element, int position);
int deleteElement(int arr[], int *size, int position);

int main() {
    int arr[MAX_CAPACITY] = {10, 20, 30, 40, 50}; // Initial array elements
    int size = 5; // Current number of elements in the array
    int choice, element, position;

    while (1) {
        printf("\n--- 1D ARRAY OPERATIONS ---");
        printf("\n1. Traversal (Display)");
        printf("\n2. Insertion");
        printf("\n3. Deletion");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCurrent Array Elements: ");
                traverseArray(arr, size);
                break;

            case 2:
                printf("\nEnter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (0 to %d): ", size);
                scanf("%d", &position);

                if (insertElement(arr, &size, element, position)) {
                    printf("Element inserted successfully!\n");
                } else {
                    printf("Insertion failed! Invalid position or array full.\n");
                }
                break;

            case 3:
                printf("\nEnter the position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);

                if (deleteElement(arr, &size, position)) {
                    printf("Element deleted successfully!\n");
                } else {
                    printf("Deletion failed! Invalid position or array empty.\n");
                }
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. TRAVERSAL OPERATION
// Time Complexity: O(n) - Visits every element sequentially
void traverseArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2. INSERTION OPERATION
// Time Complexity: O(n) - Shifts subsequent elements to the right
int insertElement(int arr[], int *size, int element, int position) {
    // Check if the array is already at max capacity
    if (*size >= MAX_CAPACITY) {
        return 0; 
    }
    // Check if the target position is within valid bounds
    if (position < 0 || position > *size) {
        return 0; 
    }

    // Shift elements to the right from the end up to the target position
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified position index
    arr[position] = element;
    
    // Update the tracker size of the array
    (*size)++; 
    return 1;
}

// 3. DELETION OPERATION
// Time Complexity: O(n) - Shifts subsequent elements to the left
int deleteElement(int arr[], int *size, int position) {
    // Check if the array contains any elements to delete
    if (*size == 0) {
        return 0; 
    }
    // Check if the target position is within valid bounds
    if (position < 0 || position >= *size) {
        return 0; 
    }

    // Shift elements to the left to close the gap
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the logical size tracker
    (*size)--; 
    return 1;
}
