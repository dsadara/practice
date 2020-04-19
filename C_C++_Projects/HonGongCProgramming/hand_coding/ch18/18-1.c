// 파일을 열고 닫는 프로그램
#include <stdio.h>

int main(void)
{
    FILE *fp;       // 파일 포인터

    fp = fopen("C:\\Users\\catnoir\\Desktop\\C_C++_Projects\\HongGongC\\hand_coding\\ch18\\data\\a.txt", "r");       // a.txt 파일을 읽기 전용으로 개방
    printf("잠시만...");
    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다\n");
        return 1; 
    }
    printf("파일이 열렸습니다\n");
    fclose(fp);


    return 0;
}
