#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int data;
    struct N *next;
}node;

node *first,*ptr,*new;

void get_element(){
    int a;
    new = (node *)malloc(sizeof(node));
    if(new!=NULL){
        printf("enter the element: ");
        scanf("%d",&a);
        new->data = a ;
        new->next = NULL;
    }
    else{
        printf("dma unsuccessful");
    }
}

void create_list(){
    if (first == NULL){
        printf("enter the number of elements to enter: ");
        int n;
        scanf("%d",&n);
        for (int i = 0; i<n ; i++){
            get_element();
            if(first==NULL){
                first=new;
                ptr=first;
            }
            else{
                ptr->next = new;
                ptr=new;
            }
        }
    }
    else{
        printf("list is already created");
    }
}

void count_ele(){
    if (first != NULL){
        int a;
        printf("enter the element: ");
        scanf("%d",&a);
        int count = 0;
        for (ptr = first; ptr->next != NULL; ptr = ptr->next){
            if(ptr->data == a){
                count ++;
            }
        }
        printf("%d appears %d times in the list",a,count);
    }
}

void free_list(){
    while(first!=NULL){
        ptr = first;
        first=first->next;
        free(ptr);
    }
}

int main(){
    int choice;
    do{
        printf("1.create list\n2.count element\n3.exit");
        printf("\neneter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            
        }
    }
}