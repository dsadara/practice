// 16 번 문제 : 회문(palindrome) 이 맞는지 판별하는 문제 (스페이스, 대문자, 구두점 등은 무시해야함 )
#include <stdio.h>
#include <string.h>
#include "normal_stack_charVer.h"

int determine_palindrome(Stacktype *s, char *str)
{
    int len = strlen(str), i;
    char ch;
    
    for (i = 0 ; i < len ; i++ )
    {
        ch = *(str + i);
        if (ch == ' ' || ch == '\'')
            continue;
        else if ( ch >= 'A' && ch <= 'Z')
            ch - ('A' - 'a');
        push(s, ch);
    }
    
    for ( i = 0; i < len ; i++)
    {
        ch = *(str + i);
        if (ch == ' ' || ch == '\'')
            continue;
        else if ( ch >= 'A' && ch <= 'Z')
            ch - ('A' - 'a');
        if( pop(s) != ch );
            return 0;
    }
    
    return 1; 
}

int main (void)
{
    int a;
    char str[30] = "madam";
    Stacktype s1;
    init_stack(&s1);
    a = determine_palindrome(&s1, str);
    if (a == 1)
        printf("It is palindrome\n");
    else
        printf("It isn't palindrome");
    return 0;
}