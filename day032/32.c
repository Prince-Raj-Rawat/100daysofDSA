#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int top = -1;
int stack[MAX];

bool isempty(){
    return top == -1;
}
bool isfull(){
    return top == MAX-1;
}

void push(int a){
    if (isfull()){
        printf("stack is full");
        return;
    }
    stack[++top]=a;
}

int pop(){
    if(isempty()){
        printf("stack is empty");
        return -1;
    }
    return stack[top--];
}

void display(){
    if(isempty()){
        printf("stack is empty");
        return;
    }
    for(int i = top; i>=0; i--){
        printf("%d",stack[i]);
        if(i>0){
            printf(" ");
        }
    }
}

int main(){
    int opt,val,n;
    do{
        printf("1.push 2.pop 3.display 4.exit\n");
        printf("enter your option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1: 
                printf("enter the no. of elements to add: ");
                scanf("%d",&n);
                for(int i = 0;i<n;i++){
                    if(isfull()){
                        printf("stack is full");
                        break;
                    }
                    printf("enter value: ");
                    scanf("%d",&val);
                    push(val);
                }
                break;
            case 2:
                printf("\nenter the no of element to pop");
                scanf("%d",&n);
                if(n<0 || n>top){
                    printf("\ninvalid value..");
                    break;
                }
                for(int i = 0;i<n;i++){
                    if(isempty()){
                        printf("\nstack is empty\n");
                        break;
                    }
                    printf("%d ",pop());
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nexiting the program...");
                return 0;
            default:
                printf("\ninvalid value..");
        }
    }while(opt != 4);
    return 0;
}