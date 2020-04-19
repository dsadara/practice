#include <stdio.h>


void auto_func(void);
void static_func(void);

int main(void)
{
    int i;
    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for(i = 0 ; i < 3 ; i++)
    {
        auto_func();
    };
    
    printf("정적 지역 변수(static)를 사용한 함수...\n");    
    for (i = 0 ; i < 3 ; i++)
    {
        static_func();
    };
    
    return 0;
}

void auto_func(void)
{
    auto int a = 0;
    
    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a;                   //정적 지역 변수는 프로그램이 끝날 때까지 존재함 -> 함수가 반환되어도 증가한 값이 그대로 남아있다 
    
    a++;
    printf("%d\n", a);
}