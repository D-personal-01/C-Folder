//Name- Daksh Joshi E.no.- 01414002025
//1. WAP to sort an array using menu driven: (CO3)
//(i) Bubble Sort
//(ii) Merge Sort
//(iii) Insertion Sort
//(iv) Selection Sort
//(v) Quick Sort

void Bubble(int *arr,int n);
void Merges(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void Insertion(int *arr, int n);
void Selection(int *arr, int n);
int partition(int arr[], int low, int high);
void Quick(int arr[], int low, int high);
void display(int arr[],int n);

#include <stdio.h>

int main(){

    int n;
    printf("\nEnter the number of elements to be sorted: ");
    scanf("%d",&n);

    int arr[n],arro[n],i,c=1;

    for(i=0;i<n;i++){
        printf("\nEnter element: ");
        scanf("%d",&arr[i]);
        arro[i] = arr[i];
    }

    while (c){

        for(i=0;i<n;i++){
            arr[i] = arro[i];
        }

        printf("\nEnter the type of sorting you want to perform:\n 1) Bubble Sort \t\t 2) Merge Sort\n 3) Insertion Sort \t\t 4) Selection Sort\n 5) Quick Sort \t\t\t 6) EXIT\n");
        scanf("%d",&c);

        switch(c){
            case 1:
                Bubble(arr,n);
                display(arr,n);
                break;
            case 2:
                Merges(arr, 0, n - 1);
                display(arr,n);
                break;
            case 3:
                Insertion(arr,n);
                display(arr,n);
                break;
            case 4:
                Selection(arr,n);
                display(arr,n);
                break;
            case 5:
                Quick(arr,0,n-1);
                display(arr,n);
                break;
            case 6:
                return 0;
            default:
                printf("\nERROR: Invalid choice\n");
        }
    }
}
void Bubble(int *arr,int n){
    int i,j,t;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void Merges(int arr[], int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        Merges(arr, l, m);
        Merges(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void Insertion(int *arr, int n){
    int i, j, key;

    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

}

void Selection(int *arr, int n){
    int i, j, min, temp;

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void Quick(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        Quick(arr, low, pi - 1);
        Quick(arr, pi + 1, high);
    }
}

void display(int arr[],int n){
    printf("Sorted Array:\n| ");
    for (int i = 0; i < n; i++) {
            printf("%d | ", arr[i]);
                }
    printf("\n");
}
