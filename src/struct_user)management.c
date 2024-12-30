#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct user {
    int num;
    char level; // G: Gold, S: Silver, B: Bronze
    char name[50];
};

int main() {
    int i;
    struct user *puser;
    puser = (struct user *)malloc(SIZE * sizeof(struct user));
    if (puser == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (i = 0; i < SIZE; i++) {
        printf("Enter user %d info (ID, Level, Name):\n", i + 1);
        scanf("%d", &puser[i].num);
        getchar();
        scanf("%c", &puser[i].level);
        getchar();
        fgets(puser[i].name, sizeof(puser[i].name), stdin);
    }
    for (i = 0; i < SIZE; i++) {
        printf("User %d: ID=%d, Level=%c, Name=%s", i + 1, puser[i].num, puser[i].level, puser[i].name);
    }
    free(puser);
    return 0;
}
