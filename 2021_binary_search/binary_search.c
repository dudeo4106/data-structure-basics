#include <stdio.h>
#define MAX_SIZE 100000

int a[6] = {1, 3, 7, 10, 14, 15};
int founded = 0;

int search(int start, int end, int target) {
	if (start > end) return -9999;
	int mid = (start + end) / 2;
	if (a[mid] == target) return mid;
	else if (a[mid] > target) return search(start, mid - 1, target);
	else return search(mid + 1, end, target);
}

int main(void) {
    int n = 6;
    int target = 15;
    int result = search(0, n - 1, target);
    if (result != -9999) printf("---> %d\n", result + 1);
    else printf("Not Found");
    return 0;
}
