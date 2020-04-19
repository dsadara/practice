#include <stdio.h>

int main(void)
{
    char name[20] = "홍길동";
    int age = 17;
    double height = 190.0;
    char Btype[4] = "AB";
    
    age += 10;
    height -= 0.5;
    
    printf("10년 후의 프로필...\n");
    printf("이름 : %s\n", name);
    printf("나이 : %d살\n", age);
    printf("키 : %.1lfcm\n", height);
    printf("혈액형 : %s형\n", Btype);
    
    return 0;
}