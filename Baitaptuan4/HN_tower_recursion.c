#include<stdio.h>

void solveTower(int num_dish, char source_peg, char helper_peg, char des_peg){
    if (num_dish == 1){
        printf("Pop dish from %c, push into %c\n", source_peg, des_peg);
    }
    else if (num_dish == 2){
        printf("Pop dish from %c, push into %c\n", source_peg, helper_peg);
        printf("Pop dish from %c, push into %c\n", source_peg, des_peg);
        printf("Pop dish from %c, push into %c\n", helper_peg, des_peg);
    }
    else {
        solveTower(num_dish - 1, source_peg, des_peg, helper_peg);
        solveTower(1, source_peg, helper_peg, des_peg);
        solveTower(num_dish - 1, helper_peg, source_peg, des_peg);
    }
}

int main(){
    int n; scanf("%d", &n);
    char source_peg = 'A', helper_peg = 'C', des_peg = 'B';
    solveTower(n, source_peg, helper_peg, des_peg);
    return 0;
}