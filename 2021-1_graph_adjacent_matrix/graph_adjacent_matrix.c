#include <stdio.h>

int a[1001][1001];

int main(void) {
    int vertex = 5;
    int edge = 3;

	int vertexAry[3] = { 1, 3, 4 };
	int edgeAry[3] = { 2, 4, 5 };
    for (int i = 0; i < edge; i++) {
        int x = vertexAry[i];
        int y = edgeAry[i];
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
			printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
