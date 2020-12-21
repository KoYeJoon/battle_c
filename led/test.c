#include <stdio.h>
#include <wiringPi.h>	//wiringPi.h Add header
//gcc test.c -lwiringPi
int main()
{
	int i;
	if(wiringPiSetup()==-1) return -1;
	pinMode(29,OUTPUT); //set pin mode 29(BCM 21 == wiringPi 29)
	for(i=0;i<5;i++)
	{
		digitalWrite(29,1);	//turn On LED (1)
		delay(500);	//0.5s delay
		digitalWrite(29,0);	//turn off LED (0)
		delay(500);	//0.5s delay
	}
	
	return 0;
}
