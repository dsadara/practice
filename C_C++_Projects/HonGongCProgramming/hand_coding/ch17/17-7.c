// 구조체 배열 

#include <stdio.h>

struct address      // 주소록을 만들 구조체 선언
{
    char name[20];  // 이름을 저장할 멤버
    int age;
    char tel[20];
    char addr[80];  
};

int main(void)
{
    struct address list[3] = {
        {"Liam", 24, "010-9874-8852", "Jinhae"},
        {"Harvey", 31, "010-5286-1477", "Tokyo"},
        {"Dongyeop", 29, "010-3101-7113", "Seoul"}
    };

    int i;

    for (i = 0 ; i < 3 ; i++)
    {
        printf("%10s%5d%15s%20s\n",
            list[i].name, list[i].age, list[i].tel, list[i].addr);
    }

    return 0;
}