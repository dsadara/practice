#include <stdio.h>

int main(void)
{
    int i, count = 0, j, num, redun = 0, a[6];
    
    while(1)
    {
        printf("로또번호입력 :");
        scanf("%d", &num);
        if( (num < 1) || (num > 45) )
        {
            printf("1부터 45까지의 수를 입력하시오");
            continue;
        }
        for(i = 0 ; i < count ; i++)
        {
            if(num == a[i])
            {
                printf("같은 번호가 있습니다!\n");
                redun = 1;
                break;
            }
        }
        if(redun != 1)
        {
            a[count] = num;
            count++;
        }
        else
        {
            redun = 0;
        }
        if(count == 6)
            break; 
    }
    printf("입력된 로또번호 : ");
    for(j = 0 ; j < 6 ; j++)
    {
        printf("   %d", a[j]);
    }
    return 0;
}