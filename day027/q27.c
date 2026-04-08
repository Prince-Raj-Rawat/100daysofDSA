#include <stdio.h>
#include <stdlib.h>
typedef struct N{
    int no;
    struct N *next;
}node;

node *head1=NULL,*head2=NULL, *ptr, *new,*temp;

void get_element(){
    new= (node *)malloc(sizeof(node));
    if(new != NULL){
        int data; 
        printf("enter element: ");
        scanf("%d",&data);
        new->no=data;
        new->next = NULL;
    }
    else{
        printf("dma failed");
    }
}

node* create_list(node *list){
    if(list == NULL){
        int n;
        printf("enter the no. of elements to add: ");
        scanf("%d",&n);
        for(int i = 0; i<n ;i++){
            get_element();
            if(list == NULL){
                list= new;
                ptr=list;
            }
            else{
                ptr->next = new;
                ptr=new;
            }
        }
        return list;
    }
    else{
        printf("list is already created");
        return list;
    }
}

void find_intersection(node* l1, node* l2){
    if (l1 ==NULL || l2 == NULL){
        printf("one of the is empty");
        return ;
    }
    else{
        ptr= l1, temp = l2;
        while (ptr !=NULL || temp !=NULL){
            if(ptr->no== temp->no){
                printf("%d is the intesection point");
                return;
            }
            else{
                if(ptr->no > temp->no){
                    temp = temp->next;
                }
                else if(ptr->no < temp->no){
                    ptr = ptr->next;
                }
            }
        }
        printf("no intersection point");
    }
}

void free_list(node *list){
    while(list !=NULL){
        temp= list;
        list= list->next;
        free(temp);
    }
}

int main(){
    int option;
    do{
        printf("1.create lists\n2.find intersection\n3.exit\n");
        printf("enter here:");
        scanf("%d",&option);
        switch(option){
            case 1:
            system("cls");
            printf("creating list...");
            head1 = create_list(head1);
            printf("------------");
            head2 = create_list(head2);
            system("cls");
            printf("list has been created");
            break;
            case 2:
            system("cls");
            find_intersection(head1,head2);
            break;
            case 3:
            printf("exiting program");
            free_list(head1);
            free_list(head2);
            break;
            default:
            printf("invalid input try again...");
        }
    }while(option != 3);

}
