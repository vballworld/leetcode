//
//  main.c
//  CompareVersions
//
//  Created by Joe Pak on 3/19/16.
//  Copyright © 2016 Joe Pak. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int returnFirstVersionPart(char *version)
{
    int firstVersionPartInt;
    char *ptr;
    
    //find first part of v.num len
    int firstPartLength = (int)(strchr(version, '.') - version);
    
    if (firstPartLength < 0)    //when v. doesn't have a '.'
    {
        firstVersionPartInt = (int)strtol(version, &ptr, 10);
        return firstVersionPartInt;
    }
    
    //copy first part of v.num & null-term
    char *firstPartStr = malloc((firstPartLength + 2) * sizeof(int));   //account for zero-based count & null-term
    //strlcpy(firstPartStr, version, firstPartLength + 1);  //some compilers don't like strlcpy
    strncpy(firstPartStr, version, firstPartLength);
    firstPartStr[firstPartLength] = '\0';
    
    firstVersionPartInt = (int)strtol(firstPartStr, &ptr, 10);  //convert str to int

    return firstVersionPartInt;
}

int returnSecondVersionPart(char *version)
{
    int secondVersionPartInt;
    int secondPartStartIndex = (int)(strchr(version, '.') - version);   //ex) xxx.yy; firstPartLength = 3
    char *secondPartStr = &version[secondPartStartIndex + 1];   //where yy (of xxx.yy) begins

    char *ptr;
    secondVersionPartInt = (int)strtol(secondPartStr, &ptr, 10);    //convert str to int

    return secondVersionPartInt;
}

int compareVersion(char *version1, char *version2)
{
    //convert first part of v.num into ints; compare them
    int v1FirstPartInt = returnFirstVersionPart(version1);
    int v2FirstPartInt = returnFirstVersionPart(version2);
    
    if (v1FirstPartInt > v2FirstPartInt)    //return 1 if v1 is greater
    {
        return 1;
    }
    else if (v1FirstPartInt < v2FirstPartInt)   //return -1 if v2 is greater
    {
        return -1;
    }
    //compare second part of v.num if first parts are equal
    else
    {
        int v1SecondPartInt = returnSecondVersionPart(version1);
        int v2SecondPartInt = returnSecondVersionPart(version2);
        
        //note v.nums w/o '.' is assigned "0" as second part val
        if (v1SecondPartInt > v2SecondPartInt)
        {
            return 1;
        }
        else if (v1SecondPartInt < v2SecondPartInt)
        {
            return -1;
        }
        //versions are identical
        else
        {
            return 0;
        }
    }
}

int main(int argc, const char * argv[])
{
    printf("%d\n", compareVersion("01", "1"));
    
    return 0;
}
