#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct Node {
	int index;
	struct Node *next;
} Node;

Node** a;
int n = 3;
int m = 3;
int c[MAX_SIZE];

void addFront(Node *root, int index) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x) {
	if (c[x]) return;
	c[x] = 1;
	printf("%d ", x);
	Node *cur = a[x]->next;
	while(cur != NULL) {
		int next = cur->index;
		dfs(next);
		cur = cur->next;
	}
}

int main(void) {
	int x[3] = { 1, 1, 2 };
    int y[3] = { 2, 3, 3 };
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

	dfs(1);

	return 0;
}
