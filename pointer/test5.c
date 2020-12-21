#include <stdio.h>
int f10(int a)
{
    return a+10;
}
int f5(int a)
{   return a+5;}
int f1(int a)
{   return a+1;}
int f22(int a)
{   return a+22;}


int main()
{
    int a=200;
    int b = 888;
    //함수 포인터의 리스트 
    int (*f[4])(int) = {f10, f5,f1,f22};
    
    //if 혹은 switch문 필요없이 아래와 같이 사용가능
    //20
    //888%4 = 0 -> f[0] 인 f10 실행
    //f10 으로 인해 10+10 = 20 이 출력됨
    printf("%d\n",f[b%4](10));
}