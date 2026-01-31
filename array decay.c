#include <stdio.h>

void displayArray(int arr[], int *ptr, int n)
{
    int i;

    printf("Access using arr[i]:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nAccess using *(arr+i):\n");
    for(i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    printf("\n\nAccess using i[arr]:\n");
    for(i = 0; i < n; i++)
        printf("%d ", i[arr]);

    printf("\n\nPointer arithmetic traversal:\n");
    for(i = 0; i < n; i++)
        printf("%d ", *(ptr + i));

    printf("\n\nSizeof arr parameter: %lu", sizeof(arr));
    printf("\nSizeof ptr parameter: %lu\n", sizeof(ptr));
}

int main()
{
    int a[5] = {10, 20, 30, 40, 50};

    printf("Sizeof array in main: %lu\n\n", sizeof(a));

    displayArray(a, a, 5);

    return 0;
}
