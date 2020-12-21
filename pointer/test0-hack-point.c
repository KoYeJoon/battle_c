#include <stdio.h>
void func(int *p)
{
    int *q = p;
    *q = 100;
    q++;
    *q = 200;
}

int main()
{
    int a = 1;
    int b = 2;
    int *pa, *pb;
    long long pp;
    pa = &a;
    pb = &b;
    pp = (long long)pa;

    //1 2
    printf("%d %d\n", a, b);
    //&a 파라미터로 넣어보고 &b 파라미터로 넣어보기
    func(&b);

    //&a 를 넣으면 100 2가 출력됨
    // 200 100
    printf("%d %d\n",*pa,*pb);
    // 6422284 6422280 200
    printf("%d %d %d\n",pa,pb,*(int  *)pp);
    // 200 6422284 200 200 
    printf("%d, %d, %d, %d\n", a, &a, *(&a), *(int *)(long long)(&a) );


}