#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    //create return array
    int *answer = malloc(sizeof(int) * (*returnSize));

    //iterate & find product per index
    int i;  //nums array counter
    int j;  //answer array counter
    for (j = 0; j < numsSize; j++)
    {
        int product = 1;    //init sum to 1

        for (i = 0; i < numsSize; i++)
        {
            //if index is not equal to self, multiply
            if (i != j)
            {
                product *= nums[i];
            }
        }

        answer[j] = product;
    }

    return answer;
}

int main()
{
    int nums[10] = {1,2,3,4};
    int numSize = 4;
    int *pSize = &numSize;

    printf("answer: %d\n", productExceptSelf(nums, numSize, pSize));
    return 0;
}
