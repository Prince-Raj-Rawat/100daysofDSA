#include <stdio.h>
#include <stdlib.h>
typedef struct N{
    int data;
    struct N *next;
}node;

int count = 0;
node *head=NULL,  *tail=NULL, *new,*ptr,*temp;

void get_element(){
    int num;
    new = (node *)malloc(sizeof(node));
    if(new){
        printf("enter the data: ");
        scanf("%d",&num);
        new->data=num;
        new->next = NULL;
    }
    else{
        printf("dma failed !!!");
    }
}

void create_list(){
    if(!head){
        int n;
        printf("enter the no of nodes to enter: ");
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            get_element();
            if(head == NULL){
                head = new;
                tail = new;
                tail->next=head;
            }
            else{
                tail->next = new;
                tail = new;
                tail -> next = head;
            }
            count ++;
        }
        printf("list has been created");
    }
    else{
        printf("list had already been created");
    }
}

void shift(int n){
    if (!head){
        printf("create the list first");
        return;
    }
    else{
        if(n<count && n>0){
            ptr= head;
            for(int i = 0; i<n ; i++){
                ptr = ptr->next;
            }
            temp=ptr->next;
            ptr->next = head;
            tail = ptr;
            head =temp;
            tail -> next= head;
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


int main() {
    int choice, n;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Shift List\n");
        printf("4. Free List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_list();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter positions to shift: ");
                scanf("%d", &n);
                shift(n);
                break;
            case 4:
                free_list();
                break;
            case 5:
                free_list();
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}