#include <stdio.h>

#include <stdlib.h>




int main(void)

{

     int num;

     int *ap;

     int i, j, cnt = 0;




     printf("> 양수 입력 : ");

     scanf("%d", &num);


     ap = (int *)malloc((num - 1) * sizeof(int));

     if(ap == NULL)

     {

           printf("메모리 부족...\n");

           exit(1);

     }




     for(i = 0; i < (num - 1); i++)
     {

           ap[i] = i + 2;

     }

     i = 0;



     while(1)
     {

           while((ap[i] == 0) && (i < (num - 2)))       //'ap[i] == 0' 배열 요소가 소수이고,  'i < (num -2)' 입력한 양수 미만 일떄

           {

                i++;

           }



           if (i == (num - 3)) break;               // 마지막 배열 요소를 가리킬때 반복문 벗어나기



           for(j = i + 1; j < (num - 1); j++)
           {

                if((ap[j] % ap[i]) == 0)

                {

                      ap[j] = 0;        // 양수가 소수에 나누어 떨어지면 그 양수는 소수가 됨 -> 배열요소에 0을 대입함 

                }

           }

           i++;

     }




     for(i = 0; i < (num - 1); i++)     // 배열 요소 출력 

     {

           if(ap[i] != 0)

           {

                printf("%5d", ap[i]);

           }

           else

           {

                printf("%5c", 'X');

           }



           if((i + 1) % 5 == 0)

           {

                printf("\n");

           }

     }




     free(ap);




     return 0;

}

