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
    //function pointer
    //f는 size 10인 function의 array이고 
    //return type은 double이다.
    //parameter a 는 int const이고
    //parameter g는 size 10인 function이자 return type은 double이고 parameter 또한 double이다. 
	double (*f[10])(int const *a, double (*g[10])(double h)); 
	int (*q)(int, int, double); 

	int a = 200; 
	int (*ff)(int); 
	//ff는 f10과 같은 기능을 한다.
    ff = f10; 

    //a가 200이고 ff는 f10과같은 기능인 들어온 숫자에 + 10을 해주므로
    //210이 출력된다.
	printf("%d\n", ff(a)); 
	
}