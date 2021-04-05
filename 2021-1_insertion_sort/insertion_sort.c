#include <stdio.h>
#include <limits.h>
#define SIZE 6

int a[SIZE] = {1, 9, 3, 7, 6, 2};

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    for (int i = 0; i < SIZE - 1; i++) {
        int j = i;
        while(j >= 0 && a[j] > a[j + 1]) {
            swap(&a[j], &a[j + 1]);
            j--;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d", a[i]);
    }
    return 0;
}
