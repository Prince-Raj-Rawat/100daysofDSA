#include <stdio.h>
#include <Stdlib.h>

typedef struct n{
    int data;
    struct n *next;
    struct n *prev;
} node;

node *tail=NULL, *head=NULL,*new,*temp;

void get_element(int a){
    new= (node *)malloc(sizeof(node));
    if(new!=NULL){
        new->data=a;
        new->next=NULL;
        new->prev=NULL;
    }
    else{
        printf("dma failed");
    }
}

void create_list(){
    if (head ==NULL){
        int n,a;
        printf("enter the no. of elements to enter :");
        scanf("%d",&n);
        for(int i = 0; i<n;i++){
            printf("enter the %d element: ",i+1);
            scanf("%d",a);
            get_element(a);
            if (head==NULL){
                head= new;
                temp=new;
            }
            else{
                temp->next = new;
                new->prev=temp;
                temp = new;
                tail=temp;
            }
        }
    }
    else{
        printf("list is already created");
    }
}

void display(){
    if(head != NULL){
        for(temp=head;temp->next != NULL;temp=temp->next){
            printf("%d ",temp->data);
        }
        printf("\n");
        for(temp=tail;temp->prev != NULL; temp=temp->prev){
            printf("%d ",temp->data);
        }
        printf("\n");
    }
}
void free_list(){
    while(head != NULL){
        temp = head;
        head = head->next ;
        free(temp);
    }
}


int main(){
    int choice;
    
}