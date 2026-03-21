#include <stdio.h>
#include <stdlib.h>

struct node{
    int no;
    struct node *next;
}*first, *ptr, *new;
int count = 0;

int count_node(){
    int node =0;
    for (ptr = first; ptr!=NULL; ptr= ptr->next){
        node+=1;
    }
    return node;
}
void get_element(){
    if (first == NULL) printf("\nthe list is created , it has one node\n");
    new = (struct node *)malloc(sizeof(struct node));
    if (new != NULL) {
        new->next = NULL;
        printf("enter the data: ");
        scanf("%d",&new->no);
    }
    else {
        printf("\nDMA unsuccessful, try again\n");
    }
}
void create_list(){
    int n;
    printf("\nenter the no of elements to add in the linked list: \n");
    scanf("%d",&n);
    if (n != 0 && n>0){
        count +=n;
        for (int i = 0; i< n; i++){
            get_element();
            if(first == NULL) first = new;
            else{
                for(ptr = first; ptr->next != NULL; ptr = ptr->next);
                ptr->next = new;
            }
        }
        printf("\n%d elements added successfull in the list",n);
    }
    else printf("invalid value");
}
void display(){
    if (first != NULL){
        int n=count_node();
        printf("there are %d nodes\n",n);
        ptr = first ;
        while (ptr!= NULL){
            printf("%d ",ptr->no);
            ptr = ptr->next;
        }
    }
    else printf("the list is empty..");
}
void free_list(){
    while (first!= NULL){
    ptr= first;
    first= first->next;
    free(ptr);
    }
}

int main(){
    int choice ;
    while (choice != 3 ){
        printf("\n(1) create list :: (2) display :: (3) exit\nenter you choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create_list();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nexiting...\n");
                break;
            default:
                printf("\ninvalid choice\n");

        }
    }
    free_list();
    return 0;
}