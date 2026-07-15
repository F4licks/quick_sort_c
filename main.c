#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int arr[], int low, int hight) {
    if (low < hight) {
        int pivot = arr[(low + hight) / 2];
        int i = low;
        int j = hight;

        while (i <= j) {
            while (arr[i] < pivot) { i++; }
            while (arr[j] > pivot) { j--; }

            if (i <= j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }

        if (low < j) quick_sort(arr, low, j);
        if (i < hight) quick_sort(arr, i, hight);

    }
}

int main () {
    int arr[] = {10, 50, 6, 3, 1, 18, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    quick_sort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}