#include <stdio.h>

// Function to print the array
void printArray(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Partition function
int partition(int arr[], int low, int high, int n)
{
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Put pivot in its correct position
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Print array after each partition
    printf("Pass: ");
    printArray(arr, n);

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high, int n)
{
    if (low < high)
    {
        int pivotIndex;

        pivotIndex = partition(arr, low, high, n);

        quickSort(arr, low, pivotIndex - 1, n);
        quickSort(arr, pivotIndex + 1, high, n);
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array: ");
    printArray(arr, n);

    printf("\nQuick Sort passes:\n");

    quickSort(arr, 0, n - 1, n);

    printf("\nSorted array: ");
    printArray(arr, n);

    return 0;
}
