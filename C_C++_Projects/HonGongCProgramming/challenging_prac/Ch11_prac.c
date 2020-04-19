#include <stdio.h>

int main(void)
{
    char ch;
    int max = 0, num = 0;
    
    while( scanf("%c", &ch) != EOF )
    {
        
        if( ch != '\n')
            num++;
        else if(max < num)
        {
            max = num; 
            num = 0; 
        }
        else
        {
            num = 0;
        }
        
    }
    
    printf("가장 긴 단어의 길이 : %d", max);
    
    return 0;
}