#include <stdio.h>
#include <stdlib.h>

int countPrimes(int n)
{
    if (n <= 2) //return 0 if n == 0, 1, 2
    {
        return 0;
    }

    //create prime array; init w/ 2
    int *parray = malloc(n * sizeof(int));
    int j = 0;
    parray[j] = 2;
    int primeCounter = 1;

    int curNum;
    //loop to move thru narray; check if number is divisible by any in parray
    for (curNum = 3; curNum < n; curNum += 2) //increment by 2s (3, 5, 7, 9, etc...)
    {
        int isPrime = 1;    //assume prime (1)

        for (j = 0; j < primeCounter; j++)
        {
            int curPrime = parray[j];

            //don't attempt divide if divisor is greater than half of curNum; break
            if (curPrime * 2 > curNum)
            {
                isPrime = 1;
                break;
            }

            if (curNum % curPrime == 0) //if num is divisible by a prime, it's not prime; move to next elem in narray
            {
                isPrime = 0;    //denotes num is not prime
                break;
            }
        }

        if (isPrime == 1)   //increment counter if num is not divisible by any num in prime array
        {
            parray[primeCounter] = curNum;  //put newly identified prime num into parray
            primeCounter++;
        }
    }

    free(parray);

    return primeCounter;
}

int main()
{
    printf("%d\n", countPrimes(499979));
    return 0;
}
