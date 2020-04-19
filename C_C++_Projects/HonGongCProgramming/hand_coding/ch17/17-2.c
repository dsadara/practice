// 배열과 포인터를 멤버로 갖는 구조체 사용 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile      // 신상명세 구조체 선언
{
    char name[20];  // 이름을 저장할 배열멤버
    int age;    
    double height;
    char *intro;       // 자기소개를 위한 포인터
};

int main(void)
{
    struct profile chahun;

    strcpy(chahun.name, "ChaehyunLim");
    chahun.age = 24;
    chahun.height = 178.9;

    chahun.intro = (char *)malloc(80);  // 자기 소개를 저장할 공간 동적할당
    printf("let you introduce : ");
    gets(chahun.intro);

    printf("name : %s\n", chahun.name);
    printf("age : %d\n", chahun.age);
    printf("height : %.1lf\n", chahun.height);
    printf("introduce yourself : %s\n", chahun.intro);
    free(chahun.intro);

    return 0; 
    }