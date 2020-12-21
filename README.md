# battle_c

## yejoon Ko - Team 1

실전코딩2 실습

## 목차
- [printf](#printf)
  * [stdio.h](#stdioh)
- [redirection](#redirection)
- [three_func](#three-func)
- [option_test](#option-test)
  * [1. compiler and interpreter](#1-compiler-and-interpreter)
  * [2. Procedures for the C execution file](#2-procedures-for-the-c-execution-file)
  * [3. gcc command option meaning and result](#3-gcc-command-option-meaning-and-result)
- [Makefile](#makefile)
- [Raspberry Pi light on code and Breadboard Connection Images](#raspberry-pi-light-on-code-and-breadboard-connection-images)
- [pointer](#pointer)
- [thread](#thread)
- [testing](#testing)


## printf
(20.08.03-20.08.04)

### stdio.h 
(20.08.03-20.08.04)

1. stderr
    * 표준 오류 스트림
    * stream number 2

2. stdout
    * 표준 출력 스트림
    * stream number 1

3. stdin 
    * 표준 입력 스트림
    * stream number 0 
     
    
* %-d를 하는 경우, 숫자가 왼쪽 정렬되는 것을 알 수 있었음.
* man page를 적극 활용할 것!!

## redirection 
(20.08.04)

```
1. 표준 출력  ('>')
    * 사용 방법 : 명령어 > 파일
    * 명령어의 표준 출력 스트림을 파일로 내용 출력
    
2. 표준 입력  ('<')
     * 사용 방법 : 명령어 < 파일
     * 명령어의 표준 입력 스트림을 파일로 내용 출력
     
```



## three_func 
(20.08.05)

* three_file folder 만들기
* #define 에 관련된 것들을 알 수 있었음
* gcc 컴파일 시 사용 가능한 명령어들을 알 수 있었음
* 더보기 : three_func 폴더의 README.md 파일 참고하기


## option_test 
(20.08.06)
### 1. compiler and interpreter 
 * 정의  
  컴파일러, 인터프리터는 프로그래밍 언어를 기계어로 변환하는 것이다.  
  하지만 변환 과정에 있어서 차이를 보인다.

 * 차이점

|  | 컴파일러 | 인터프리터 |
| ---- | ---- | ---- |
| 번역 단위 | 전체 | 한줄씩 |
| 실행 속도 | 빠름 | 느림 |
| 번역 속도 | 느림 | 빠름 |
| 목적 프로그램 | 생성함 | 생성하지 않음 |
| 메모리 할당 | 목적 프로그램 생성 시 사용 | 사용 안함 |
   
   
### 2. Procedures for the C execution file 
* 소스파일(t1.c) -> 전처리된 소스파일(t1.i) -> 어셈블리파일(t1.s) -> 목적파일(t1.o) -> 실행파일(a.out)
    


### 3. gcc command option meaning and result


1. -E : 전처리만 실행하며 컴파일이나 어셈블하지 않음
```
$ gcc -E 01.option-E.c > 01.option-E.i  
```

(결과)  
![-E](/uploads/b729fd1b0bfc3e6d52a925c4f8435afd/-E.PNG)     
-> i 파일이 생성됨    
    
<br>
<br>

2. -S : 컴파일만 실행하며 어셈블이나 링크하지 않음  
```
$ gcc -S 01.option-E.i  
```

(결과)  
![-S](/uploads/ea2b77761ffe9437fa7227c4cc3d5861/-S.PNG)  
-> s 파일이 생성됨  

    
<br>
<br>

3. -c : 컴파일과 어셈블하며 링크하지 않음  
```
$ gcc -c 01.option-E.s  
```

(결과)  
![-c](/uploads/70929faa25490bd0d65353e23bf34211/-c.PNG)   
->o 파일이 생성됨  

    
<br>
<br>

4. -g : 운영체제 고유의 형식으로 디버깅 정보를 만듦   
따라서 gdb로 실행 파일에 대해 디버깅 가능.  
```
$gcc -g 01.option-E.c  
```

(결과)  
![-g](/uploads/69b35ca6e3d45aef38918a385e88ecd4/-g.PNG)  
-> .exe파일이 생성됨     
-> 사진과 같이, 디버깅이 가능하도록 디버깅 정보가 생성되었다. 

    
<br>
<br>

5. -o<파일> : 출력을 <파일>에 함  
```
$ gcc 01.option-E.c -o 01main  
```

(결과)   
![-o](/uploads/5158d1010e49368bcd715e12794db07f/-o.PNG)  
->지정한 이름으로 실행 파일이 생성됨   

    
<br>
<br>

6. -I <디렉터리> : 헤더파일을 검색할 디렉터리를 추가함
```
Makefile에서 myinclude라는 폴더에 있는 header들을 include하고 싶은 경우
CFLAGS = -Wall -g -Imyinclude
```


<br>
<br>

7. -l<라이브러리명> : <라이브러리명>으로 지정한 라이브러리를 링크 시 추가함  
```
Makefile에서 mytest라는 파일을 생성할 때,
math library를 include하고 싶은 경우
mytest : $(OBJS)
        $(CC) -o $@ $^ -lm
```
    
<br>
<br>

8. -L <디렉터리> : -l에 의해 지정된 라이브러리를 검색할 디렉터리를 추가함  

    
<br>
<br>

9. -D <매크로> : 매크로를 지정함
```
$gcc -DDEBUG 01.option-E.c 
```

(결과)  
![-D](/uploads/792ecb9422eb644682cc2980148e6c5b/-D.PNG)  

->#ifdef으로 정의된 define을 켜주어, #ifdef~ #endif 사이에 있는 코드를 실행시켜준다. 
    
<br>
<br>

10. -O<레벨> : 최적화 수준을 지정함(0<=level<=3)
```
(ex) $ gcc -c -Wall -O2 01.option-E.c
```

(결과)  ![image](/uploads/2627a22ae3d27da27944e4c669f9b2f5/image.png)

-> 최적화 된 것은 처리속도를 측정하는 코드를 추가한 팀프로젝트 코드를  -O2 option을 사용하여 gcc로 컴파일하였을 때 ,
optimize된 것을 확인할 수 있었다.            
-> O0 : default_최적화 작업이 이루어지지 않는다.           
-> O1 : 만들어지는 오브젝트, 또는 실행파일을 가능한 작게 하면서, 컴파일 시간이 오래걸리지 
않는 범위에서 최적화를 수행한다.      
-> O2 : 만들어지는 코드가 가능한 빠르게 수행되도록 하지만, 코드의 크기가 너무 커지지 않도록 하는
범위에서 최적화를 수행한다.      
-> O3 : 코드의 크기는 전혀 신경쓰지 않고, 오직 빠른 코드를 만들어내기 위해 최적화를 수행한다.
 (무조건 좋지만은 않은 것 같았다.)     

    
<br>
<br>

11. -Wall : gcc가 제공할 수 있고, 일반적으로 유용한 모든 경고 메시지 출력  
 안쓰는 변수가 무엇인지 알려준다.  
```
$ gcc -Wall 01.option-E.c
```

(결과)  ![-Wall](/uploads/e1a09d153c9baa514007eaf6d74e6333/-Wall.PNG)  

    
<br>
<br>

12. -v : 실행 명령어들과 버전을 출력함
```
$gcc -v    
```

(결과)  
![-v](/uploads/d6b7a2efb94ddf3f70049afdf29d53ed/-v.PNG)  

    
<br>
<br>

## Makefile
(20.08.07)

* three_files 폴더 안의 README.md 참고

[Click! goto /three_files/README.md](https://git.ajou.ac.kr/yejoon/battle_c/-/blob/master/three_files/README.md)


## Raspberry Pi light on code and Breadboard Connection Images 
(20.08.10)

* led 폴더 안 참고

[Click! goto /led](https://git.ajou.ac.kr/yejoon/battle_c/-/tree/master/led)

* led 개인과제 링크


[Click! goto /mutex/README.md](https://git.ajou.ac.kr/yejoon/battle_c/-/blob/master/mutex/README.md)

## pointer
(20.08.11-20.08.12)
* pointer 폴더 안의 README.md 참고

[Click! goto /pointer/README.md](https://git.ajou.ac.kr/yejoon/battle_c/-/blob/master/pointer/README.md)


## thread
(20.08.12)
* thread 폴더 안의 README.md 참고
 

[Click! goto /thread/README.md](https://git.ajou.ac.kr/yejoon/battle_c/-/blob/master/thread/README.md)


## testing
(20.08.18-20.08.21)
* test 폴더 안의 README.md 에 test와 관련된 내용 작성 및 0820 개인과제 수행함
* 팀 과제는 battle_c_1에 작성함.

[Click! goto /test/README.md](https://git.ajou.ac.kr/yejoon/battle_c/-/blob/master/test/README.md)

