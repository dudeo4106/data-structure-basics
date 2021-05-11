#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 200001

typedef struct Edge {
  int cost;
  int node;
} Edge;

void swap(Edge *a, Edge *b) {
	Edge temp;
	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;
}

typedef struct priorityQueue {
	Edge *heap[EDGE_MAX];
	int count;
} priorityQueue;

void push(priorityQueue *pq, Edge *edge) {
	if (pq->count >= EDGE_MAX) return;
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

Edge* pop(priorityQueue *pq) {
	if (pq->count <= 0) return NULL;
	Edge *res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	while (leftChild < pq->count) {
		if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if (pq->heap[target]->cost > pq->heap[rightChild]->cost && rightChild < pq->count) target = rightChild;
		if (target == now) break;
		else {
			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

typedef struct Node {
	Edge *data;
	struct Node *next;
} Node;

Node** adj;
int d[NODE_MAX];

void addNode(Node** target, int index, Edge* edge) {
	if (target[index] == NULL) {
		target[index] = (Node*)malloc(sizeof(Node));
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

int main(void) {
	int input[3][3] = {
		{1, 2, 8},
		{1, 3, 9},
		{2, 3, 10},
	};
	int n = 3;
	int m = 3;

	adj = (Node**)malloc(sizeof(Node*) * (n + 1));
	for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }
	priorityQueue *pq;
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));
	pq->count = 0;
	for (int i = 0; i < m; i++) {
		Edge *edge1 = (Edge*)malloc(sizeof(Edge));
		edge1->node = input[i][1];
		edge1->cost = input[i][2];
		addNode(adj, input[i][0], edge1);
		Edge *edge2 = (Edge*)malloc(sizeof(Edge));
		edge2->node = input[i][0];
		edge2->cost = input[i][2];
		addNode(adj, input[i][1], edge2);
	}

	long long res = 0;
	Edge *start = (Edge*)malloc(sizeof(Edge));
	start->cost = 0;
	start->node = 1;
	push(pq, start);
	for (int i = 1; i <= n; i++) {
		int nextNode = -1, nextCost = INT_MAX;
		while (1) {
			Edge* now = pop(pq);
			if (now == NULL) break;
			nextNode = now->node;
			if (!d[nextNode]) {
				nextCost = now->cost; break; }
			}
			if (nextCost == INT_MAX) printf("This is not a connected graph.\n");
			res += nextCost;
			d[nextNode] = 1;
			Node* cur = adj[nextNode];
			while (cur != NULL) {
				push(pq, cur->data); cur = cur->next;
			}
	}
	printf("%lld\n", res);
	return 0;
}