#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[50];
    int i, count = 0;
    printf("문장입력 : ");
    gets(str1);
    for(i = 0 ; i < 50 ; i++)
    {
        if((str1[i] >= 65) && (str1[i] <= 90))
        {
            str1[i] += 32;
            count++;
        }
    }
    printf("바뀐문장 : %s\n", str1);
    printf("\n");
    printf("바뀐문자 수 : %d", count);
    
    return 0;
}