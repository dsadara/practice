// typedef 을 사용한 형 재정의
// typedef 을 사용하면 자료형 이름에서 struct 과 같은 예약어(enum, union 등) 생략가능, typedef 으로 기본 자료형도 재정의 가능 
#include <stdio.h>

struct student
{
    int num;
    double grade; 
};
typedef struct student Student;
typedef unsigned int nbyte; 

typedef struct student2     // 이렇게 형 선언과 동시에 재정의 할 수도 있음 
{
    int num;
    double grade; 
} Student2;

void print_data(Student *ps);

int main(void)
{
    Student s1 = {315, 4.2};        //Student 형 변수 선언과 초기화
    nbyte n = 100;
    printf("print unsigned int : %d\n", n);
    print_data(&s1);                //Student 형(구조체) 변수의 주소 전달

    return 0;
}

void print_data(Student *ps)
{
    printf("Stud Num : %d\n", ps -> num);
    printf("grade : %.1lf\n", ps -> grade);
}