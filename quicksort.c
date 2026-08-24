#include <stdio.h>

// Function to swap two elements using pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function: Places pivot at correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);    // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    // Place pivot in its correct sorted position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Main Quick Sort function that implements recursion
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program
int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted Array: \n");
    printArray(data, n);
    
    // Perform quicksort
    quickSort(data, 0, n - 1);
    
    printf("Sorted Array in Ascending Order: \n");
    printArray(data, n);
    
    return 0;
}
