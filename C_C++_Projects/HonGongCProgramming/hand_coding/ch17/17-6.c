// 구조체 포인터의 사용

#include <stdio.h>

struct score
{
    int kor;
    int eng;
    int math;
};

int main(void)
{
    struct score chahun = {90, 80, 70}; // 구조체 변수 선언과 초기화
    struct score *ps =  &chahun;

    printf("Kor : %d\n", (*ps).kor);   // 구조체 포인터로 멤버 접근
    printf("Eng : %d\n", ps -> eng);   // -> 연산자 사용 
    printf("math : %d\n", ps -> math);

    return 0;
}