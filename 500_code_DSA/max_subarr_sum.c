#include<stdio.h>
#include<math.h>

int find_max_sum(int a[]){
    int max_sum = -1e9;
    for (int i = 0; i < 6; i++){
        int sum = 0;
        for (int j = i; j < 6; j++){
            sum += a[j];
            if (max_sum < sum) max_sum = sum;
        }
    }
    return max_sum;
}
// this function return the largest value in 3 parameters 
int max_3 (int a, int b, int c){
    if (a > b)
    {
        if (a > c) return a;
        else return c;
    }
    else {
        if (b > c) return b;
        else return c;
    }
}

// this function return the largest value in 2 parameters
int max_2(int a, int b){
    return (a > b) ? a : b;
}
// find subarr which has largest weight - the begin element has right_index
int find_maxRight(int a[], int right_index, int left_index){
    int max_sumRight = -1e9;
    int sum = 0;
    for (int index = right_index; index <= left_index; index ++){
        sum += a[index];
        if (sum > max_sumRight){
            max_sumRight = sum;
        }
    }
    return max_sumRight;
}

// find subarr which has largest weight - the last element has left_index
int find_maxLeft(int a[], int right_index, int left_index){
    int max_sumLeft = -1e9;
    int sum = 0;
    for (int index = left_index; index >= right_index; index --){
        sum += a[index];
        if (sum > max_sumLeft){
            max_sumLeft = sum;
        }
    }
    return max_sumLeft;
}

// use recursion to find the subarr having largest sum
int find_max_sum_v2(int a[], int i, int j){
    int max_value;
    if (i == j) return a[i];
    else{
        int mid = (i + j) / 2;
        int max_Left = find_max_sum_v2(a, i, mid);
        int max_Right = find_max_sum_v2(a, mid + 1, j);
        int max_Mid = find_maxLeft(a, i, mid) + find_maxRight(a, mid + 1, j);
        max_value = max_3(max_Left, max_Right, max_Mid);
    }
    return max_value;
}

// use dynamic program
int find_max_sum_v3(int a[], int n){
    int max_sum = a[0];
    int tmp_sum = a[0];
    for (int index = 1; index < n; index++){
        tmp_sum += a[index];
        tmp_sum = max_2(tmp_sum, a[index]);
        max_sum = max_2(max_sum, tmp_sum);
    }
    return max_sum;
}

int main(){
    int arr[6] = {-2, 11, -4, 13, -5, 2};
    int max_subarr1 = find_max_sum_v2(arr, 0, 5);
    int max_subarr2 = find_max_sum_v3(arr, 6);
    printf("%d %d", max_subarr1, max_subarr2);
    return 0;
}