//Find equilibrium index of an array
#include<stdio.h>

void find_equilibrium_index(int arr[], int n){
    int check = 0;
    int sum_left[n];
    sum_left[0] = 0;
    for (int i = 1; i < n; i++){
        sum_left[i] = sum_left[i - 1] + arr[i - 1];
    }
    int sum_right = 0;
    for (int i = n - 1; i >= 0; i--){
        if (sum_right == sum_left[i]){
            printf("%d ", i);
            check = 1;
        }
        sum_right += arr[i];
    }
    if(check == 0){
        printf("Khong ton tai chi so thoa man");
    }
}

int main(){
    int num_element;
    scanf("%d", &num_element);
    int arr[num_element];
    for (int i = 0; i < num_element; i++){
        scanf("%d", &arr[i]);
    }
    find_equilibrium_index(arr, num_element);
    return 0;
}