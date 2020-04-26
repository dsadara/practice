// dequeue를 이용한 palindrome 판별 프로그램 미완성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_deque_charVer.h"

int determine_palindrome(DequeType *d, char *s)
{
    int i, len = strlen(s);
    char ch;
    for(i = 0 ; i < len ; i++)
    {
        ch = *(s + i);
        add_rear(d, ch);
    }

}

int main(void)
{
    int res;
    DequeType d;
    char str[20] = "madam";
    res = determine_palindrome(&d, str);
    if(res == 0)
        printf("It is not palindrome\n");
    else 
        printf("It is palindrome\n");

    return 0;
}