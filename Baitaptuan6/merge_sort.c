#include<stdio.h>

void merge(int arr[], int left, int right, int mid){
    int len_A = mid - left + 1, len_B = right - mid;
    int arr_A[len_A];
    int arr_B[len_B];
    int A = 0, B = 0;
    int index_A = 0, index_B = 0;
    int index = left;
    for (int i = left; i <= mid; i++){
        arr_A[A] = arr[i];
        A += 1;
    }
    for (int j = mid + 1; j <= right; j++){
        arr_B[B] = arr[j];
        B+= 1;
    }
    while(index_A < len_A && index_B < len_B){
        if (arr_A[index_A] < arr_B[index_B]){
            arr[index++] = arr_A[index_A++];
        }
        else arr[index++] = arr_B[index_B++];
    }
    while (index_A < len_A){
        arr[index++] = arr_A[index_A++];
    }
    while(index_B < len_B){
        arr[index++] = arr_B[index_B++];
    }
}

void merge_sort(int arr[], int left, int right){
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, right, mid);
    for (int i = 0; i < 13; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int A[13] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    for (int i = 0; i < 13; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    merge_sort(A, 0, 12);
    for (int i = 0; i < 13; i++){
        printf("%d ", A[i]);
    }
    return 0;
}