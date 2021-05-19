#include <stdio.h>
#define NUMBER 7

int a[] = { 7, 1, 9, 5, 6, 4, 1 };
int tree[4 * NUMBER];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif) {
	if (index < start || index > end) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(void) {
	init(0, NUMBER - 1, 1);
	printf("0 ~ 6 Sum: %d\n", sum(0, NUMBER - 1, 1, 0, 6));
	printf("Modify elements of index 5 by +3\n");
	update(0, NUMBER - 1, 1, 5, 3);
	printf("3 ~ 6 Sum: %d\n", sum(0, NUMBER - 1, 1, 3, 6));
	return 0;
}