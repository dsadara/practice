// fread, fwrite 함수는 입출력할 데이터의 크기와 개수를 인수로 줄 수있음 -> 구조체나 배열과 같이 데이터양이 많은 경우도 파일에 쉽게 입출력할 수 있다.
// 또한 숫자와 문자 사이의 변환과정을 수행하지 않으므로 입출력 효율을 높일 수 있다.
// *fprintf 와 fread 의 차이!!
#include <stdio.h>

int main(void)
{
    FILE *afp, *bfp;
    int num = 10;
    int res;

    afp = fopen("data\\a.txt", "wt");        // 텍스트 모드로 출력 파일 개방
    fprintf(afp, "%d", num);                // num의 값을 문자로 변환하여 출력
    bfp = fopen("data\\b.txt", "wb");       // 바이너리 모드로 출력 파일 개방 
    fwrite(&num, sizeof(num), 1, bfp);      // num 의 값을 그대로 파일에 출력 

    fclose(afp);
    fclose(bfp);

    bfp = fopen("data\\b.txt", "rb"); // 바이너리 모드로 입력파일 개방
    fread(&res, sizeof(res), 1, bfp);
    printf("%d", res);

    fclose(bfp);
    return 0;
}
