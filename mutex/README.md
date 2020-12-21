# mutex folder

## How to do homework


### led.h
1. 모든 파일에서 필요로 하는 library를 include 하기
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>
#include <pthread.h>

```

<br>
<br>


2. RED, GREEN, YELLOW 에 해당하는 pin 번호 define하기
```
#define RED 1
#define GREEN 4
#define YELLOW 5
```

<br>
<br>

3. led_yellow.c와 led_green.c에 정의한 led_green_task, led_yellow_task 함수를 이용하기 위해 정의하기
```
extern void*led_green_task(void*arg);
extern void*led_yellow_task(void*arg);
```

<br>
<br>

### led_main.c
1. led RED를 1초 간격으로씩 10회 깜빡이도록 하는 led_red_task 함수 구현하기
2. main에서는 ./mytest 뒤에 argv가 들어오지 않은 경우 led_red_task만 실행하도록 하고
3. argv[1] 이 1 인경우, 2인경우, 3인경우 각각다른 실행을 하도록 코드 만들기 _ 편의상 mode_num으로 재정의
```
mode_num이 1인 경우
빨간색 LED는 1초간격으로 10회 on/off 하기
초록색 LED는 pthread_create를 통해 동시에 2초 간격으로 argv[2]회 on/off하기
```

<br>
<br>

```
mode_num이 2인 경우
빨간색 LED는 1초간격으로 10회 on/off 하기
노란색 LED는 pthread_create를 통해 동시에 3초 간격으로 argv[2]회 on/off하기
```

<br>
<br>

```
mode_num이 3인 경우
빨간색 LED는 1초간격으로 10회 on/off 하기
노란색 LED는 pthread_create를 통해 동시에 3초 간격으로 argv[2]회 on/off하기
초록색 LED는 pthread_create를 통해 동시에 2초 간격으로 argv[2]회 on/off하기
```

<br>
<br>

### led_yellow.c
* 노란색 LED를  3초 간격으로 argv[2]회 on/off하기

<br>
<br>

### led_green.c
* 초록색 LED를  3초 간격으로 argv[2]회 on/off하기

<br>
<br>

## how to use make command
* make
실행에 필요한 모든 파일들을 linking하여 ./led_main 파일을 생성해준다.

<br>
<br>


* make clean 
OBJ 파일 및 ./led_main 파일을 삭제해준다.

<br>
<br>


* make dep
gccmakedep를 이용하여 dependency를 찾아준다.


<br>
<br>


### ./led_main 사용법
* ./led_main
빨간색 LED만 1초 간격으로 10회 on/off 반복한다.

<br>
<br>

* ./led_main 1 5
빨간색 LED는 1초 간격으로 10회 on/off 반복, 초록색 LED는 2초 간격으로 5회 on/off 된다.

<br>
<br>


* ./led_main 2 7
빨간색 LED는 1초 간격으로 10회 on/off 반복, 노란색 LED는 3초 간격으로 7회 on/off 된다.

<br>
<br>

* ./led_main 3 6
빨간색 LED는 1초 간격으로 10회 on/off 반복, 초록색 LED는 2초 간격으로 6회 on/off 되고, 노란색 LED는 3초 간격으로 6회 on/off 된다.

<br>
<br>

