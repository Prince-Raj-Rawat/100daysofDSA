#include <stdio.h>
void bubble_sort(int *ptr,int *size);
void remove_duplicate(int *ptr,int *size);
void print_element(int *ptr, int *size);
int main(){
    int arr[50];
    int n;
    printf("enter the no. of elemnts to enter : ");
    scanf("%d",&n);
    for (int i = 0; i <n;i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,&n);
    remove_duplicate(arr,&n);
    print_element(arr,&n);
    return 0;
}

void bubble_sort(int *ptr, int *size){
    int temp;
    for (int i = 0; i< (*size) ;i++ ){
        for(int j =0 ; j< (((*size) - 1) - i) ; j++ ){
            if(ptr[j]>ptr[j+1]){
                temp=ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }
    }
}
void remove_duplicate(int *ptr, int *size){
    int j = 1;
    for (int i = 1 ; i < *size;i++){
            if (ptr[i] != ptr[j-1]){
                ptr[j++]=ptr[i];
        }
    }
    *size = j; 
}
void print_element(int *ptr, int *size){
    for (int i = 0 ; i <*size;  i++){
        printf("%d: %d\n",i+1,ptr[i]);
    }
}