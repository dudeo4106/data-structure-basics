#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;

void push(int data) {
    if (top == SIZE - 1) {
        printf("Stack overflow has occurred\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
       printf("Stack underflow has occurred\n");
       return -INF;
    }
    return stack[top--];
}

void show() {
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
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
