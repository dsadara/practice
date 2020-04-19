// 다른 구조체를 멤버로 갖는 구조체

#include <stdio.h>
#include <string.h>

struct profile
{
    int age;
    double height;
};

struct student
{
    struct profile pf;
    char id[20];
    double grade;
};

int main(void)
{
    struct student chahun;

    chahun.pf.age = 24;
    chahun.pf.height = 178.4;
    strcpy(chahun.id, "2016253019");
    chahun.grade = 3.9;

    printf("age : %d", chahun.pf.age);
    printf("height : %.1lf", chahun.pf.height);
    printf("student id : %s", chahun.id);
    printf("grade : %.1lf", chahun.grade);

    return 0;
}