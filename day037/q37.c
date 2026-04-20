#include <stdio.h>

#define MAX 100

int queue[MAX];

int front = -1, rear = -1;

int isempty(){
    return (front > rear|| (front==-1 || rear == -1));
}

int isfull(){
    return (rear == MAX-1);
}

int peek(){
    if(!isempty()){
        return queue[front];
    }
    return -1;
}

void enqueue(int a){
    if(isfull()){
        printf("the queue is full\n");
        return;
    }
    if(isempty()){
        rear = front = 0;
        queue[rear]=a;
        return;
    }
    int i;
    for(i = front; i<=rear && a>queue[i];i++);
    for (int j = rear; j>=i;j--){
        queue[j+1]=queue[j];
    }
    queue[i]=a;
    rear ++;

}

int dequeue(){
    if(!isempty()){
        return queue[front++];
    }
    printf("queue is empty");
    return -1;
}

void display(){
    if(!isempty()){
        for(int i = front ; i<=rear ; i++){
            printf("%d ",queue[i]);
        }
        return;
    }
    printf("list is empty");
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
