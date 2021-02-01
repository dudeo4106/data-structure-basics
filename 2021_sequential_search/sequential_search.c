#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100

char fruits[5][7] = {"apple", "orange", "banana", "melon", "apple"};
int founded;

int main(void) {
    int n = 5;
    char word[7] = "apple";

    for (int i = 0; i < n; i++) {
        if (strcmp(fruits[i], word) == 0) {
            printf("----> %d \n" , i + 1);
            founded = 1;
        }
    }

	if (!founded) printf("not found");
    return 0;
}
