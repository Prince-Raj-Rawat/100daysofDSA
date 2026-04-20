#include <stdio.h>

#define MAX 50

int front = -1, rear = -1;
int queue[MAX];

int isfull() {
    return (rear + 1) % MAX == front;
}

int isempty() {
    return (rear == -1 && front == -1);
}

void enqueue(int a) {
    if (isfull()) {
        printf("queue is full\n");
        return;
    }
    if (isempty()) {
        front = rear = 0;
        queue[rear] = a;
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = a;
}

int dequeue() {
    if (isempty()) {
        printf("the queue is already empty\n");
        return -1;
    }
    int val = queue[front];
    if (rear == front) {
        rear = front = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

void display() {
    if (isempty()) {
        printf("the queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if (val != -1) printf("%d dequeued\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
