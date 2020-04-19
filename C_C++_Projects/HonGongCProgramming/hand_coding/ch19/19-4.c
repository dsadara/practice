// 이미 정의된 매크로

#include <stdio.h>

void func(void);

int main(void)
{
    printf("컴파일 날짜와 시간 : %s, %s\n\n", __DATE__, __TIME__);
    printf("파일명 : %s\n", __FILE__);
    printf("함수명 : %s\n", __FUNCTION__);      // 매크로명이 사용된 함수 이름 
    printf("행번호 : %d\n", __LINE__);  // 매크로명이 사용된 행번호

    #line 100 "macro.c" // 행 번호를 100부터 시작 파일명은 macro.c로 표시
        func();         // 여기부터 행 번호는 100으로 시작
        return 0;
}

void func(void)
{
    printf("\n");
    printf("파일명 : %s\n", __FILE__);
    printf("함수명 : %s\n", __FUNCTION__);
    printf("행번호 : %d\n", __LINE__);
}