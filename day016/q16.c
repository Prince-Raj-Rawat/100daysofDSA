#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n);
int main(){
    int *arr;
    int n,freq[100][1] = {0};
    printf("enter the amount of element you want to enter: ");
    scanf("%d",&n);
    arr = (int *)malloc(sizeof(int)*n);
    printf("enter the elemnts in array: \n");
    for (int i = 0; i <n; i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
    for (int i = 0; i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    int count = 1;
    for(int i= 0; i <n;i++){
        if(arr[i]==arr[i+1]){
            count++;
        }
        else{
            printf("%d : %d\n",arr[i],count);
            count= 1;
        }
        }
    
    free(arr);
    return 0;
}

void bubble_sort(int *arr, int n){
    int temp;
    for (int i = 0 ; i<n ; i++){
        for(int j = 0; j < n-1 -i; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1]= arr[j];
                arr[j]= temp;

            }
        }
    }
}