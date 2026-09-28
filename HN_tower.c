#include<stdio.h>

void solveTower(int n, char colA, char colB, char colC){
    if (n == 1){
        printf("%c -> %c\n", colA, colB);
    }
    else if (n == 2){
        printf("%c -> %c\n", colA, colC);
        printf("%c -> %c\n", colA, colB);
        printf("%c -> %c\n", colC, colB);
    }
    else {
        solveTower(n - 1, colA, colC, colB);
        solveTower(1, colA, colB, colC);
        solveTower(n - 1, colC, colB, colA);
    }
}

int main(){
    solveTower(4, 'A', 'B', 'C');
    return 0;
}