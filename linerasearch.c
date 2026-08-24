#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        // Return index if target matches current element
        if (arr[i] == target) {
            return i;
        }
    }
    // Return -1 if target is not found
    return -1;
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Call the search function
    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
