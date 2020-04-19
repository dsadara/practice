//버퍼를 사용하는 문자 입력

#include <stdio.h>

int main(void)
{
    char ch;
    int i;
    /* 입력할 데이터의 수를 3으로 할 때 
    for(i = 0 ; i < 3 ; i++)
    {
        scanf("%c", &ch);
        printf("%c", ch);
    }
    */
    while (1)               // 데이터를 길이와 상관없이 화면에 출력하고 싶을 때
    {
        scanf("%c", &ch);
        if(ch == '\n')
            break;
        printf("%c", ch);
    }
    return 0;
}