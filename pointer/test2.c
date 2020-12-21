#include <stdio.h>
int main()
{
    int a[2] ;
    int const *b = a;

    *(int *)b = 200;

    //200 2322432
    //a[2]를 static int로 선언한다면  a[1]의 출력값이 0이 됨을 알 수 있다.
    //static -> 선언과 동시에 초기화하지 않으면 0으로 초기화됨을 알 수 있음
    printf("%d %d\n", a[0], a[1]);
}