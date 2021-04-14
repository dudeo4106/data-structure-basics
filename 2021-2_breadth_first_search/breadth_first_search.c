#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

typedef struct Node {
	int index;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *front;
	Node *rear;
	int count;
} Queue;

Node** a;
int n = 5;
int m = 4;
int c[MAX_SIZE];

void addFront(Node *root, int index) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void queuePush(Queue *queue, int index) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	} else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

int queuePop(Queue *queue) {
	if (queue->count == 0) {
		printf("Queue underflow has occurred!");
		return -INF;
	}
	Node *node = queue->front;
	int index = node->index;
	queue->front = node->next;
	free(node);
	queue->count--;
	return index;
}

void bfs(int start) {
	Queue q;
	q.front = q.rear = NULL;
	q.count = 0;
	queuePush(&q, start);
	c[start] = 1;
	while(q.count != 0) {
		int x = queuePop(&q);
		printf("%d ", x);
		Node *cur = a[x]->next;
		while (cur != NULL) {
			int next = cur->index;
			if (!c[next]) {
				queuePush(&q, next);
				c[next] = 1;
			}
			cur = cur->next;
		}
	}
}

int main(void) {
	int x[4] = { 1, 1, 1, 2 };
    int y[4] = { 2, 3, 5, 5 };
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));

	for (int i = 0; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}

	for (int i = 0; i < m; i++) {
		int curX = x[i];
		int curY = y[i];
		addFront(a[curX], curY);
		addFront(a[curY], curX);
	}

	bfs(1);

	return 0;
}
