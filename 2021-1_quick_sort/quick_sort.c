#include <stdio.h>
#define SIZE 10

int a[SIZE] = {5, 10, 9, 7, 3, 1, 4, 6, 8, 2};

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int start, int end) {
    if (start >= end) return;
    int key = start, i = start + 1, j = end, temp;
    while (i <= j) {
        while (i <= end && a[i] <= a[key]) i++;
        while (j > start && a[j] >= a[key]) j--;
        if (i > j) swap(&a[key], &a[j]);
        else swap(&a[i], &a[j]);
    }
    quickSort(start, j - 1);
    quickSort(j + 1, end);
}

int main(void) {
	quickSort(0, SIZE - 1);
	for (int i = 0; i < SIZE; i++) printf("%d\n", a[i]);
    return 0;
}
