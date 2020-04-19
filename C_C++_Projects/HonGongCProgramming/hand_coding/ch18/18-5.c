// stdin과 stdout을 사용한 문자 입출력

#include <stdio.h>

int main(void)
{
    int ch; // 입력할 문자를 저장할 변수
    while(1)
    {
        ch = fgetc(stdin);
        if (ch == EOF)
        {
            break;
        }
        fputc(ch, stdout);
    }

    return 0;
}