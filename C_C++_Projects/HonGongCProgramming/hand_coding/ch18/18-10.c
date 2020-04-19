// 스트림 파일의 버퍼 공유 문제와 fflush 함수 -> 입출력 함수들이 버퍼를 공유하면 문제가 발생 
// fscanf 함수가 개행 문자를 버퍼에 남겨 놓아서 생기는 문제 -> fgets 함수는 개행 문자가 나올떄까지 문자열을 입력 

#include <stdio.h>

int main(void)
{
    FILE *fp;       // 파일 포인터
    int age;        // 나이 저장 변수
    char name[20];  // 이름 저장 배열

    fp = fopen("data\\b.txt", "r");

    fscanf(fp, "%d", &age);     // 나이 입력
    while(fgetc(fp) != '\n'){}            
    fgets(name, sizeof(name), fp);  // 이름 입력

    printf("나이 : %d, 이름 : %s", age, name);      // 입력 데이터 출력
    fclose(fp);     // 파일 닫음

    return 0;
}