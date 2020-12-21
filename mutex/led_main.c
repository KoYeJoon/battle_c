#include "led.h"


void led_red_task()
{
	int i;
	pinMode(RED, OUTPUT);
	
	for(i=0; i<10; i++) {
		printf("I'm Red\n");
		digitalWrite(RED, HIGH);
		sleep(1);
		//delay(1000);
		digitalWrite(RED, LOW);
		sleep(1);
		//delay(1000);
	}

	
}

int main(int argc, char *argv[])
{
	int mode_num;
	int num;
	pthread_t tid1, tid2;
	
	
	
	wiringPiSetup();
	

	
	if(argc < 2) {
		led_red_task();
		pthread_exit(NULL);
	}
	
	mode_num = atoi(argv[1]);
	num = atoi(argv[2]);
	
	
	if(mode_num == 1){
		if(pthread_create(&tid1, NULL, led_green_task,  (void*)num)!=0) {
		perror("pthread_create");
		exit(1);
		}
		led_red_task();
	}
	else if(mode_num == 2){
		if(pthread_create(&tid2, NULL, led_yellow_task, (void*)num)!=0) {
		perror("pthread_create");
		exit(1);
		}
		led_red_task();
	}
	else if(mode_num == 3) {
		if(pthread_create(&tid1, NULL, led_green_task,  (void*)num)!=0) {
		perror("pthread_create");
		exit(1);
		}
		if(pthread_create(&tid2, NULL, led_yellow_task, (void*)num)!=0) {
		perror("pthread_create");
		exit(1);
		}
		led_red_task();
	}
	
	pthread_exit(NULL);
}





