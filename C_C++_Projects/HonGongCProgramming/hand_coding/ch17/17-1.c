// 구조체를 선언하고 멤버를 사용하는 방법

#include <stdio.h>

struct student          // 구조체 선언
{
    int num;            // int 형 멤버
    double grade;       // double 형 멤버
};                     // 세미콜론 선언

int main(void)
{
    struct student s1;      // struct studnet 형 변수 선언

    s1.num = 2;
    s1.grade = 2.7;
    printf("Stud Num : %d\n", s1.num);
    printf("Stud Grade : %.1lf\n", s1.grade);

    return 0;
}

