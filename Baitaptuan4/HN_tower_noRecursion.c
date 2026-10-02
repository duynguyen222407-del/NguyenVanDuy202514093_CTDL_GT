#include<stdio.h>
int pow(int x, int y){
    int result = 1;
    for (int i = 0; i < y; i++){
        result *= x;
    }
    return result;
}

void interact_peg(char from_peg, char to_peg, int from_dish[]
                  , int to_dish[], int *from, int *to, int *from_state, int *to_state){
    printf("Pop dish from %c, push into %c\n", from_peg, to_peg);
    *to_state = *from_state;
    *to += 1;
    to_dish[*to] = *to_state;

    from_dish[*from] = 0;
    *from -= 1;
    if(*from < 0){
        *from_state = 0;
    }
    else *from_state = from_dish[*from];
}

void solve_HNtower(int num_dish, char source_peg, char helper_peg, char des_peg){
    if (num_dish % 2 == 0){
        char tmp = helper_peg;
        helper_peg = des_peg;
        des_peg = tmp;
    }
    int source_dish[num_dish];
    int helper_dish[num_dish];
    int des_dish[num_dish];
    for (int i = 0; i < num_dish; i++){
        source_dish[i] = num_dish - i;
        helper_dish[i] = 0;
        des_dish[i] = 0;
    }
    int source = num_dish - 1;
    int helper = -1, des = -1;
    int current_state[3] = {1, 0, 0};

    for (int i = 1; i <= pow(2, num_dish) - 1; i++){
        if (i % 3 == 1){
            // interact between source and des
            if (current_state[0] == 0){
                interact_peg(des_peg, source_peg, des_dish, source_dish, &des, &source, &current_state[2], &current_state[0]);
            }
            else if (current_state[2] == 0){
                interact_peg(source_peg, des_peg, source_dish, des_dish, &source, &des, &current_state[0], &current_state[2]);
            }
            else if (current_state[0] < current_state[2]){
                interact_peg(source_peg, des_peg, source_dish, des_dish, &source, &des, &current_state[0], &current_state[2]);
            }
            else {
                interact_peg(des_peg, source_peg, des_dish, source_dish, &des, &source, &current_state[2], &current_state[0]);
            }
        }
        else if(i % 3 == 2){
            //interact between source and helper
            if (current_state[0] == 0){
                interact_peg(helper_peg, source_peg, helper_dish, source_dish, &helper, &source, &current_state[1], &current_state[0]);
            } else if (current_state[1] == 0){
                interact_peg(source_peg, helper_peg, source_dish, helper_dish, &source, &helper, &current_state[0], &current_state[1]);
            }
            else if (current_state[0] < current_state[1]){
                interact_peg(source_peg, helper_peg, source_dish, helper_dish, &source, &helper, &current_state[0], &current_state[1]);
            }
            else {
                interact_peg(helper_peg, source_peg, helper_dish, source_dish, &helper, &source, &current_state[1], &current_state[0]);
            }
        }
        else {
            //interact between helper and des
            if (current_state[1] == 0){
                interact_peg(des_peg, helper_peg, des_dish, helper_dish, &des, &helper, &current_state[2], &current_state[1]);
            }
            else if (current_state[2] == 0){
                interact_peg(helper_peg, des_peg, helper_dish, des_dish, &helper, &des, &current_state[1], &current_state[2]);
            }
            else if (current_state[1] < current_state[2]){
                interact_peg(helper_peg, des_peg, helper_dish, des_dish, &helper, &des, &current_state[1], &current_state[2]);
            }
            else {
                interact_peg(des_peg, helper_peg, des_dish, helper_dish, &des, &helper, &current_state[2], &current_state[1]);
            }
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    char source_peg = 'A';
    char helper_peg = 'C';
    char des_peg = 'B';
    solve_HNtower(n, source_peg, helper_peg, des_peg);
    return 0;
}