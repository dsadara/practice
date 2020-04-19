// 구조체 변수 초기화와 대입연산

#include <stdio.h>

struct student
{
    int id; 
    char name[20];
    double grade;
};

int main(void)
{
    struct student s1 = {200, "ChaehyunLim", 3.9}, s2 = {201, "ChaeyoungLim", 3.6}, s3 = {202, "DongyeopLim", 4.2};

    struct student max;     // 최고 학점을 저장할 구조체 변수

    max = s1; //일단 s1 저장
    if(s2.grade > max.grade) max = s2;
    if(s3.grade > max.grade) max = s3;

    printf("Stud Num : %d\n", max.id);
    printf("Stud name : %s\n", max.name);
    printf("Stud Num : %.1lf\n", max.grade);

    return 0;

}