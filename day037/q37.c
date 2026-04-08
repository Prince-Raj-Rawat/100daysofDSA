#include <stdio.h>

#define MAX 100

int queue[MAX];

int front = -1, rear = -1;

int isempty(){
    return (front == -1 && rear == -1);
}

int isfull(){
    return (rear == MAX-1);
}


