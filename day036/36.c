#include <stdio.h>

#define MAX 50

int front = -1, rear = -1;
int queue[MAX];
int isfull(){
    return (rear+1)%MAX == front;
}

int isempty(){
    return (rear == -1 && front == -1);
}

void enqueue(int a){
    if(isfull()){
        printf("queue is full");
        return;
    }
    if(isempty()){
        front=rear=0;
        queue[rear]=a;
        return;
    }
    rear= (rear+1)%MAX;
    queue[rear]=a;
}

int dequeue(){
    if(isempty){
        printf("the queue is already empty");
        return;
    }
    int a;
    if(rear==front){
        a=rear;
        rear=front=-1;
        return queue[a];
    }
    a=front;
    front = (front+1)%MAX;
    return queue[a];
}

void display(){
    if(isempty()){
        printf("the queue is empty");
        return;
    }
    int i=rear;
    while(1){
        printf("%d ",queue[i]);
        if(i==front) break;
        i = (i-1+MAX)%MAX;
    }
}