#include <stdio.h>

int main()
{
    int a[10] = {0,0,0,1,4,5,6,7,8,9};
    void *b;
    long long *c;

    //b=&a[0]과 같음
    //b = a;
    //type casting하면 됨 
    c = (long long *)a;

    //6422260, 0
    printf("%d, %d\n",a,*a);
    //61fef4, 0
    printf("%x, %llx\n",c,*c);

    //61fefc, 100000000
    printf("%x, %llx\n", c+1, *(c+1));
    
    float kk = 0.75f;
    //%x : integer를 16진수로 봄
    //0.75 : 1061158912, 3f400000
    printf("%f : %d, %x \n",kk, *(int *)&kk, *(int *)&kk);
}