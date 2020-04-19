#include <stdio.h>

int main(void)
{
    double avg;
    char grade;
    
    avg = 84.5;
    grade = 'B';
    
    printf("평균 : %.1lf\n", avg);
    printf("학점 : %c", grade);
    
    return 0;
}