# pointer

## pointer 뿌시기

### 1. Three basic memory model in C
* Automatic : default
ex. int a = 100;
* Static : 프로그램이 실행되는 내내 메모리가 살아 있다.
ex static int a = 100;
* Manual : size 변경이 가능하다.
ex. malloc 

![0811_automatic__static__manual_compare](/uploads/98727f2baaea6f69d0af52ba4f2c85a9/0811_automatic__static__manual_compare.PNG)

```
[표 사진에서 각 행 영어 해석]
- set to zero on startup : 시작할 때 0으로 초기화하는가
- Scope-limited : scope 밖에서 건드릴 수 있는가
- Can set values on init : 초기화할 때 값을 set할 수 있는가
- Can set nonconstant values on init : 아래 코드와 같이 사용할 수 있는가
    func(int a)
    {
        int b = a*4;
    }
- sizeof measures array size: sizeof를 사용할 수 있는가
- persists across function calls : function call을 해도 값이 유지가 되는가
- Can be global : global로 선언이 되는가
- Array size can be set at runtime : 사이즈를 설정할 수 있는가
- Can be resized : 사이즈 변경이 가능한가
```

<br>



### 2. Noun-Adjective Form
* 1. int const a : a는 상수(const) integer이다.
* 2. int const * a : a는 상수 integer 포인터를 가르킨다.
* 3. int * const a : a는 interger pointer가 상수이다.
    -> int *a = &pi; 에서 값을 변경하지 않았으면 하는 경우, int*const a와 같은 형태로 사용한다.
    -> 가르키는 메모리 주소는 고정되어 있고 그 안에 들어가는 값은 변할 수 있다.

* 4. int * const * a : a는 integer를 가르키는 포인터인데, 그것의 포인터이다.
* 5. int const ** a : a는 상수를 가르키는 포인터가 있는데 이것도 상수이고, 이 상수를 가르키는 포인터이다.
* 6. int const * const * a : 고정된 이중 포인터

### 3. const 와 final 차이
const 상수에 대해 다루면서, 한번 값을 할당하면 변하지 않는다는 성질을 지닌 점이, final과 비슷하다고 생각하여 이 둘의 차이점에 대해 검색해보았다.
```
공통점 : 한 번 값을 할당하면 재할당 할 수 없다.
final : 런타임 전까지 정해지지 않더라도 컴파일 시 에러가 나지 않지만, 한 번 값이 할당되면 재할당 되지 않는다.
const : 런타임 전까지 정해지는 값에 대해서만 할당이 가능하다.
```

### 4. code 분석
각 c 파일에 주석 확인하기

