#include<stdio.h>
void sort_array(int arr[], int num_element){
    int cnt = 0;
    for (int index = 0; index < num_element; index ++){
        if (arr[index] == 0) cnt++;
    }
    for (int j = 0; j < cnt; j++){
        arr[j] = 0;
    }
    for (int k = cnt; k < num_element; k++){
        arr[k] = 1;
    }
}
int main(){
    int num_element;
    scanf("%d", &num_element);
    int arr[num_element];
    for (int i = 0; i < num_element; i++){
        scanf("%d", &arr[i]);
    }
    sort_array(arr, num_element);
    for (int j = 0; j < num_element; j++){
        printf("%d ", arr[j]);
    }
    return 0;
}