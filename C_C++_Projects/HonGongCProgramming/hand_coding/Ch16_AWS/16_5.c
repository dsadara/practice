//동적 할당 영역에 저장한 문자열을 함수로 처리 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char **ps);

int main(void)
{
    char temp[80];
    char *str[21] = { 0 };      // 문자열을 연결할포인터 배열, 널 포인터로 초기화 
    int i = 0;
    
    while (i < 20)              // 최대 20개 까지 입력
    {
        printf("문자열을 입력하세요 : ");
        gets(temp);
        if(strcmp(temp, "end") == 0) break;
        str[i] = (char *)malloc(strlen(temp) + 1);       // strlen 함수는 널문자 제외한 갯수 출력하므로 개수 1개 를 더 추가 해줌
        strcpy(str[i], temp);
        i++;
    }
    print_str(str);
    
    for( i = 0 ; str[i] != NULL ; i++)
    {
        free(str[i]);
    }
    
    return 0;
}

void print_str(char **ps)
{
    while (*ps != NULL)
    {
        printf("%s\n", *ps);
        ps++;
    }
}