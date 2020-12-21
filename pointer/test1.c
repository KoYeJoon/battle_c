#include <stdio.h>
void set_elmt(int *a){
    a[0] = 3;
}
int main()
{
    const int a = 10;
    int *b = &a;
    //10
    printf("%d\n",a);

    //const 벗기기 -> const로 선언된 a이지만 값이 변동됨
    int*const c = b;
    *c = 100;
    //100
    printf("%d \n",a);
}