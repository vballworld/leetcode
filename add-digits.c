#include <stdio.h>
#include <stdlib.h>

int addDigits(int num); //prototype

int addDigits(int num)
{
    int answer;

    //if input == 0, answer = 0
    if (num == 0)
    {
        answer = 0;
        return answer;
    }

    answer = num % 9;   //calculate digital root

    //if argument is multiple of 9, return 9
    if (answer == 0)
    {
        answer = 9;
    }

    return answer;
}

int main()
{
    printf("digital root of %d: %d\n", 12, addDigits(12));
    return 0;
}
