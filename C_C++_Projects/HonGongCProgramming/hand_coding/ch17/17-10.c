// 공용체를 사용한 학번과 함점 데이터 처리,
// 공용체는 선언 방식이 구조체와 비슷하지만 모든 멤버가 하나의 저장공간을 같이 사용  

#include <stdio.h>

union student       // 공용체 선언
{
    int num;
    double grade;
};

int main(void)
{
    union student s1 = { 315 }; // 공용체 변수의 크기는 멤버중에서 크기가 가장 큰 멤버로 결정됨 -> union student 변수 선언하면 double의 크기인 8바이트 저장공간이 할당됨 
    // 공용체 변수의 초기화는 중괄호를 사용하여 첫 번째 멤버만 초기화 ( 첫번쨰 멤버가 아니면 멤버 접근 연산자 . 로 멤버를 직접 지정)
    union student s2 = { .grade = 3.5};
    s1.grade = 4.4;             // num 멤버와 같은 공간을 사용하므로 메모리를 덮어씌우고 대입
    s2.num = 123;
    printf("grade : %.1lf, %.1lf\n", s1.grade, s2.grade);
    printf("Stud Num : %d ,%d \n", s1.num, s2.num);

    return 0; 
}