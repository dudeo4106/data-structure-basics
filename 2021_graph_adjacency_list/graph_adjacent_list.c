#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int index;
	int distance;
	struct Node *next;
} Node;

void addFront(Node *root, int index, int distance) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}

void showAll(Node *root) {
	Node *cur = root->next;
	while (cur != NULL) {
		printf("%d(distance: %d): ", cur->index, cur->distance);
		cur = cur->next;
	}
}

int main(void) {
    int vertex = 5;
    int edge = 4;
	int vertexAry[4] = { 1, 1, 1, 3 };
	int edgeAry[4] = { 2, 3, 5, 4 };
	int distanceAry[4] = { 9, 8, 10, 8 };

	Node** a = (Node**)malloc(sizeof(Node*) * (vertex + 1));

    for (int i = 1; i <= vertex; i++) {
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }

    for (int i = 0; i < edge; i++) {
        int x = vertexAry[i];
        int y = edgeAry[i];
        int curDistance = distanceAry[i];
        addFront(a[x], y, curDistance);
    }

    for (int i = 1; i <= vertex; i++) {
        printf("item [%d]: ", i);
        showAll(a[i]);
        printf("\n");
    }
    return 0;
}
