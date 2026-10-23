//Find the maximum product of two integers in an array
#include<stdio.h>

void merge_part(int arr[], int left, int mid, int right){
    int length = right - left + 1;
    int tmp[length];
    int left_arr_2 = mid + 1;
    int left_arr_1 = left;
    int index = 0;
    while(left_arr_1 <= mid && left_arr_2 <= right){
        if (arr[left_arr_1] < arr[left_arr_2]){
            tmp[index++] = arr[left_arr_1++];
        }
        else {
            tmp[index++] = arr[left_arr_2++];
        }
    }
    while (left_arr_1 <= mid){
        tmp[index++] = arr[left_arr_1++];
    }
    while (left_arr_2 <= right){
        tmp[index++] = arr[left_arr_2++];
    }
    for (int i = 0; i <= right - left; i++){
        arr[left + i] = tmp[i];
    }
}

void merge_sort(int arr[], int left, int right){
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge_part(arr, left, mid, right);
}

int main(){
    int max_product;
    int num_arr; scanf("%d", &num_arr);
    int arr[num_arr];
    for (int i = 0; i < num_arr; i++){
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, num_arr - 1);
    /*
    for (int i = 0; i < num_arr; i++){
        printf("%d ", arr[i]);
    }
    */
    max_product = arr[0] * arr[1];
    if (max_product < arr[num_arr - 2] * arr[num_arr - 1]){
        max_product = arr[num_arr - 2] * arr[num_arr - 1];
    }
    printf("%d", max_product);
    return 0;
}