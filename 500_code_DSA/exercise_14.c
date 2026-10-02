//Find equilibrium index of an array
#include<stdio.h>

void find_equilibrium_index(int arr[], int n){
    int sum_left[n];
    sum_left[0] = 0;
    for (int i = 1; i < n; i++){
        sum_left[i] = sum_left[i - 1] + arr[i - 1];
    }
    int sum_right = 0;
    for (int i = n - 1; i >= 0; i--){
        if (sum_right == sum_left[i]){
            printf("%d ", i);
        }
        sum_right += arr[i];
    }
}

int main(){

    return 0;
}