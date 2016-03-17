#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s)
{
    bool answer;

    //turn arg into alphanumeric only array
    int l = strlen(s);
    char *s_new = malloc(sizeof(char) * (l + 1));   //need l + 1 space for '\0' char
    char *s_reverse = malloc(sizeof(char) * (l + 1));

    int i;  //arg (s) index
    int j = 0;  //alphanumeric only array index
    for (i = 0; i < l; i++)
    {
        if (isalnum(s[i]) > 0)
        {
            s_new[j] = tolower(s[i]);   //store lowercase alphanumeric char into new array
            j++;
        }
    }
    s_new[j] = '\0';    //properly terminate s_new

    strcpy(s_reverse, s_new);   //copy s_new into s_reverse; reverse it
    strrev(s_reverse);

    //if 2 arrays are equal --> palindrome
    answer = (strcmp(s_new, s_reverse) == 0) ? true : false;

    return answer;
}

int main()
{
    printf("%d\n", isPalindrome("A lad named E. Mandala"));
    return 0;
}
