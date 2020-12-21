
#include <stdio.h>

void set_elmt(int *a)
{
    a[0]=3;
}

int main()
{
    const int a = 10;
    //warning 발생
    int *b = &a;

    //10
    printf("%d\n",a);



    //b는 a의 주소를 참조하므로 함수를 통해 b를 set하여 a의 값을 3으로 설정
    set_elmt(b);
    //3
    printf("%d\n",a);
    
    
    //c는 b가 가르키는 a의 주소를 가르키게 된다. 
    int*const c = b;
    *c = 100;
    //100
    printf("%d \n",a);
}