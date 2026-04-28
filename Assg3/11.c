//Name- Daksh Joshi   Enrollment number-01414002026
//11. WAP to search & display the location of an element specified by the user, in an array using
//    (i) Linear Search (ii) Binary Search technique.


#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int left = 0, right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

void sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int pos1 = linearSearch(arr, n, key);

    if(pos1 != -1)
        printf("Linear Search: Found\n");
    else
        printf("Linear Search: Not Found\n");

    sort(arr, n);

    int pos2 = binarySearch(arr, n, key);

    if(pos2 != -1)
        printf("Binary Search: Found\n");
    else
        printf("Binary Search: Not Found\n");

    return 0;
}
