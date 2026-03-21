#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n);

int main(){
    int *a,n;
    again:
    printf("enter the no. of elements to enter: ");
    scanf("%d",&n);
    a= (int *)malloc(sizeof(int)*n);
    if(a!=NULL){
        printf("memory allocated successfully\n");
        printf("enter the elements:\n");
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        bubble_sort(a,n);
        for(int i=0; i <n; i++){
            printf("%d ",a[i]);
        }
        printf("\nThe max:  %d \n",a[n-1]);
        printf("the min:  %d \n",a[0]);
        free(a);
        return 0;
    }
    else{
        printf("memory allocation failed.... , try again:\n");
        goto again;
    }
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