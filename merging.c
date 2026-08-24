#include <stdio.h>

void merge(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
    int i;

    // Copy first array elements
    for(i = 0; i < n1; i++)
    {
        arr3[i] = arr1[i];
    }

    // Copy second array elements
    for(i = 0; i < n2; i++)
    {
        arr3[n1 + i] = arr2[i];
    }
}

void display(int arr[], int n)
{
    int i;

    printf("Merged array elements are:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr1[100], arr2[100], arr3[200];
    int n1, n2, i;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array:\n");

    for(i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array:\n");

    for(i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    merge(arr1, n1, arr2, n2, arr3);

    display(arr3, n1 + n2);

    return 0;
}
