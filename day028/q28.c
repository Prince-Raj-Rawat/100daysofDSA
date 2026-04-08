#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int data;
    struct N *next;
}node;
node *head=NULL,*tail=NULL,*new,*ptr,*temp;

void create_node(int a){
    new=(node*)malloc(sizeof(node));
    if(new){
        new->data=a;
        if(head==NULL){
            head=new;
            tail=new;
            tail->next=new;
        }
        else{
            tail->next=new;
            tail=tail->next;
            tail->next=head;
        }
    }
}

void display(){
    if(head){
        ptr=head;
        do{
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
        printf("\n");
    }
}

void free_list(){
    if(head){
        temp=head->next;
        while(temp!=head){
            ptr=temp;
            temp=temp->next;
            free(ptr);
        }
        free(head);
        head=NULL;
        tail=NULL;
    }
}

int main(){
    int choice,data;
    do{
        printf("1.create list\n2.display list\n3.exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            system("cls");
            int n;
            printf("enter the no. of elements to enter: ");
            scanf("%d",&n);
            for (int i =0; i<n;i++){
                printf("enter the data: ");
                scanf("%d",data);
                create_node(data);
            }
            printf("list created successfully");
            break;
            case 2:
            system("cls");
            display();
            break;
            case 3:
            printf("exiting program...");
            free_list();
            break;
            default:
            printf("invalid input... try again.");


        }
    }while(choice != 3);
}