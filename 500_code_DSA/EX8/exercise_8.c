#include<stdio.h>

int find_max(int a, int b){
    return (a > b) ? a : b;
}

typedef struct {
    int max_element;
    int start;
    int end;
} subarr;

void find_largest_subarr(int arr[], int arr_B[], int num_arr){
    int max = 0;
    int num_sub = num_arr* (num_arr + 1) / 2; 
    subarr A[num_sub];
    int num = 0;
    for (int i = 0; i < num_arr; i++){
        for (int j = i + 1; j <= num_arr; j++){
            if (arr_B[i] == arr_B[j]){
                A[num].max_element = j - i;
                A[num].start = i;
                A[num].end = j - 1;
                max = find_max(max, A[num].max_element);
                num += 1;
            }
        }
    }
    if (max == 0){
        printf("There is no satisfied subarr");
    }
    else for (int j = 0; j < num; j++){
        if (A[j].max_element == max){
            for (int i = A[j].start; i <= A[j].end; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
}

int main(){
    int num_arr; scanf("%d", &num_arr);
    int arr[num_arr];
    int arr_B[num_arr + 1];
    arr_B[0] = 0;
    for (int i = 0; i < num_arr; i++){
        scanf("%d", &arr[i]);
        if (arr[i] == 0) arr_B[i + 1] = arr_B[i] - 1;
        else arr_B[i + 1] = arr_B[i] + 1;
    }
    find_largest_subarr(arr, arr_B, num_arr);
    return 0;
}