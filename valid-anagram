#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAnagram (char *s, char *t);    //prototype

int isAnagram (char *s, char *t)
{
    int returnCode = 1;

    //initialize 2 alphabet arrays; a[0] = 'A', a[25] = 'Z'
    int array1[26] = {0};
    int array2[26] = {0};

    //read & process arrays
    int sl = strlen(s);
    int tl = strlen(t);

    //exit early if string lengths are not equal
    if (sl != tl)
    {
        returnCode = 0;
        return returnCode;
    }

    int i;
    int temp1;
    int temp2;
    for (i = 0; i < sl; i++)
    {
        temp1 = s[i] - 'a';
        temp2 = t[i] - 'a';

        //mark off use of a letter
        array1[temp1] += 1;
        array2[temp2] += 1;
    }

    //check if array 1 & 2 are equal (IOW, same chars used in strings)
    for (i = 0; i < 26; i++)
    {
        //exit if element values are not equal
        if (array1[i] != array2[i])
        {
            returnCode = 0;
            break;
        }
    }

    return returnCode;
}

int main()
{
    char str1[6] = "hello";
    char str2[6] = "there";

    printf("result: %d\n", isAnagram(str1, str2));

    return 0;
}
