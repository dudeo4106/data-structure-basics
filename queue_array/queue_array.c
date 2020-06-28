#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int rear = 0;

void push(int data) {
    if (rear == SIZE) {
        printf("Queue overflow has occurred\n");
        return;
    }
    queue[rear++] = data;
}

int pop() {
    if (front == rear) {
       printf("Queue underflow has occurred\n");
       return -INF;
    }
    return queue[front++];
}

void show() {
    for (int i = front; i < rear; i++) {
        printf("%d\n", queue[i]);
    }
}

int main(void) {
    push(1);
    push(2);
    push(3);
    pop();
    push(10);
    pop();
    show();
    return 0;
}
