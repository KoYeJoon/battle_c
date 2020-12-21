#include <stdio.h>

int main()
{
    int a[10], b[30],c[40];
    int *t[3];
    t[0] = a;
    t[1] = b;
    t[2] = c;
    t[1][35] = 200;

    //200
    //b[30]이므로 오류가 떠야하지만, 30근처에 있으면 가끔 인식하지 못하고 출력되는 경우가 발생한다.
    printf("%d\n",b[35]);
    for (int i = 0 ; i < 40 ; i++)	
		printf("%d ", c[i]); 

}