// Find majority element (Boyer–Moore Majority Vote Algorithm)
#include<stdio.h>

int majority_vote(int *arr, int n, int *check){
    int candidate = 0;
    int count = 0;
    int check_cnt = 0;
    for (int i = 0; i < n; i++){
        if (count == 0){
            candidate = *(arr + i);
        }
        if (candidate == *(arr + i)){
            count ++;
        }
        else{
            count --;
        }
    }
    for (int i = 0; i < n; i++){
        if (*(arr + i) == candidate){
            check_cnt ++;
        }
        if (check_cnt > n / 2){
            *check = 1;
        }
        else {
            *check = 0;
        }
    }
    return candidate;
}
int main(){
    int check = 0;
    int num_element;
    scanf("%d", &num_element);
    int arr[num_element];
    for (int i = 0; i < num_element; i++){
        scanf("%d", &arr[i]);
    }
    int majority_val = majority_vote(arr, num_element, &check);
    if (check){
        printf("%d", majority_val);
    }
    else {
        printf("Non_existent");
    }
    return 0;
}