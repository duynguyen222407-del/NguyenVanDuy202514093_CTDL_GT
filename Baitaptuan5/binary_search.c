#include<stdio.h>

int binary_search(int arr[], int left, int right, int target){
    while (left <= right) {
        int mid = (right + left) / 2;
        if (target == arr[mid]) return 1;
        else if (target > arr[mid]){
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return 0;
}

int main(){
    int num_element;
    scanf("%d", & num_element);
    int arr[num_element];
    for (int i = 0; i < num_element; i++){
        scanf("%d", & arr[i]);
    }
    int target;
    scanf("%d", &target);
    printf("Array: ");
    for (int i = 0; i < num_element; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Target: ");
    printf("%d ", target);
    printf("\n");
    int check = binary_search(arr, 0, num_element - 1, target);
    if (check) printf("Found");
    else printf("Not found");
    return 0;
}