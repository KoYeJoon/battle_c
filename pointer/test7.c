#include <stdio.h>

float f_f() {return 100.0; }
int f_i() {return 100; }


int main()
{
    //function pointer
	int (*f)(void); 
	float (*ff)(void); 
    //함수 할당해줌
	f = f_i; 
    //10
	printf("%d\n", f()); 
	ff = f_f; 
    //100.000000
	printf("%f\n", ff()); 

}