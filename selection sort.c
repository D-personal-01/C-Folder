#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, n);

    return 0;
}
