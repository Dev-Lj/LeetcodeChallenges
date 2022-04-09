// https://leetcode.com/problems/house-robber/

#include <stdio.h>

int rob_recursive(int* nums, int numsSize, int start_idx, int sum, int* memo){
    
    if (start_idx >= numsSize) {
        return sum;
    }

    sum += nums[start_idx];

    if(memo[start_idx] == -1) {
        int sum1 = rob_recursive(nums, numsSize, start_idx + 2, 0, memo);
        int sum2 = rob_recursive(nums, numsSize, start_idx + 3, 0, memo);
        
        if (sum1 > sum2) {
            memo[start_idx] = sum1;
        } else {
            memo[start_idx] = sum2;
        }
    }
    sum += memo[start_idx];
    return sum;
}

void init_memo(int* memo, int n) {
    for (int i=0;i<n;i++) {
        memo[i] = -1;
    }
}

int rob(int* nums, int numsSize){
    int memo[numsSize];
    init_memo(memo, numsSize);

    int rob_0 = rob_recursive(nums, numsSize, 0, 0, memo);
    int rob_1 = rob_recursive(nums, numsSize, 1, 0, memo);
    
    int result;
    if (rob_0 > rob_1) result = rob_0; else result = rob_1;
    return result;
}

/** To Run:
 * gcc 198/house_robber_1.c -o 198/house_robber_1.exe -g; .\198\house_robber_1.exe
 * */

int main() {
    int n = 4;
    int nums[] = {1,2,1,1};

    int result = rob(nums, n);

    printf("Result: %d \n", result);

    return 0;
}