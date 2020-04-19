#include <stdio.h>

int main(void)
{
    int try =0, num , answer = 19;
    while(1)
    {
        printf("숫자입력(1부터 30까지) : ");
        scanf("%d", &num);
        try++;
        if(num == answer)
        {
            printf("정답입니다!");
            break;
        }
        else if(num > answer)
            printf("%d보다 작습니다! \n", num);
        else if(num < answer)
            printf("%d보다 큽니다! \n", num);
    }
    printf("시도한 횟수는 %d회 입니다", try);
    return 0;
}