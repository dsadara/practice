// 16 �? 문제 : ?���?(palindrome) ?�� 맞는�? ?��별하?�� 문제 (?��?��?��?��, ???문자, 구두?�� ?��??? 무시?��?��?�� )
#include <stdio.h>
#include <string.h>
#include "normal_stack_charVer.h"

int determine_palindrome(Stacktype *s1, char *str)
{
    int len = strlen(str), i;
    element ch;
    
    for (i = 0 ; i < len ; i++ )
    {
        ch = *(str + i);
        if (ch == ' ' || ch == '\'')
            continue;
        else if ( ch >= 'A' && ch <= 'Z')
            ch = ch - ('A' - 'a');
        push(s1, ch);
    }
    
    for ( i = 0; i < len ; i++)
    {
        ch = *(str + i);
        if (ch == ' ' || ch == '\'')
            continue;
        else if ( ch >= 'A' && ch <= 'Z')
           ch = ch - ('A' - 'a');
        if( pop(s1) != ch )
            return 0;
    }
    
    return 1; 
}

int main (void)
{
    int a;
    char str[30] = "madam I'm Adam";
    Stacktype s1;
    init_stack(&s1);
    a = determine_palindrome(&s1, str);
    if (a == 1)
        printf("It is palindrome\n");
    else
        printf("It isn't palindrome\n");
    return 0;
}