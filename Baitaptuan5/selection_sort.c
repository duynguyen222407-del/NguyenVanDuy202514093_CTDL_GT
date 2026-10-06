#include<stdio.h>

int main(){
    int arr[13] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    for (int index = 0; index < 13; index++){
        printf("%d ", arr[index]);
    }
    printf("\n");
    for (int i = 0; i < 13; i++){
        int swap = 0;
        int index = 0;
        int min = arr[i];
        for (int j = 12; j >= i; j--){
            if (min > arr[j]){
                swap = 1;
                min = arr[j];
                index = j;
            }
        }
        if (swap){
            int tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;
        }
        for (int index = 0; index < 13; index ++){
            printf("%d ", arr[index]);
        }
        printf("\n");
    }
    return 0;
}