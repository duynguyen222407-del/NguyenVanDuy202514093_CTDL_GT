#include<stdio.h>

void swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void sort_arr(int arr[], int num_element){
    int low = 0, mid = 0, high = num_element - 1;
    while (mid <= high){
        if (arr[mid] == 0){
            swap(arr, mid, low);
            mid += 1;
            low += 1;
        }
        else if (arr[mid] == 1){
            mid += 1;
        }
        else {
            swap(arr, mid, high);
            high -= 1;
        }
    }
}
int main(){
    int num_element;
    scanf("%d", &num_element);
    int arr[num_element];
    for (int i = 0; i < num_element; i++){
        scanf("%d", &arr[i]);
    }
    sort_arr(arr, num_element);
    for (int i = 0; i < num_element; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}