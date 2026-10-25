#include<stdio.h>

void find_subarr(int arr[], int num_element){
    int max_value, best_max = 0, current_start = 0, best_start;
    for (int i = 0; i < num_element; i++){
        for (int j = current_start; j < i; j++){
            if (arr[j] == arr[i]){
                current_start = j + 1;
                break;
            }
        }
        max_value = i - current_start + 1;
        if (best_max < max_value){
            best_max = max_value;
            best_start = current_start;
        }
    }
    for (int i = best_start; i < best_start + best_max; i++){
        printf("%d ", arr[i]);
    }   
}

int main(){
    int num_element; scanf("%d", &num_element);
    int arr[num_element];
    for (int i = 0; i < num_element; i++){
        scanf("%d", &arr[i]);
    }
    find_subarr(arr, num_element);
    return 0;
}