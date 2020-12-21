#include "led.h"

void*led_yellow_task(void*arg)
{
	int i;
	pinMode(YELLOW, OUTPUT);
	
	for(i=0; i<(int)arg; i++) {
		printf("I'm Yellow\n");
		digitalWrite(YELLOW, HIGH);
		sleep(3);
		//delay(1000);
		digitalWrite(YELLOW, LOW);
		sleep(3);
		//delay(1000);
	}
	pthread_exit(arg);
}


