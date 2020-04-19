#include <stdio.h>

int main(void)
{
    int pos;        //양수를 입력할 변수
    int sum = 0;    //입력할 양수를 누적할 변수
    
    scanf("%d", &pos);
    while(pos > 0)
    {
        sum += pos;
        scanf("%d", &pos);
    }
    printf("누적된 값 : %d\n", sum);
    
    return 0;
}