// 16 ë²? ë¬¸ì œ : ?šŒë¬?(palindrome) ?´ ë§ëŠ”ì§? ?Œë³„í•˜?Š” ë¬¸ì œ (?Š¤?˜?´?Š¤, ???ë¬¸ì, êµ¬ë‘?  ?“±??? ë¬´ì‹œ?•´?•¼?•¨ )
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