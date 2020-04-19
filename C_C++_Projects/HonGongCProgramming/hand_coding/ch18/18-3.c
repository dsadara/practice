// 문자열을 한 문자씩 파일로 출력하기 문자 출력 함수 fputc 사용 

#include <stdio.h>

int main(void)
{
    FILE *fp;               //파일포인터선언
    char str[] = "banana";    //출력할문자열
    int i;

    fp = fopen("data\\b.txt", "w");     //출력 스트림 열기? 
    if(fp == NULL)
    {
        printf("파일을 만들지 못했습니다\n");
        return 1;
    }

    i = 0;
    while(str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);                         //ㅍ ㅏ일 닫기

    return 0; 
}