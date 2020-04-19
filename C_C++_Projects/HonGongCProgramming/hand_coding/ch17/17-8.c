// 구조체 배열을 처리하는 함수(함수에서 -> 연산자를 사용하여 구조체 맴버에 접근, 배열 표현식으로 구조체 멤버에 접근할 수도 있다)

#include <stdio.h>

struct address      // 주소록을 만들 구조체 선언
{
    char name[20];  // 이름을 저장할 멤버
    int age;
    char tel[20];
    char addr[80];  
};

void print_list(struct address * lp);

int main(void)
{
      struct address list[3] = {
        {"Liam", 24, "010-9874-8852", "Jinhae"},
        {"Harvey", 31, "010-5286-1477", "Tokyo"},
        {"Dongyeop", 29, "010-3101-7113", "Seoul"}
    };

    print_list(list);

    return 0;
}

void print_list(struct address * lp)
{
    int i;

    for (i = 0 ; i < 3 ; i++)
    {
        printf("%10s%5d%15s%20s\n", (lp + i) -> name, (lp + i ) -> age
        , (lp + i) -> tel, (lp + i) -> addr);
    }
}