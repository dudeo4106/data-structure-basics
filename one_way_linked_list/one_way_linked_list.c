#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void removeFront(Node *root) {
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

void freeAll(Node *root) {
    Node *cur = head->next;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur=next;
    }
}

void showAll(Node *root) {
    Node *cur = head->next;
    while (cur != NULL) {
        printf("%d", cur->data);
        cur = cur->next;
        printf("\n");
    }
}

int main(void)
{
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 5);
    addFront(head, 9);
    addFront(head, 8);
    removeFront(head);
    showAll(head);
    freeAll(head);
    return 0;
}
