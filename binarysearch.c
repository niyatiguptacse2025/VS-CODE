#include <stdio.h>

// Function to perform iterative binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Prevents integer overflow compared to (low + high) / 2
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        // If target is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }

    // Element was not present in the array
    return -1;
}

int main() {
    // Binary search requires a SORTED array
    int my_array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(my_array) / sizeof(my_array[0]);
    int target = 23;

    printf("Searching for target value: %d\n", target);
    int result = binarySearch(my_array, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element is not present in the array.\n");
    }

    return 0;
}
