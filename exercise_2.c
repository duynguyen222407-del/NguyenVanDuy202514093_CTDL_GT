// check if a subset with 0 sum exists or not
#include<stdio.h>
typedef struct{
    int sum;
    int indice;
} list_sum;


void buble_sort_Str_arr(list_sum arr[], int n){
    for (int i = 0; i < n; i++){
        int check_value = 0;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j].sum > arr[j + 1].sum){
                check_value = 1;
                list_sum arr_tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]  = arr_tmp;
            }
        }
        if (!check_value) break;
    }
}

int check_subset(int provided_arr[], int n){
    list_sum arr[n];
    int tmp_sum = 0;
    for (int index = 0; index < n; index ++){
        tmp_sum += provided_arr[index];
        if (tmp_sum == 0) return 1;
        arr[index].sum = tmp_sum;
        arr[index].indice = index;
    }
    buble_sort_Str_arr(arr, n);
    for (int i = 0; i < n - 1; i++){
        if (arr[i].sum == arr[i + 1].sum) return 1;
    }
    return 0;
}
int main(){
    int n; scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int result = check_subset(arr, n);
    printf("%d", result);
    return 0;
}