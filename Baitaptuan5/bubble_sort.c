#include<stdio.h>

int main(){
    int arr[10] = {1, 9, 10, 11, 45, 56, 57, 39, 9, 10};
    int check;
    while(1){
        check = 0;
        for (int i = 0; i < 9; i++){
            if (arr[i] > arr[i + 1]){
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                check = 1;
            }
        }
        if (check == 0) break;
    }
    for (int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}