/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/

#include <stdio.h>
#include <stdlib.h>

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
void reverse(int *arr, int start, int end){
    int temp;
    while (start<end){
        temp= arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

int main(){
    int *arr,n,m;
    again:
    printf("enter the no of elements to enter: ");
    scanf("%d",&n);
    arr= (int *)malloc(sizeof(int)*n);
    if (arr != NULL){
        printf("\nmemory allocated successfully\n");
        printf("enter the elements: \n");
        for(int i=0; i<n;i++){
        scanf("%d",&arr[i]);
        }
        bubble_sort(arr,n);
        for(int i = 0; i <n ;i ++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        printf("enter the pos: ");
        scanf("%d",&m);
        m=m%n;
        reverse(arr,0,n-1);
        reverse(arr,0,m-1);
        reverse(arr,m,n-1);
        printf("\nrotated successfully\n");
        for(int i = 0; i<n; i++){
            printf("%d ",arr[i]);
        }
        free(arr);

    }
    else{
        printf("\nmemory is not allocated.. try again\n");
        goto again;
    }
}
