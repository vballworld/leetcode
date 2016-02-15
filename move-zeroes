#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int *nums, int numsSize);   //prototype

void moveZeroes(int *nums, int numsSize)
{
    int i;  //index of left-most "0" element
    int j;  //current reading index in array

    //find i & j's starting point
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            j = i;  //also init j to i's starting position
            break;
        }
    }

    /*Read array:
    if nums[j] == 0 --> j++
    if nums[j] != 0 --> switch nums[j] & nums[i], i++, j++
    */
    int temp;
    for ( ; j < numsSize; )
    {
        if (nums[j] == 0)
        {
            j++;
        }
        else
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            i++;
            j++;
        }
    }

    /* debug: print array
    for (i = 0; i < numsSize; i++)
    {
        printf("%d   ", nums[i]);
    }
    */
}

int main()
{
    int array1[8] = {1, 1, 2, 3, 0, 0, 4, 4};
    moveZeroes(array1, 8);

    return 0;
}
