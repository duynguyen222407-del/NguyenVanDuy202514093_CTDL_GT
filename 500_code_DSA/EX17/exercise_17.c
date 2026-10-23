//Move all zeros present in an array to the end
#include<stdio.h>

void move_zeros(int *arr, int n){
    int j = 0;
    for(int i = 0; i < n; i++){
        if (*(arr + i) != 0){
            *(arr + j) = *(arr + i);
            j++;
        }
    }
    for (int i = j; i < n; i++){
        *(arr + i) = 0;
    }
}

void swap_2_elements(int *arr, int i, int j){
    int tmp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = tmp;
}

void using_pivot(int *arr, int n){
    int pivot = 0;
    for (int i = 0; i < n; i++){
        if (*(arr + i) != 0){
            swap_2_elements(arr, i, pivot);
            pivot ++;
        }
    }
} 

int main(){
    int arr[9] = {6, 0, 8, 2, 3, 0, 4, 0, 1};
    move_zeros(arr, 9);
    for (int i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}