#include <stdio.h>

int disp_menu(void);

int main(void)
{
    int sel;
    
    sel = disp_menu();
    printf("선택된 메뉴는 %d번 입니다.\n", sel);
    
    return 0;
}

int disp_menu(void)
{
    int menu_num;
    printf("1.볶음짬뽕\n");
    printf("2.콩나물국밥\n");
    printf("3.바지락칼국수\n\n");
    printf("# 메뉴를 선택하세요 : ");
    scanf("%d", &menu_num);
    return menu_num;
}