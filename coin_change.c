#include<stdio.h>
int min(int a, int b){
    return (a > b) ? a:b;
}

int coin_change(int current_amount, int coins[], int n, int amount){
    if (current_amount == amount) return 0;
    int min_numCoin = 1e9;
    for (int i = 0; i < n; i++){
        if (current_amount + coins[i] <= amount){
            min_numCoin = min(min_numCoin, 1 + coin_change(current_amount + coins[i], coins, n, amount));
        }
    }
    return min_numCoin;
}
int main(){

    return 0;
}