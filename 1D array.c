#include<stdio.h>

void insertion(int *arr){
    int n;
    printf("Enter the position of the element:");
    scanf("%d",&n);
    printf("Enter the new Element:");
    scanf("%d",&arr[n]);


}

void deletion(int *arr){
    int n;
    printf("Enter the position of the element:");
    scanf("%d",&n);
    arr[n]=-1;
}

void transversal(int *arr){
    for(int i=0;i<10;i++)
        printf("%d ",arr[i]);

}

void reverse(int *arr){
    int m;
    for(int i = 0; i < 5; i++){
        m = arr[i];
        arr[i] = arr[9 - i];
        arr[9 - i] = m;
    }
}


void merge(int *arr){
    int arr1[10]={0}, arrm[20];

    printf("Enter 10 elements for second array (sorted):\n");
    for(int x=0; x<10; x++){
        scanf("%d", &arr1[x]);
    }

    int i=0, j=0, k=0;

    while(i<10 && j<10){
        if(arr[i] < arr1[j]){
            arrm[k++] = arr[i++];
        }
        else{
            arrm[k++] = arr1[j++];
        }
    }

    while(i<10)
        arrm[k++] = arr[i++];

    while(j<10)
        arrm[k++] = arr1[j++];

    printf("Merged array:\n");
    for(int x=0; x<20; x++){
        printf("%d ", arrm[x]);
    }
}


int main(){
    int arr[10]={0};
    int c,;
    while (1){
    printf("Operation choices: \n 1.Insertion \n 2.Deletion \n 3.Transversal \n 4.Reverse \n 5.Merge \n 6.Exit");
    printf("Enter the serial number of the operation you want to do:");
    scanf("%d",&c);
    switch(c){
    case 1:
         insertion(arr);
         break;
    case 2:
         deletion(arr);
         break;
    case 3:
        transversal(arr);
         break;
    case 4:
        reverse(arr);
         break;
    case 5:
        merge(arr);
         break;
    default:
        return 0;
    }
    }

return 0;
}
