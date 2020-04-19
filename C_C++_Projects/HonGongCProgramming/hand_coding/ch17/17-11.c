// 열거형을 사용한 프로그램, 열거형은 변수에 저장할 수 있는 정수 값을 기호로 정의하여 나열함

#include <stdio.h>

enum season {SPRING, SUMMER, FALL, WINTER}; //열거형 선언 각각 0, 1, 2, 3 이 된다 
enum season2 {spring = 5 , summer, fall  = 10, winter}; // 각각 5 6 10 11 이 된다. 

int main (void)
{

    enum season ss;     //열거형 변수 선언 
    enum season2 ss2;

    char *pc = NULL; //문자열을 저장할 포인터

    ss = SPRING; //열거 멤버의 값 대입
    switch(ss)
    {
        case 0: pc = "inline"; break;
        case 1: pc = "swimming"; break;
        case 2: pc = "trip"; break;
        case 3: pc = "skiing"; break;
    }
    printf("My seasonal hobby => %s\n", pc);

    ss2 = winter;
    switch(ss2)
    {
        case 5: pc = "inline"; break;
        case 6: pc = "swimming"; break;
        case 10: pc = "trip"; break;
        case 11: pc = "skiing"; break;
    }
    printf("Your seasonal hobby : => %s\n", pc);
    return 0;
}