// 353p 확인문제 해답
#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[80];           //문자열을 입력할 배열
    char res_str[80];       //생략 문자열을 저장할 배열
    char *star = "**********";
    int len;
    printf("단어 입력 : ");
    scanf("%s", str);
    len = strlen(str);      //입력한 단어의 길이 계산
    if (len <= 5)           //길이가 5 이하이면 그대로 복사
    {
        strcpy(res_str, str);
    }
    else                    //길이가 5보다 큰 경우는
    {   
        strncpy(res_str, str, 5);           //일단 다섯 문자만 복사
        res_str[5] = '\0';                  //마지막에 널 문자 저장
        strncat(res_str, star, len - 5);    //문자열의 길이만큼 별로 채우기 
    }
    printf("입력한 단어 : %s, 생략한 단어 : %s\n", str, res_str);
    return 0;
}