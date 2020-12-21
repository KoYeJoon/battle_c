#include <stdio.h>

int main()
{
   // int a[2]={0,1};
   // int const *b = a;

    const int a = 99;
    int const *b = &a;

//   int const k = 100;
    //const이므로 수정이 안된다고 뜸
//    k=200;

    //const 벗기기
    *(int *)b = 200;
    
   // printf("%d %d\n",a[0],a[1]);
   //200
   printf("%d \n",a);
}