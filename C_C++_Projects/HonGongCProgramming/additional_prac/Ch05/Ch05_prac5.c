#include <stdio.h>

int main(void)
{
    int rich = 150, // 가정형편을 저장할 변수
    tuition = 100,  // 등록금
    scholar = 0;    // 장학금
    double grade = 4.1;
    
    if((rich >= 100) && (grade >= 4.0))
        scholar = (double) tuition * 0.2;
    if((rich < 100))
        scholar = (double) tuition * 0.4;
    
    tuition -= scholar;
    
    printf("다음 학기 납입할 등록금은 %d만원 입니다.", tuition);
    
    return 0;
}