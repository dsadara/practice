//공백이나 제어 문자 입력 ab a_ aEnter

#include <stdio.h>

int main(void)
{
    char ch1, ch2;
    
    scanf("%c%c", &ch1, &ch2);          // scanf(" %c %c", &ch1, &ch2); 이렇게 하면 공백문자가 변수에 입력이 안되고 문자나 숫자만 입력이 된다.
    printf("[%c%c]", ch1, ch2);
    
    return 0;
}