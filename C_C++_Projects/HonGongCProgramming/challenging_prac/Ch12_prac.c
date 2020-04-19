// 353p 확인문제 3 

#include <stdio.h>

int main(void)
{
    char str[16];
    char *s = str;
    int cnt = 0;
    printf("단어 입력 : ");
    gets(str);
    printf("입력한 단어 %s\n", str);
    while(*s != '\0')
    {
        cnt++;
        if(cnt > 5)
            *s = '*';
        s++;
    };
    printf("생략한 단어 : %s", str);
    return 0;
}