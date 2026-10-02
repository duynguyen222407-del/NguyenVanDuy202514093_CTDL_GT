#include<stdio.h>
void sort_array(int arr[], int n){
    int cnt = 0;
    for (int index = 0; index < n; index ++){
        if (arr[index] == 0) cnt++;
    }
    // ghi de vao mang cu
    for (int j = 0; j < cnt; j++){
        arr[j] = 0;
    }
    for (int k = cnt; k < n; k++){
        arr[k] = 1;
    }
}
int main(){
    int n;  // n la so phan tu cua mang
    scanf("%d", &n);
    int arr[n];
    // nhap cac phan tu cua mang(chi gom cac gia tri 0 va 1)
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort_array(arr, n);
    for (int j = 0; j < n; j++){
        printf("%d ", arr[j]);
    }
    return 0;
}