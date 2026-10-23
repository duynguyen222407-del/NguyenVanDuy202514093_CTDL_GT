//Move all zeros present in an array to the end
#include<stdio.h>

void move_zero(int arr[], int num_element){
    int index = 0;
    for (int j = 0; j < num_element; j++){
        if (arr[j] != 0){
            arr[index] = arr[j];
            index += 1;
        }
    }
    for (int j = index; j < num_element; j++){
        arr[j] = 0;
    }
}

int main(){
    int num_element;
    scanf("%d", &num_element);
    int arr[num_element];
    for (int i = 0; i < num_element; i++){
        scanf("%d", &arr[i]);
    }
    move_zero(arr, num_element);
    for (int i = 0; i < num_element; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}