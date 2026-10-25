#include "sort_arr.h"

static void merge(int arr[], int left, int right, int mid){
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
}

static int sort_with_pivot(int arr[], int left, int right){
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
        quick_sort(arr, left, pivot_position - 1);
        quick_sort(arr, pivot_position + 1, right);
    }
}