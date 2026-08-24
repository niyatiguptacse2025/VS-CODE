#include <stdio.h>
#include <stdbool.h>

// Function to perform an optimized bubble sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    
    // Outer loop for passes
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Inner loop to compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; // Mark that a swap occurred
            }
        }
        
        // If no two elements were swapped by inner loop, then break
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Original array:\n");
    printArray(data, size);
    
    // Run the sorting algorithm
    bubbleSort(data, size);
    
    printf("Sorted array in ascending order:\n");
    printArray(data, size);
    
    return 0;
}
