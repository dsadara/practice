// 구조체 변수를 함수 매개변수에 사용

#include <stdio.h>


struct vision       // 시력을 저장하는 구조체 
{
    double left;
    double right;
};

struct vision exchange(struct vision human1);       // 구조체 반환값 그리고 구조체 인수 선언 

int main()
{
    struct vision human1;

    printf("Enther the vision : ");

    scanf("%lf%lf", &(human1.left), &(human1.right));
    human1 = exchange(human1);
    printf("Changed vision : %.1lf  %.1lf\n", human1.left, human1.right);

    return 0; 
}

struct vision exchange(struct vision human1)
{
    double temp; 

    temp = human1.left;
    human1.left = human1.right;
    human1.right = temp;

    return human1;
}