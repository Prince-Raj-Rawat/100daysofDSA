#include <stdio.h>
#include <stdlib.h>



int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    for(int i = 0; i < numsSize-1; i ++){
        for (int j = 1; j< numsSize; j++){
            if(i==j){
                continue;
            }
            if ((nums[i]+nums[j])== target){
                result[0]=i;
                result[1]=j;       }
        }
    }
    return result;
    
}
int main (){
    int a[4]={2,7,11,15};
    int target = 9;
    int size;
    int *result = twoSum(a,4,9,&size);
    printf("%d %d",a[result[0]],a[result[1]]);
    return 0;

}
