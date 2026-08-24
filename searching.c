#include <stdio.h>

int main() {
    int size, searchTarget, foundIndex = -1;

    // 1. Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1) return 1;

    int arr[size]; // Declare 1D array with user-defined size

    // 2. Input array elements
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    // 3. Get the target value to search
    printf("Enter the number to search for: ");
    if (scanf("%d", &searchTarget) != 1) return 1;

    // 4. Linear Search logic
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchTarget) {
            foundIndex = i; // Store the matching index
            break;          // Stop searching once found
        }
    }

    // 5. Display the search result
    if (foundIndex != -1) {
        printf("Element %d found at index %d (Position %d).\n", searchTarget, foundIndex, foundIndex + 1);
    } else {
        printf("Element %d was not found in the array.\n", searchTarget);
    }

    return 0;
}
