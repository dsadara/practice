// dequeue를 이용한 palindrome 판별 프로그램 미완성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_deque_charVer.h"

int determine_palindrome(DequeType *d, char *s)
{
    int i, len = strlen(s);
    char ch, reverse[20];
    for(i = 0 ; i < len ; i++)
    {
        ch = *(s + i);
        if (ch == ' ' || ch == '\'')
            continue;
        else if ( ch >= 'A' && ch <= 'Z')
            ch = ch - ('A' - 'a');
        add_rear(d, ch);
    }
    len = get_count(d);
    for(i = 0 ; i < len ; i++)
    {
        reverse[i] = delete_rear(d);
    }
    reverse[len] = '\0';
    if(strcmp(s, reverse) == 0) // palindrome 이면 
        return 1;
    else 
        return 0; 
}

int main(void)
{
    int res;
    DequeType d;
    init_deque(&d);
    char str[20] = "madam I'm Adam";
    res = determine_palindrome(&d, str);
    if(res == 0)
        printf("It is not palindrome\n");
    else 
        printf("It is palindrome\n");

    return 0;
}