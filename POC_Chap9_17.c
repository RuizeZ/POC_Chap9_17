/*
ruizeZ
6/15/2020
Based on the input Format and digits output desired result. More detail please see readme
*/

#include <stdio.h>
#include <string.h>
char *edit( char *pattern, char const *digits );
int main(void)
{
    char inputpattern[100];
    char inputdigits[100];
    printf("Enter pattern: ");
    gets(inputpattern);
    printf("Enter digits: ");
    gets(inputdigits);
    edit(inputpattern, inputdigits);
}

char *edit( char *pattern, char const *digits )
{
    int signif = 0;
    char *returnadd;
    int digitsi = 0;
    for (int i = 0; i < strlen(pattern); i++)
    {
        if (pattern[i] == '#')
        {
            if (digitsi > strlen(digits))
            {
                break;
            }
            if (signif == 0)
            {
                if ((digits[digitsi] == ' ') || (digits[digitsi] == '0'))
                {
                    pattern[i] = pattern[0];
                    digitsi++;
                }
                else
                {
                    pattern[i] = digits[digitsi];
                    digitsi++;
                    signif = 1;
                    returnadd = &(pattern[i]);
                }  
            }
            else if (signif == 1)
            {
                if (digits[digitsi] == ' ')
                {
                    pattern[i] = '0';
                    digitsi++;
                }
                else
                {
                    pattern[i] = digits[digitsi];
                    digitsi++;
                }
            }  
        }
        else if (pattern[i] == '!')
        {
            if (digitsi > strlen(digits))
            {
                break;
            }
            if (signif == 0)
            {
                if (digits[digitsi] == ' ')
                {
                    pattern[i] = '0';
                    digitsi++;
                    signif = 1;
                    returnadd = &(pattern[i]);
                }
                else
                {
                    pattern[i] = digits[digitsi];
                    digitsi++;
                    signif = 1;
                    returnadd = &(pattern[i]);
                }
            }
            else
            {
                pattern[i] = digits[digitsi];
                digitsi++;
            }
        }
        else
        {
            if (signif == 0)
            {
                pattern[i] = pattern[0];
            }
            
        }
    }
    printf("result: %s\n",pattern);
    printf("return: %c\n",*returnadd);
    return returnadd;
}