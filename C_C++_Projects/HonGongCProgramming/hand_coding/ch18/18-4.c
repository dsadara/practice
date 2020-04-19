// 기본적으로 개방되는 표준 입출력 스트림을 사용한 문자열 입력
#include <stdio.h>

int main(void)
{
    int ch;         // 입력한 문자를 저장할 변수

    while(1)
    {
        ch = getchar();     // 키보드에서  문자입력(표준입력스트림 stdin 사용 -> 키보드연결)
        if(ch == EOF)       // ctrl + z 로 입력종료
        {
            break;
        }
        putchar(ch);        // 화면에 문자 출력(표준출력스트림 stdout 사용 -> 모니터연결)
    }

    return 0;
}
