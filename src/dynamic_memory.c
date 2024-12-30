#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main() {
    int *n;
    int i;
    n = (int *)malloc(SIZE * sizeof(int));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (i = 0; i < SIZE; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", n + i);
    }
    for (i = 0; i < SIZE; i++) {
        printf("Number %d: %d\n", i + 1, *(n + i));
    }
    free(n);
    return 0;
}
