#include <stdio.h>

int main(void)
{
    int sum = 259;
    double avg = sum / 3.0;
    char grade;
    
    switch ((int)avg / 10)
    {
    case 10:
    case 9: 
    grade = 'A';
    break;                  // switch문에 case 실행문들은 중괄호가 없어도 break이 나올 때까지 모든 문장을 실행한다
    case 8: 
    grade = 'B';
    break;
    case 7: 
    grade = 'C';
    break;
    default: 
    grade = 'F';
    }
    printf("평균 : %.1lf, 학점 : %c", avg, grade);
    
    return 0;
}