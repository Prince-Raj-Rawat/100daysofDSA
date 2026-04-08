#include <stdio.h>

#define MAX 50

int top= -1, rear=-1;
int queue[MAX];

int isempty(){
    return (top ==-1 || top > rear);
}

int isfull(){
    return ( rear==MAX-1);
}

int dequeue(){
    if(isempty()){
        printf("stack is empty");
        return -1;
    }
    return queue[top++];
}

void enqueue(int a){
    if(isfull()){
        printf("stack is full");
        return;
    }
    queue[++rear] = a;
    if(top == -1) top = 0;
    return;
}

void display(){
    if(!isempty()){
        for(int i = top ; i<=rear ; i++){
            printf("%d ",queue[i]);
        }
    }
}

int main(){
    printf("welcome to the stack program::");
    int choice = 0;
    while(choice != 4){
        printf("\n1.enqueue 2.dequeue 3.display 4.exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                int a;
                printf("enter the no. to enter in the queue: ");
                scanf("%d",&a);
                enqueue(a);
                break;
            case 2:
                int b = dequeue();
                if(b != -1){
                printf("%d has ben dequeued from the list",b);
            }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting the programe...");
                break;
            default:
                printf("invalid option choose again...");

        }
    }
    return 0;
}