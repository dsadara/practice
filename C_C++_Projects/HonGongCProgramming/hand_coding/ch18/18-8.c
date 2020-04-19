// 여러 줄의 문장을 입력하여 한 줄로 출력, fgets fputs 한 줄씩 입출력

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *ifp, *ofp;        // 파일 포인터 선언 
    char str[80];           // 입력할 문자열을 저장하 ㄹ배열
    char *res;              // fgets 함수의 반환값을 저장할 변수

    ifp = fopen("a.txt", "r");      // 입력 파일을 읽기 전용으로 개방
    if (ifp == NULL)
    {
        printf("입력 파일을 열지 못했습니다...\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");      // 출력 파일을 쓰기 전용으로 개방
    if (ofp == NULL)        // 개방 여부 확인
    {
        printf("출력 파일을 열지 못했습니다\n");
        return 1; 
    }

    while(1)        // 문자열을 입력하고 출력하는 과정 반복
    {
        res = fgets(str, sizeof(str), ifp);
        if(res == NULL)     // 반환값이 널 포인터면 반복 종료, End Of File 아니면 error 일떄 fgets 함수는 NULL을 반환한다 
        {
            break;
        }
        str[strlen(str) - 1] = '\0';    // 개행 문자 제거 
        fputs(str, ofp);
        fputs(" ", ofp); 
    }

    fclose(ifp);
    fclose(ofp);

    return 0; 
}