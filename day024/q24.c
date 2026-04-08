#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int data;
    struct N *next;
}node;
node *head=NULL,*new,*ptr,*temp;

void get_element(int a){
    new = (node *)malloc(sizeof(node));
    if(new!=NULL){
        new->data = a;
        new->next = NULL;
    }
    else printf("\nDMA failed successfully\n");
    
}

void create_list(){
    printf("enter the no. of elements you want to enter the list:");
    int n,d;
    scanf("%d",&n);
    for (int i = 0; i<n;i++){
        printf("enter %d element: ",i+1);
        scanf("%d",&d);
        get_element(d);
        if(head == NULL){
            head = new;
            ptr=head;
        }
        else{
            ptr->next=new;
            ptr=new;
        }
    }
    printf("element added successfully");
}

void remove_ele(int a){
    if(head == NULL){
        printf("the list is already empty");
    }
    else{
        int count=1;
        for(ptr= head;ptr->next!=NULL;ptr=ptr->next){
            if (ptr->next->data == a){
                temp = ptr->next;
                ptr->next = ptr->next->next;
                free(temp);
                printf("element removed successfully");
                break;
            }
        }
    }
}

void display(){
    if (head != NULL){
        for (ptr = head ; ptr != NULL; ptr = ptr->next){
            printf("%d ",ptr->data);
        }
    }
    else printf("list is empty");
}

void free_list(){
    while(head!= NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
    int choice,a;
    do{
        printf("1. create list \n2. diplay list \n3. remove element \n4. exit\n");
        printf("enter you choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                system("cls");
                create_list();
                break;
            case 2:
                display();
                break;
            case 3:
                system("cls");
                display();
                printf("enter the element: ");
                scanf("%d",&a);
                remove_ele(a);
                break;
            case 4:
                system("cls");
                printf("exiting program");
                free_list();
                break;
            default:
                printf("invalid value.. try again");
        }
    }
    while (choice != 4);
}