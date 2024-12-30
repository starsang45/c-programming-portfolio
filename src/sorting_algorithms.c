#include <stdio.h>
#define SIZE 4

void ssSort(int a[], int size);
void SelectionSort(int a[], int size);
void bubbleSort(int a[], int size);
void insertionSort(int a[], int size);
int partition(int a[], int begin, int end);
void quickSort(int a[], int begin, int end);

void ssSort(int a[], int size) {
    int i, j, t, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        printf("Step %d: ", i + 1);
        for (t = 0; t < size; t++) printf("%d ", a[t]);
        printf("\n");
    }
}

void SelectionSort(int a[], int size) {
    int i, j, t, min, temp;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (a[j] < a[min]) min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        printf("Step %d: ", i + 1);
        for (t = 0; t < size; t++) printf("%d ", a[t]);
        printf("\n");
    }
}

void bubbleSort(int a[], int size) {
    int i, j, t, temp;
    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("Step %d: ", size - i);
        for (t = 0; t < size; t++) printf("%d ", a[t]);
        printf("\n");
    }
}

void insertionSort(int a[], int size) {
    int i, j, temp, t;
    for (i = 1; i < size; i++) {
        temp = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > temp)) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
        printf("Step %d: ", i);
        for (t = 0; t < size; t++) printf("%d ", a[t]);
        printf("\n");
    }
}

int partition(int a[], int begin, int end) {
    int pivot = a[begin];
    int left = begin + 1;
    int right = end;
    int temp;
    while (left <= right) {
        while (left <= right && a[left] <= pivot) left++;
        while (left <= right && a[right] > pivot) right--;
        if (left < right) {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
    temp = a[begin];
    a[begin] = a[right];
    a[right] = temp;
    return right;
}

void quickSort(int a[], int begin, int end) {
    if (begin < end) {
        int pivotIndex = partition(a, begin, end);
        quickSort(a, begin, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, end);
    }
}
