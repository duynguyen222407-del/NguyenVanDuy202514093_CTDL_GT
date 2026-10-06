#include<stdio.h>

#include <stdio.h>

int main() {
    int arr[13] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    for (int index = 0; index < 13; index ++){
        printf("%d ", arr[index]);
    }
    printf("\n");
    int i, key, j;

    for (i = 1; i < 13; i++) {
        key = arr[i]; 
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        for (int index = 0; index < 13; index ++){
            printf("%d ", arr[index]);
        }
        printf("\n");
    }
    return 0;
}