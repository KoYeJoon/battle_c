#include "led.h"

void*led_green_task(void*arg)
{
	int i;
	pinMode(GREEN, OUTPUT);
	for(i=0; i<(int)arg; i++) {
		printf("I'm Green\n");
		digitalWrite(GREEN, HIGH);
		sleep(2);
		//delay(1000);
		digitalWrite(GREEN, LOW);
		sleep(2);
		//delay(1000);
	}
	pthread_exit(arg);
}


