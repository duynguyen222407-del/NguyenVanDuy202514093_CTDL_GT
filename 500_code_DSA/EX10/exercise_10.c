#include<stdio.h>
void swap_two_element(int *A, int *B){
   int tmp = *A;
   *A = *B;
   *B = tmp;
}
void merge_arr(int arr_A[], int arr_B[], int num_A, int num_B){
    for (int i = 0; i < num_A; i++){
        if (arr_A[i] > arr_B[0]){
            swap_two_element(&arr_A[i], &arr_B[0]);
        }

        for (int j = 0; j < num_B - 1; j++){
            if (arr_B[j] > arr_B[j + 1]){
                swap_two_element(arr_B + j, arr_B + j + 1);
            }
        }
    }
}

int main(){
    int num_X, num_Y;
    scanf("%d %d", &num_X, &num_Y);
    int X[num_X];
    int Y[num_Y];
    for (int i = 0; i < num_X; i++){
        scanf("%d ", &X[i]);
    }
    for (int j = 0; j < num_Y; j++){
        scanf("%d ", &Y[j]);
    }
    merge_arr(X, Y, num_X, num_Y);
    for (int i = 0; i < num_X; i++){
        printf("%d ", X[i]);
    }
    printf("\n");
    for (int j = 0; j < num_Y; j++){
        printf("%d ", Y[j]);
    }
    return 0;
}