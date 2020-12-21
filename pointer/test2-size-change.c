#include <stdio.h>

int func(int a)
{
	int b[a]; 
	b[0] = 200; 
	printf("%d\n", b[0]); 
}

int main()
{
	int a = 1;
	int b = 2; 
	void *v = &a; 
    //6422292 (v는 a의 주소값을 가르키므로)
	printf("v add %d \n", v);
	v++; 
    //6422293
	printf("v add %d \n", v);
    //1 2
	printf("%d %d\n", a, b);
    //200
	func(10); 
    //1 2
	printf("%d %d\n", a, b);
}
