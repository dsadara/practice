// 파일의 내용을 화면에 출력하기 fgetc 사용

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("data\\a.txt", "r");
    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다...\n");
        return 1;
    }

    while (1)
    {
        ch = fgetc(fp); // 개방한 파일에서 문자 입력
        if (ch == EOF)  // 함수의 반환값이 EOF면 입력종료
        {
            break;
        }
        putchar(ch);    // 입력한 문자를 화면에 출력
    }

    fclose(fp);         // 파일 닫음

    return 0;
}