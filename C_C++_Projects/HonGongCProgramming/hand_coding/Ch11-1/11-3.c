//getchar함수와 putchar함수 사용

#include <stdio.h>

int main(void)
{
    while(1)
    {
        int ch;
        ch = getchar();
        if(ch == -1)
            break;
        printf("입력한 문자 : ");
        putchar(ch);
        putchar('\n');
    }
    return 0;
}