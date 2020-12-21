# three_files

## three_files에서 사용된 개념

### #define 뿌시기(0805)
* #ifdef _VERSION_ : _VERSION_이 정의되어 있는 경우 블록에 들어감
* #ifndef _VERSION_ : _VERSION_이 정의되어 있지 않는 경우 블록에 들어감
* #endif : #ifdef 종료시켜줌


### gcc 명령어 뿌시기(0805)
* -c : 컴파일 할 때, output file을 각각 만들어줌
--활용--
ex ) func.c 는 바뀐 게 없고, main.c만 바뀐 경우
1. 처음에 컴파일 할 때, gcc -c main.c func.c 를 하게 되면,
main.o 와 func.o가 생긴다.
2. main.c를 수정함.(가정)
3. gcc main.c func.o 실행
4. main.c만 다시 컴파일하여 ./a.out 파일을 생성한다.
 
* -o {이름}: {이름}으로 output file 생김 
--활용--
gcc main.c func.o -o main
main이라는 이름으로 output file이 생성된다.

* -D : macro define으로, -D 뒤에 오는 이름으로 정의된 macro define을 켜준다.
-- 활용 --
gcc -D_SWITCH_ALL main.c func.c -o main

* -U : macro undefine으로, -D와 반대로 -U 뒤에 오는 이름으로 정의된 macro define을 꺼준다.   

### make 명령어 이용하기(0807)
1. touch Makefile로 Makefile 만들기
2. vi Makefile로 편집하기

#### (ver1)
```
실행파일 이름을 mytest로 하는 경우,
mytest : target 파일들(.o)
    gcc -o mytest targetFile(.o)    //tab키 필수!
xx.o : xx.c xx.h
    gcc -c xx.c
```     


(ex)
```
mytest : func.o
    gcc -o mytest func.o
func.o : func.c func.h
    gcc -c func.c
```    

<br>
<br>

#### (ver2)_make clean 사용
```
(1) dependency 없는 경우, 내 Makefile에서 make clean하면 .o파일과 실행파일을 지우고 싶다면?
#dummy target
clean :
	-rm xx.o
	rm mytest


(2) -rm에서 '-'의 의미?
'-'를 포함한 command가 오류가 발생하더라도 다음줄을 실행하라는 의미
```     


(ex)
```
#dummy target
clean :
	-rm func.o main.o
	rm mytest
```    


<br>
<br>

#### (ver3)_make dep 사용
```
dependency를 추가하는 경우
dep :
	gccmakedep xx.c

이 경우, 실행을 위해 필요한 목적파일에서
test1.o : test1.c a.h b.h 인 경우, header파일에 대한 정의를 삭제하고,
test1.o : test1.c 만 작성해도 dependency를 찾아주므로 header 파일들을 링킹해주는 것 같다.

(1) 라즈비안 OS에서 사용하는 경우, 
sudo apt-get install xutils-dev 
명령어를 통해 gccmakedep를 설치해야 사용가능하다.

(2) 맥 OS에서 사용하는 경우
dep :
	gcc -M xx.c 
코드에서 gcc -M을 사용하는 경우, gccmakedep과 같은 기능을 한다는 것을 man page를 통해 알 수 있었다.
```     

(ex)
```
(1) 라즈비안 OS
dep :
	gccmakedep func.c main.c

(2) 맥 OS
dep :
	gcc -M func.c main.c
```     



<br>
<br>


#### (ver4)_define하기
```
코드의 재사용성을 증가하기 위해 define 이용하기!
OBJS := xx.o yy.o
xx.o, yy.o는 OBJS로 정의하겠다는 의미이다.
:= 는 =라고 써도 된다.

이 define을 부를 때, $(OBJS) 혹은 ${OBJS}라고 불러서 호출이 가능하다.
```    

(ex)
```
OBJS := func.o main.o

mytest : $(OBJS)
```    

<br>
<br>


#### (ver5)_내장 매크로 이용하기<Internal Macro>
```
$@ : 현재의 target 파일명 
-> mytest 치환가능
$^ : 현재 모든 의존 파일들의 명단
-> test1.o test2.o test3.o
$? : 현재의 target 파일보다 더 최근에 갱신된 의존 파일들의 명단
->dependency가 많은 경우, $? 로 치환가능
$*.c : 현재의 target파일보다 더 최근에 갱신된 현재 의존 파일 명단
$< : 의존 파일 중 첫번째 파일 명
-> 사용 많이 함

```    

(ex)
```
mytest : $(OBJS)
	gcc -o $@ $^

test1.o : test1.c 
	gcc -c $?

test2.o : test2.c 
	gcc -c $*.c

test3.o : test3.c 
	gcc -c $<
```     

<br>
<br>


#### (ver6)_내장 매크로 이용하기<Pre-defined Macro>
```
$(CC) : c compile하는 프로그램
->이는 CC := gcc로 재정의 하여 gcc로 컴파일하게 할 수 있다.
$(CFLAGS) : cc 명령어의 옵션 설정 가능
-> -c -Wall -g 인 경우 -g는 디버깅 정보를 만드는 것이므로
-O2(최적화 레벨을 정하여)코드를 최적화하는 것과 함께 쓰는 것을 지양해야 함.
$(CXX) : c++ 컴파일하는 프로그램
```    

(ex)
```
CC := gcc
CFLAGS = -c -Wall -g
#CFLAGS = -c -Wall -O2

mytest : $(OBJS)
	$(CC) -o $@ $^

test1.o : test1.c 
	$(CC) $(CFLAGS) $?
```     

<br>
<br>

#### (ver7)_확장자 규칙(Suffix Rules 이용)
```
미리 정의해놓은 일반화한 기술 파일 항목을 가르킴
(1) .SUFFIXES : .o .c .s
(2) .c.o :
	$(CC) $(CFLAGS) -c $<
-> 일일히 목적 파일들을 gcc로 컴파일하지 않아도 되는 듯
(3) .s.o :
	$(AS) $(ASFLAGS) -o $@ $<
```    

(ex)
```
SRCS := test1.c test2.c test3.c
OBJS := $(SRCS:.c=.o)

.c.o :  
	$(CC) $(CFLAGS) $<
```    

<br>
<br>


#### (ver8)_.c.o 마저 생략이 가능
(ex)_최종 코드
```
SRCS := func.c main.c
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS = -c -Wall -g
#CFLAGS = -c -Wall -O2

mytest : $(OBJS)
	$(CC) -o $@ $^

#dummy target
clean :
	-rm $(OBJS)
	rm mytest

dep :
	gcc -M $(SRCS)

```       


