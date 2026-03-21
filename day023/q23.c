#include <stdio.h>
#include <Stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
}node;

node *list1=NULL, *list2=NULL, *list3=NULL, *new, *ptr;

void get_element(int data){
    new = (node *)malloc(sizeof(node));
    if(new!= NULL){
        new->data= data;
        new->next = NULL;
    }
    else printf("\ndma failed\n");

}

node* create_list(node *list){
    if (list != NULL){
        printf("\nlist is already created\n");
        return list; 
    }
    else{
        printf("elenter the no. of elements to add: ");
        int n,data;
        scanf("%d",&n);
        for(int i = 0; i<n ; i++){
            printf("enter data: ");
            scanf("%d",&data);
            get_element(data);
            if(list == NULL){
                list = new;
                ptr=new;
            }
            else{
                ptr->next=new;
                ptr=new;
            }
        }
        printf("\nlist has been created\n");
        return list;

    }
}

node* merge_list(node *l1,node *l2, node *l3){
   while(l1 != NULL || l2 != NULL){
    if(l1 == NULL || l2 == NULL){
        if(l3 == NULL){
        l3 = (l1 == NULL)?l2:l1;
        return l3;
        }
        else {
            ptr->next = (l1 == NULL)?l2:l1;
            return l3;
        }
    }
        else{
         
           if(l1->data<l2->data){
                get_element(l1->data);
                if(l3==NULL){
                    l3=new;
                   ptr=new;
               }
               else{
                    ptr->next = new;
                    ptr = new;
               } 
               l1=l1->next;    
            }
            else if(l2->data < l1->data){
                get_element(l2->data);
                if(l3==NULL){
                    l3=new;
                   ptr=new;
               }
               else{
                    ptr->next = new;
                    ptr = new;
               } 
               l2=l2->next;
            }
            else{
                get_element(l2->data);
                if(l3==NULL){
                    l3=new;
                   ptr=new;
               }
               else{
                    ptr->next = new;
                    ptr = new;
               } 
               l2=l2->next;
            }

        }
        
    }
    return l3;
}

void display(node *list){
    if (list != NULL){
        ptr = list ;
        while (ptr!= NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    else printf("the list is empty..");
}
void free_list(node *first){
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
                list1 = create_list(list1);
                list2 = create_list(list2);
                list3 = merge_list(list1,list2,list3);
                break;
            case 2:
                display(list1);
                display(list2);
                display(list3);
                break;
            case 3:
                printf("\nexiting...\n");
                break;
            default:
                printf("\ninvalid choice\n");

        }
    }
    free_list(list1);
    free_list(list2);
    free_list(list3);
    return 0;
}