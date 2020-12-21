# thread

## 1. thread 뿌시기

### process와 thread 차이
1. process 

 * 사전적 의미
    * 컴퓨터에서 연속적으로 실행되고 있는 컴퓨터 프로그램
    * 메모리에 올라와 실행되고 있는 프로그램의 인스턴스
    * 운영체제로부터 시스템 자원을 할당받는 작업의 단위
    * 동적인 개념 : 실행된 프로그램을 의미한다.

 * 예시 : CPU시간, Code, Data, Stack, Heap의 구조로 된 독립된 메모리 영역
 * 특징
    * process는 각각 독립된 영역인 Code, Data, Stack, Heap의 구조를 할당받는다.
    * 기본적으로 process 당 최소 1개의 메인 스레드를 가지고 있다.
    * 한 process가 다른 process의 자원에 접근하려면 process 간의 통신(IPC)을 사용해야 한다.
    


2. thread

 * 사전적 의미
    * process 내에서 실행되는 여러 흐름의 단위
    * process의 특정한 수행 경로
    * process가 할당받은 자원을 이용하는 실행의 단위

 * 특징
    * thread는 process 내에서 각각 stack만 따로 할당받고 Code, Data, Heap 영역은 공유한다.
    * 기본적으로 process 당 최소 1개의 메인 thread를 가지고 있다.
    * 같은 process안에 있는 여러 thread는 heap 공간을 공유하지만, process는 다른 process의 메모리에 접근할 수 없다.



### mutex

* 사용 이유
    * critical section에 접근할 때, 많은 객체들이 공유자원에 한번에 접근하는 것을 방지하고자 사용하는 도구이다.

* mutex 사용이 필요한 예시
    * 두 개의 thread가 같은 변수를 같은 시간에  업데이트하려고 할 때, 하나는 0을 1로 변경하려하고, 나머지 하나는 1을 0으로 변경을
    시도하는 경우, 충돌이 발생할 수 있다. 따라서, 충돌을 방지하기 위해 mutex와 같은 도구가 필요하다.

* 사용 방법
    * process는 critical section에 들어가기 전에 lock을 하고, 나올 때 unlock을 한다.
    * #include <pthread.h> 를 이용하여 pthread_mutex_t 를 통해 사용이 가능하다.


```
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // thread 초기화
pthread_mutex_lock(&mutex); // 잠금
pthread_mutex_unlock(&mutex); //잠금 해제
int status = pthread_mutex_destroy(*&mutex);    //mutex free
```

<br>
<br>

## 2. thread 과제 뿌시기
* thread는 전역변수 메모리는 공유하지만, local 변수는 공유하지 않음을 생각하기

### 구현방법
1. main에서 학생들의 점수를 입력받기(scanf)
2. 학생들의 점수는 short int 로 30개 받기
3. main, child1, child2를 이용한다.
4. s_thread1 첫번째 thread : average, sum 구해서 프린트하기
5. s_thread2 두번째 thread : 성적순으로 sorting해서 출력해주기
6. pthread_exit(NULL)을 이용하면 main이 죽더라도 child가 죽지 않음을 생각해보기 


### 프로그램 이용방법
1. 프로그램을 실행한 후, 30명의 학생들의 점수를 입력한다.
2. 2개의 child thread가 각각 자신의 실행 후, average, sum, sorting된 결과를 출력해준다.


### reference
[OS] 프로세스와 스레드의 차이 https://gmlwjd9405.github.io/2018/09/14/process-vs-thread.html