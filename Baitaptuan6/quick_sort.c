#include<stdio.h>

int sort_with_pivot(int arr[], int left, int right){
    int pivot = arr[left];
    int i = left + 1; int j = right;
    while(i <= j){
        while(arr[i] <= pivot && i <= right) i+= 1;
        while(arr[j] >= pivot && j >= left) j-= 1;
        if (i < j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    if (j < left) j += 1;
    int temp = arr[j];
    arr[j] = arr[left];
    arr[left] = temp;
    return j;
}

void quick_sort(int arr[], int left, int right){
    if (right <= left) return;
    else{
        int pivot_position = sort_with_pivot(arr, left, right);
        for (int i = 0; i < 13; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        quick_sort(arr, left, pivot_position - 1);
        quick_sort(arr, pivot_position + 1, right);
    }
}

int main(){
    int arr[13] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    for (int i = 0; i < 13; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    quick_sort(arr, 0, 12);
    for (int i = 0; i < 13; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}