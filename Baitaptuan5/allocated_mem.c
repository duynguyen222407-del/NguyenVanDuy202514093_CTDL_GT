#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int *) malloc(5 * sizeof(int));
    if (ptr == NULL){
        printf("Failed");
        return 1;
    }
    ptr = (int *) realloc(ptr, 8 * sizeof(int));
    if (ptr == NULL){
        printf("Reallocating failed");
        return 1;
    }
    for (int i = 0; i < 5; i++){
        *(ptr + i) = i;
    }
    ptr = (int *) realloc(ptr, 5 * sizeof(int));
    if (ptr == NULL){
        printf("Reallocating failed");
        return 1;
    }
    for (int i = 0; i < 5; i++){
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
}