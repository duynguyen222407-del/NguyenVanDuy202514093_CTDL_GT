// Find majority element (Boyer–Moore Majority Vote Algorithm)
#include<stdio.h>

void majority_vote(int arr[], int n){
    int check = 0;
    int candidate = arr[0];
    int count = 0;
    int check_cnt = 0;
    for (int i = 0; i < n; i++){
        if (candidate == arr[i]){
            count += 1;
        }
        else count -= 1;
        if (count == 0){
            if (i < n - 1) candidate = arr[i + 1];
        }
    }
    for (int i = 0; i < n; i++){
        if (*(arr + i) == candidate){
            check_cnt ++;
        }
        if (check_cnt > n / 2){
            check = 1;
        }
    }
    if(check) printf("%d", candidate);
    else printf("Non_existent");
}

int main(){
    int num_element;
    scanf("%d", &num_element);
    int arr[num_element];
    for (int i = 0; i < num_element; i++){
        scanf("%d", &arr[i]);
    }
    majority_vote(arr, num_element);
    return 0;
}