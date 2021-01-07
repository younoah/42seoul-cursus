# part 1. Libc functions

> Libc는 C표준 라이브러리를 의미한다.
>
> 즉, C표준 라이브러리에 정의되어 있는 함수들을 재구현 해야한다.



## 1. 구현 목록



### 1.1 메모리

- `memset` : 원하는 값으로 메모리 세팅
- `bzero` : 메모리를 0으로 세팅
- `memcpy` : `src` 가 가리키는 곳 부터 `n` 바이트 만큼을 `dest` 이 가리키는 곳에 복사한다.
- `memccpy` : 메모리 영역 `src` 에서 메모리 영역 `dest` 로 *n* 바이트를 넘지 않고, 문자 *c* 가 발견되면 멈춘다.
- `memmove` : `src`가 가리키는 메모리로 부터 n바이트 사이즈만큼 `dest`가 가리키는 메모리로 복사한다.
- `memchr` : 메모리 블록에서 문자를 찾는다.
- `memcmp` : 두 개의 메모리 블록을 비교한다.
- `calloc` : malloc 처럼 메모리를 할당하고 전부 0으로 초기화한다.



### 1.2 문자열

- `strlen` : 문자열의 길이를 구한다.
- `strlcpy` : null을 보장하면서 문자열을 복사한다.
- `strlcat` : null을 보장하면서 문자열을 이어 붙인다.
- `strchr` : 문자열에서 특정한 문자가 가장 먼저 나타나는 곳의 위치를 찾는다.
- `strrchr` : 문자열에서 특정한 문자를 검색하되 가장 마지막으로 나타나는 위치를 찾는다.
- `strnstr` : 문자열 내에서 부분문자열을 탐색한다.
- `strncmp` : 두 문자 열의 일부 문자열을 비교한다.

- `strdup` : 문자열을 새로운 메모리에 할당하여 복사한다.



### 1.3. 체크

- `isalpha` : 해당 문자가 알파벳인지 확인한다. (문자열x)
- `isdigit` : 숫자인지 확인한다.
- `isalnum` : 알파벳이거나 숫자인지 확인한다.
- `isascii` : 아스키코드(0 ~ 127)인지 확인하다
- `isprint` : 출력가능한 문자인지 확인한다.(아스키코드상 32~126 까지만 출력이 가능하다.)



### 1.4. 변환

- `atoi` : 문자열 정수를 int형 정수로 변환한다.
- `toupper` : 문자를 소문자에서 대문자로 변환한다.
- `tolower` : 문자를 대문자에서 소문자로 변환한다.



## memset

> 상수 바이트로 메모리 채우기

```c
#include <string.h>
void *memset(void * ptr, int value, size_t n);
```

- 포인터를 역참조한 뒤 값을 할당할 때는 해당 자료형 크기만큼만 할당할 수 있다. 만약 int형 포인터라면 4바이트 크기만큼 할당한다.
- memset 함수를 사용하면 메모리의 내용을 원하는 크기만큼 특정값으로 설정할 수 있으며 함수 이름은 memory set에서 따왔다. 이때 설정하는 크기는 바이트 단위입니다.
- memset() 함수는 `ptr` 이 가리키는 메모리 영역의 첫 번째 부터 `n` 바이트를 상수 바이트 `value`로 채운다.
- 이 때, c는 unsigned char 로 형변환 된다.

#### 인자

- `ptr` : 값을 채울 메모리의 시작 주소

- `value` : 채울 값, 인자로는 `int` 로 전달되지만 함수 내부적으로 `unsigned char` 로 형변환 되어서 사용된다.

- `n` : `value` 로 채울 바이트 수

#### 리턴값

- `ptr` 이 리턴된다.

#### 예시

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	char str[] = "almost every programmer should know memset!"; // 문자열(포인터) 선언 및 초기화
	long long *numPtr = malloc(sizeof(long long));  // long long의 크기 8바이트만큼 동적 메모리 할당
	memset(str, '-', 6); // 문자열(포인터) str에 첫번째부터 6번째 까지
	printf("%s\n", str);
	memset(numPtr, 0x27, 8);    // numPtr이 가리키는 메모리를 8바이트만큼 0x27로 설정
	printf("%llx\n", *numPtr);    // 0x2727272727272727: 27이 8개 들어가 있음
	free(numPtr);    // 동적으로 할당한 메모리 해제
	return 0;
}
```

#### 구현

```c
void	*ft_memset(void *ptr, int value, size_t n)
{
    // ptr에서 1바이트씩 이동하면서 값을 할당해줘야한다. 즉 포인터 연산을 해야한다.
    // 하지만 ptr이 void 포인터이므로 포인터 연산이 불가능하다. (자료형을 모르기 때문에)
    // 따라서 ptr을 타입캐스팅을 한 후 자료형 포인터로 변환하여 포인터연산을 하던가
    // 임시로 생성한 자료형 포인터 변수를 만들고 ptr을 가르키도록 하여 포인터 연산을 해야한다.
    // 특히 왜 unsined char자료형을 사용하냐면,
    // 1바이트씩 증가시키기위해, 자료형의 크기가 1바이트인 char로 하고
    // 일반적인 char로 할 경우 자료형 연산을 할때 음수 때문에 얘기치 못한 불상사를 막기위함이다.
    // char vs unsigen char 둘의 차이에 대한 이해가 더 필요하다.
    // 왜 굳이 unsigen char 자료형을 써야할까
	unsigned char *temp;
	size_t			i;
	
	temp = ptr;
	i = 0;
	while (i < n)
	{
		temp[i] = value;
		i++;
	}
	return (ptr);
}
```



## bzero

> 제로 값의 바이트를 기입한다

```c
#include <string.h>
void bzero(void *ptr, size_t n);
```

- bzero() 함수는 `ptr` 의 처음부터 n바이트까지 0으로 세팅한다.

#### 인자

`ptr` : 값을 채울 메모리의 시작 주소

`n` : `value` 로 채울 바이트 수

#### 리턴값

- 없음

#### 예시

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	char str1[] = "almost every programmer should know memset!";

	bzero(str1, 1);
	printf("bzero : %s\n", str1);
	return (0);
}
```

#### 구현

```c
void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = ptr;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
```



## memcpy

> 메모리의 일부분을 복사한다.

```c
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
```

- `src` 가 가리키는 곳 부터 `n` 바이트 만큼을 `dest` 이 가리키는 곳에 복사한다.
- 이 때, `dst` 와 `src` 의 타입은 모두 `memcpy()` 함수와 무관하다.
- 왜냐하면 이 함수는 단순히 이진 데이터를 복사하는 것이기 때문이다.
- 또한, 이 함수는 `src` 의 `null` 종료 문자를 검사하지 않는다. 언제나 정확히 `n` 바이트 만큼 복사한다. (null보장 x)
- 오버플로우 문제를 방지하기 위해 `dst` 와 `src` 가 가리키는 배열의 크기는 반드시 `n` 바이트 이상이어야 한다. (`n < len(dest) && n < len(src)`) 
- 또한 서로 메모리 영역이 겹치면 안된다. 만약 두 메모리 블록이 겹쳐저 있다면 `memmove()` 함수를 사용하자.

#### 인자

- `dst` : 데이터가 복사될 곳의 주소로, `void*` 형으로 형 변환 되어서 전달된다.
- `src` : 복사할 데이터들이 위치한 주소로 역시 `void*` 형으로 형 변환 되어서 전달된다.
- `n` : 복사할 데이터의 바이트 수 이다.

#### 리턴값

`dest`가 리턴된다.

#### 예제

```c
#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];

	memcpy(str2, str1, strlen(str1) + 1);
	memcpy(str3, "copy successful", 16);
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}
```

#### 구현

```c
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dst);
}
```

#### 

## memccpy

> 메모리 영역 복사

```c
#include < string.h >
void *memccpy(void *dest, const void *src, int c, size_t n);
```

- 메모리 영역 *src* 에서 메모리 영역 *dest* 로 *n* 바이트를 넘지 않고, 문자 *c* 가 발견되면 멈춘다.
- 즉, n 바이트 이전까지 c가 없다면 복사가 되지 않고, n바이트 이전에 c가 있다면 c까지 메모리 영역이 복사된다.
- 메모리 영역이 겹치면 결과가 정의되지 않는다.

#### 리턴값

- 만약 c를 찾으면 c 다음 주소 값을 반환하고, src의 값에서 n 바이트 만큼 중 c를 찾지 못하면 `NULL` 값을 반환한다.

#### 예제

```c
#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];

	int *res1 = memccpy(str2, str1, 's', strlen(str1) + 1);
	int *res2 =  memccpy(str3, "copy successful", 'u', 14) ;
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	printf("res1 : %p\nres2 : %p", res1, res2);
	return 0;
}
```

#### 구현

```c
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;
	
    // const가 아닌 void 포인터 dest는 unsigned char 포인터형 tmp_dest에 할당 할때 암묵적 형변환이 되어 할당된다.
    // 색이 옅은 void가 색이 있는 char로 형변환이 되는듯? 이부분은 좀더 확실하게 찾아보고 넘어가야 할 듯 하다.
    // tmp_dest = (unsigned char*)dest; 이런식으로 타입캐스팅을 하고 할당해도된다.
    // 반면에 const로 선언된 void 포인터 src는 타입캐스팅을 하지않고 할당하면 에러를 뱉는다.
	tmp_dst = dst;
	tmp_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_src[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
```



## memmove

> 메모리 블록을 옮긴다.

```c
#include <string.h>
void *memmove(void *dst, const void *src, size_t n);
```

- `src`가 가리키는 메모리로 부터 n바이트 사이즈만큼 `dst`가 가리키는 메모리로 옮긴다.
- move라서 잘라내고 붙어넣는거라고 생각할 수 있지만, 복사하는 기능을 가진 함수이다.
- memcpy()와이 차이점은 memcpy()는 곧바로 어딘가를 거치지 않고 그 위치에 복사해서 붙여넣는다 생각하면되고
- memmove()는 훨씬 더 안전하게 복사할 것을 버퍼에 복사하고 해당 위치에 가서 버퍼에 복사 된것을 붙여 넣는 식으로 동작이 구현되어있다.
- 즉, memcpy()와 memmove()는 똑같이 복사하는 기능이지만 memcpy()는 버퍼를 거치지 않아 빠르고, memmove()는 버퍼를 이용하여 안전하다.
- 거두절미하고, memmove는 memcpy와 달리 메모리가 겹치는 상태에서의 불상사를 피할수 있도록 한다.
- 메모리 복사 수행시, 중간에 버퍼를 이용하게 되므로 `dst` 과 `src` 의 해당하는 범위가 겹쳐져도 문제는 없다.
- `src` 의 널 종료 문자를 확인하지 않는다. 언제나 정확히 `n` 바이트 만큼 복사를 수행한다.
- 오버플로우를 방지하기 위해 `dst` 와 `src` 가 가리키는 배열 모두 적어도 `n` 바이트 이상은 되어야 한다.

#### 인자

- `dest` : 복사 한걸 붙여넣을 메모리를 가리키는 포인터 (목적지)
- `src` : 복사 할 메모리를 가리키는 포인터 (출발지)
- `n` : 복사할 바이트 길이

#### 리턴값

- 첫번째 인자 `dest` 가 반환이 된다.

#### 예시

```c
#include<string.h>
#include<stdio.h>

/*
예시1
memmove can be very useful...... 에서, 문자열 시작 주소 부터 15 번째 부분 부터
11 바이트, 즉 "very useful" 을 문자열 시작 주소 부터 20 번째 부분, 즉 "use~"
부분에 복사해 넣는다. 다시말해, 위 문자열은 "memmove can be very very useful."
이 된다.
 */
// 이 예시를 보면 정말 move한 느낌이 들긴 하다.
int main() {
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}

// 예시2
int main(void)
{
    int src[] = { 7, 6, 5, 4, 3, 2, 1};
    int dest[7];

    memmove(dest, src, sizeof(src));
    //memmove(dest, src, sizeof(int) * 7); // 이것도 가능
    
	printf("복사한 배열 : ");
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", src[i]);
    }
    printf("\n");
    printf("복사된 배열 : ");
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", dest[i]);
    }
    return 0;
}
```

#### 구현

```c
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	unsigned int	i;

	if (!dst && !src)
		return (dst);
	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
    i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			tmp_dst[n - 1 - i] = tmp_src[n - 1 - i];
			i++;
		}
	}
	return (dst);
}
```

#### 구현시 주의점!

##### dest < src 인 경우

- src의 주소가 dest 보다 큰 값이라면,
- src의 처음 부터 n바이트 만큼 dest에 복사한다.
- src를 한 바이트씩 복사하더라도 dest 보다 큰 위치에 있기 때문에
- 오버랩되더라도 src를 모두 정상적으로 dest에 복사할 수 있다.

>  memmove() 전

| 0x0000(dest) | 0x0001 | 0x0002(src) | 0x0003 | 0x0004 | 0x0005 |
| :----------: | :----: | :---------: | :----: | :----: | :----: |
|              |        |      t      |   e    |   s    |   t    |

> memmove() 후

| 0x0000(dest) | 0x0001 | 0x0002(src) | 0x0003 | 0x0004 | 0x0005 |
| :----------: | :----: | :---------: | :----: | :----: | :----: |
|      t       |   e    |      s      |   t    |   s    |   t    |



##### dest > src 인 경우

- src의 주소가 dest보다 작은 값이면,
- dest가 src보다 뒤에 있기 때문에 기존 방식 대로 복사하면  src의 뒷부분, 즉 src와 dest가 겹치는 부분이 자료가 바뀌게 되어 올바르게 복사가 되지 않는다.
- 아래 예시의 경우 test에서 t, e까지 잘 옮기다가 s에 t로 바뀌었기 때문에 기존 방식대로 불상사가 발생한다.
- src의 마지막 데이터부터 한바이트 씩 앞으로 가면서 dest의 마지막 바이트부터 한바이트씩 앞으로 가면서 복사해야한다.

>  memmove() 전

| 0x0000(src) | 0x0001 | 0x0002(dest) | 0x0003 | 0x0004 | 0x0005 |
| :---------: | :----: | :----------: | :----: | :----: | :----: |
|      t      |   e    |      s       |   t    |        |        |

> memmove() 후

| 0x0000(src) | 0x0001 | 0x0002(dest) | 0x0003 | 0x0004 | 0x0005 |
| :---------: | :----: | :----------: | :----: | :----: | :----: |
|      t      |   e    |      t       |   e    |   s    |   t    |

#### 재구현

```c
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *usrc;
	unsigned char *udst;
	unsigned char temp[len];

	if (dst == NULL && src == NULL)
		return (NULL);
	usrc = (unsigned char *)src;
	udst = (unsigned char *)dst;
	ft_memcpy(temp, usrc, len);
	ft_memcpy(udst, temp, len);
	return (dst);
}
```

기존에 작성한 코드는 버퍼개념을 이용하지 않았다. 이번에 tmp라는 임시장소(버퍼역할)로 옮기는걸로 조금더 간단하게 구현해보았다.

하지만 이렇게 구현하면 `libft-unit-test` 에서 128mb input data를 처리할 수 없다고 나오는데 왜 그런지는 아직 모르겠다.



## memchr

> 메모리 블록에서 문자를 찾는다.

```c
#include <string.h>

void *memchr(void *ptr, int value, size_t n);
```

- ptr이 가리키는 메모리 처음부터 n바이트 까지 탐색하면서 처음으로 value와 일치하는 값의 주소를 리턴한다.

#### 인자

- `ptr` : 검색을 수행할 포인터
- `value` : 찾을 값으로, `int` 로 값이 전달되지만 내부적으로는 한바이트씩 비교하기 때문에 `unsigned char` 로 변환되어 사용된다.
- `n` : 검색을 시작한 부분 부터 검색을 수행할 만큼의 바이트수

#### 리턴값

- 메모리 블록에서 `value` 와 일치하는 값이 있다면 그 곳의 주소를 리턴하고 값을 찾지 못한다면 `NULL` 을 리턴한다.

#### 예시

```c
#include <stdio.h>
#include <string.h>

int main() {
	char* pch;
	char str[] = "Example string";
	pch = (char*)memchr(str, 'p', strlen(str));

	if (pch != NULL)
	{
		printf("'p' found at position %ld.\n", pch - str + 1);
		printf("pch : %p  str : %p\n", pch, str);
	}
	else
		printf("'p' not found.\n");

	return 0;
}
```

#### 구현

```c
void	*ft_memchr(void *ptr, int value, size_t n)
{
	unsigned char	*tmp_ptr;
	unsigned char	find;
	unsigned int	i;

	tmp_ptr = (unsigned char*)ptr;
	find = (unsigned char)value;
	i = 0;
	while (i < n)
	{
		if (tmp_ptr[i] == find)
			return (&tmp_ptr[i]);
		i++;
	}
	return (0);
}
```



## memcmp

> 두 개의 메모리 블록을 비교한다.

```c
#include <string.h>

int memcmp(const void *ptr1, const void *ptr2, size_t n);
```

- ptr1이 가리키는 처음부터 n바이트까지의 데이터와 ptr2가 가리키는 처음부터 n바이트까지의 데이터를 비교하여 이들이 같다면 0을 리턴하고 다르다면 값이 다른 시점의 `ptr1값 - ptr2값` 을 리턴한다.
- `strncmp`와의 차이점?
	- `memcpy` 는 두 문자열 중 하나가 끝나더라도(널 값이 나오더라도) 상관없이 *서로 다른 값이 나오거나*, *n개가 될 때 까지* 비교를 수행한다.
	- `strncmp`는 s1과 s2가 모두 NULL값이 나오면 남은 카운트에 관계없이 0을 반환한다.

#### 인자

- `ptr1` : 메모리 블록을 가리키는 포인터

- `ptr2` : 메모리 블록을 가리키는 포인터

- `num` : 비교할 바이트 수

#### 리턴 값

- 만일 두 메모리 블록이 정확히 같다면 0 을 리턴한다.
- 다르다면 값이 다른 첫 시점에서  `ptr1값 - ptr2값` 을 리턴한다.

#### 예시

```c
#include <stdio.h>
#include <string.h>

int main ()
{
    char str1[12];
    char str2[12];
    int state;

    strcpy(str1, "mozi");
    strcpy(str2, "tistory");

    state = memcmp( &str1, &str2, 4 );

    printf ("State=\"%d\", str1=\"%s\", str2=\"%s\"\n", state, str1, str2);
    return 0;
}
```

#### 구현

```c
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*tmp_ptr1;
	unsigned char	*tmp_ptr2;
	unsigned int	i;

	tmp_ptr1 = (unsigned char*)ptr1;
	tmp_ptr2 = (unsigned char*)ptr2;
	i = 0;
	while (i < n)
	{
		if (tmp_ptr1[i] != tmp_ptr2[i])
			return (tmp_ptr1[i] - tmp_ptr2[i]);
		i++;
	}
	return (0);
}
```



## strlen

> 문자열의 길이를 구한다.

```c
#include <string.h>

size_t strlen(const char *str);
```

- 문자열의 시작 부터, 널 문자 직전 까지의 문자의 개수를 센다.

#### 인자

`string` : C 형식 문자 or C 형식 문자열

#### 리턴값

문자열의 길이. (참고로 `size_t` 형으로 선언 되어 있는데 대부분의 [string.h](https://modoocode.com/76) 에서는 부호 없는 정수형으로 선언되어 있다.)

#### 예시

```c
#include <stdio.h>
#include <string.h>

int main() {
  char szInput[256];
  printf("Enter a sentence: ");
  scanf("%s", szInput);
  printf("The sentence entered is %lu characters long.\n", strlen(szInput));
  return 0;
}
```

#### 구현

```c
#include <stdlib.h>

size_t	strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
```



## strlcpy

> null을 보장하여 문자열 복사하기

```c
#include <string.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
```

- src를 dst에 null을 포함해서  (size-1)개 까지 복사후 마지막에 null을 붙어준다. (null 보장)
- src의 길이가  size보다 적으면 부족한 부분을 null로 채운다.
- 예를들어 src가 "abc"이고 n이 6이면 dst에는 "abc\n\n\n"이 들어간다.

#### 리턴

- src의 길이를 리턴한다.

#### 구현

```c
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t i;
	size_t src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}
```



## strlcat

> null을 보장하여 문자열 이어 붙이기

```c
#include <string.h>
size_t	ft_strlcat(char *dst, char *src, size_t size);
```

- dest의 길이를 포함해서 새로운 dest의 길이를 설정하고 (size)
- 빈공간 만큼 src를 이어 붙인다. 마지막에  null을 보장하여 넣어준다.

#### 구현

```c
size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dst_len;
	size_t	result;
	size_t	i;

	dst_len = ft_strlen(dst);
	result = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (result + size);
	while (src[i] && i < (size - dst_len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	result += dst_len;
	return (result);
}
```



## strchr

> 문자열에서 특정한 문자가 가장 먼저 나타나는 곳의 위치를 찾는다.

```c
#include <string.h>  // C++ 에서는 <cstring>

char	*ft_strchr(const char *s, int c);
```

#### 인자

- `s` : C 형식 문자열

- `character` : 검색할 문자로, `int` 형태로 형변환 되어서 전달되지만 함수 내부적으로는 다시 `char` 형태로 처리된다.

#### 리턴값

- `s` 에서 처음으로 발견되는 `c`의 포인터를 리턴한다.

- 만일 문자가 없다면 `NULL` 포인터를 리턴하게 된다.

#### 예시

```c
#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "This is a sample string";
	char* pch;
	printf("Looking for the 's' character in \"%s\"...\n", str);

	pch = strchr(str, 's');

	while (pch != NULL) {
		printf("found at %ld\n", pch - str + 1);
		pch = strchr(pch + 1, 's');
	}

	return 0;
}
```

#### 구현

```c
char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)s + i); //const이기 때문에 char포인터로 형변환
        	//return ((char*)&s[i]); //const이기 때문에 char포인터로 형변환
        	// char포인터로 형변환을 하지 않으면 인덱싱도 불가하다.
		i++;
	}
	if (s[i] == c) // c가 null일 경우를 위해서
		return ((char*)s + i);
	return (0);
}
```



## strrchr

> 문자열에서 문자를 검색하되 가장 마지막으로 나타나는 위치를 찾는다. (reverse)

```c
#include <string.h>  // C++ 에서는 <cstring>

char *strrchr(char *s, int c);
```

- 문자열에서 문자를 검색하되 가장 마지막으로 나타나는 위치를 찾는다. 

- 그리고 이를 가리키는 포인터를 리턴한다.

- 이 때 문자열의 널 종료 문자 역시 C 문자열의 일부분이라 생각한다.

- 따라서 이 함수는 문자열의 널 종료 문자를 가리키는데 사용될 수 도 있다.

- 예외처리

	```null
	  if (last[i] == find)        
	  		return (last);
	```

	s가 빈문자열일 때, s의 첫 글자만 c일 때 NULL이 아니라 s의 첫글자를 반환해야 함.

#### 인자

- `s` : 문자 or 문자열
- `c` : `s` 에서 찾을 문자 (`int` 로 전달되지만 함수 내부적으로 다시 `char` 로 변환되어 처리된다.)

#### 리턴값

- `s` 에서 찾은 문자의 위치를 리턴한다. 
- 만약 찾지 못했다면 `null`을 리턴한다.

#### 예시

```c
#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "This is a sample string";
	char* pch;
	pch = strrchr(str, 's');
	printf("Last occurence of 's' found at %ld \n", pch - str + 1);
	return 0;
}
```

#### 구현

```c
char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = strlen(s);
	while(i >= 0)
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i--;
	}
	return (0);
}
```



## strnstr

> 문자열 내에서 부분문자열을 탐색한다.

```c
#include <string.h>
char *strnstr(const char *big, const char *little, size_t len);
```

- `big` 의 처음부터  `len` 까지 `little` 문자열이 포함되었는지 검색한다.
- 만약 발견되면 가장 먼저 발견된 위치를 리턴한다.
- 검색에서 마지막 `null` 문자는 포함하지 않는다.

#### 인자

- `big` : 검색할 대상 문자열
- `little` : `big` 에서 검색할 문자열
- `len` : `big` 에서 검색할 구간의 길이

#### 리턴값

- 만약 발견되면 가장먼저 발견된 위치를 리턴한다.
- 만약 발견되지 않는다면 `null` 을 리턴한다.
- 만약 `little` 이 `null` 이면 `big` 을 그대로 반환한다.
- `big` 의 문자열 길이 혹은 `len` 보다 `little` 의 문자열 길이가 더 길면 `null` 을 반환한다. (찾을 필요도 없이 null이기 때문에 )

#### 예시

```c
#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "This is a simple string";
	char* pch;
	pch = strnstr(str, "simple", 16); // 15이하로 설정하면 null출력
	printf("pch : %s\n", pch);
	return 0;
}
```

#### 구현

```c
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	
    // 만약 little이 null이면 big을 그대로 반환한다.
	if (little[0] == 0)
		return ((char *)big);
    // 주의!
    // if (!little)
    //	 return ((char *)big);
    // 이렇게 하면 안된다. 
    // 입력 값이 null이라는건 입력을 "" 이렇게 한거인데
    // null값을 갖고 있는 주소를 갖고 있기 때문에
    // little[0] == 0 일때 라고 처리하는게 맞다.
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
```



## strncmp

> 두 문자 열의 일부 문자열을 비교한다.

```c
#include <string.h>

int strncmp(const char *s1, const char *s2, size_t n);
```

- 두 문자열의 처음부터 n까지만 정확히 일치하는지 비교한다.
- 두 문자열의 길이가 n보다 작을때는 처음부터 null까지 일치하는지 비교한다.

- 일치하면 `0` 반환, 일치하지 않으면 최초로 불일치 하는 차이값 리턴 (`s1[i] - s2[i]`)

#### 예시

```c
#include <stdio.h>
#include <string.h>

int main() {
	char str[][5] = {"R2D2", "C3PO", "R2A6"};
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++)
		if (strncmp(str[n], "R2xx", 2) == 0) {
		printf("found %s\n", str[n]);
		}
	return 0;
}
```

#### 구현

```c
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
```



## atoi

> 문자열을 정수(int)로 변환한다.

```c
#include <stdlib.h>

int atoi(const char *str);
```

- 문자열에서 비-공백 문자가 나오기 전 까지 최대한 많은 공백들을 무시한다.
- 그 다음에 첫 번째 비-공백 문자부터 최대한 많은 숫자들을 수로 변환한다.
- 숫자의 맨 앞부분에는 `+` 나 `-` 가 올 수 도 있다
- 숫자들 다음에 나타나는 문자들은 모두 무시된다

#### 리턴값

- 성공적으로 변환을 하였다면 `int` 값을 리턴한다.
- 만약 반환을 실패하였다면 0이 리턴된다.

#### 예시

```c
#include <stdio.h>

int main() {
	char s[] = "-2147483647";
	int num = atoi(s);
	printf("res : %d\n", num);
	return (0);
}
```

#### 구현

```c
int		ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign *= (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}
```



## isalpha

> 알파벳인지 확인하다.

#### 구현

```c
int		isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z'))
		return (1);
	else
		return (0);
}
```



## isdigit 

> 숫자형문자(digit)인지 확인한다.

#### 구현

```c
int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
```



## isalnum

> 알파벳이거나 숫자인지 확인한다.

#### 구현

```c
int		ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
```



## isascii

> 아스키코드인지 확인하다

#### 구현

```c
int		ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
```



## isprint

> 출력가능한 문자인지 확인한다.
>
> 아스키코드상 32~126 까지만 출력이 가능하다.

#### 구현

```c
int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
```



## toupper

> 소문자를 대문자로 바꾼다.

#### 구현

```c
int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	else
		return (c);
}
```



## tolower

> 대문자를 소문자로 바꾼다.

#### 구현

```c
int		ft_toupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	else
		return (c);
}
```



## calloc

#### malloc함수와 calloc함수의 차이점

```c
/*문자 10개를 저장하기 위한 동적 메모리할당 */

// malloc
char *p = (char *)malloc(sizeof(char)*10);

// calloc
char *p = (char *)calloc(10, sizeof(char));
```

- malloc은 할당된 공간의 값을은 바꾸지 않는다.

- calloc은 할당된 공간의 값을 모두 0으로 바꾼다.

- 배열을 할당하고 모두 0으로 초기화할 필요가 있을경우에는 calloc을 쓰면 편하다.

```c
#include <stdlib.h>

calloc(size_t count, size_t size);
```

- `count` 는 메모리의 단위 갯수, `size` 는 메모리 1개당 크기 (ex. 4개 x 4바이트 , 10개 x 1바이트)
- malloc으로 공간을 할당된 메모리 공간을 모두 0으로 초기화 시켜준다. (memset())



## strdup

> 문자열을 새로운 메모리에 할당하여 복사한다.

#### 예시

```c
#include <stdio.h>

int main()
{
	char *line = "hello world!";
	char *dupstr = NULL;

	dupstr = ft_strdup (line);
	printf("%s\n", dupstr);
	free(dupstr);
}
```

#### 구현

```c
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*res;

	res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
```



## 2. 추가 정리

### 2.1. `memmove` vs `memcpy`

- `memcpy`와이 차이점은 `memcpy`는 곧바로 어딘가를 거치지 않고 그 위치에 복사해서 붙여넣는다 생각하면되고
- `memmove`는 훨씬 더 안전하게 복사할 것을 버퍼에 복사하고 해당 위치에 가서 버퍼에 복사 된것을 붙여 넣는 식으로 동작이 구현되어있다.
- 즉, `memcpy`와 `memmove`는 똑같이 복사하는 기능이지만 `memcpy`는 버퍼를 거치지 않아 빠르고, `memmove`는 버퍼를 이용하여 안전하다.
- `memcpy`는 서로 메모리 영역이 겹치면 안된다. 만약 두 메모리 블록이 겹쳐저 있다면 `memmove()` 함수를 사용하자.
- 거두절미하고, memmove는 memcpy와 달리 메모리가 겹치는 상태에서의 불상사를 피할수 있도록 한다.



### 2.2. `memcmp` vs `strcmp`

- `memcpy` 는 두 문자열 중 하나가 끝나더라도(널 값이 나오더라도) 상관없이 *서로 다른 값이 나오거나*, *n개가 될 때 까지* 비교를 수행한다.
- `strncmp`는 s1과 s2가 모두 NULL값이 나오면 남은 카운트에 관계없이 0을 반환한다.



### 2.3. size_t

- size_t은 부호 없는 정수 자료형(unsigned int)
- C 언어 표준 함수에서도 크기를 의미하는 매개변수나 반환값은 size_t를 사용하고 있고, 
- CPU 비트 수에 맞게 자료형을 제공하고 있으므로 크기를 의미하는 변수는 unsigned int 대신 size_t로 선언하는 것이 좋습니다.
- size_t는 32비트에서 4바이트, 64비트에서 8바이트로 정의되어 있습니다.
- unsigned int는 64비트에서 32비트일수도있다.



### 2.4. unsigned char를 사용하는이유

- 이 때 초기화 할 값인 c는 인자로는 int로 전달되지만 함수 내부적으로는 `unsigned char`로 형변환 되어서 사용된다.

	**메모리에 접근할 때에는 signed char형이 아닌 unsigned char형을 사용해야하는 이유**

	unsigned char 는 모든 bit를 투명하게 볼 수 있는 특성을 제공합니다.
	즉, 다른 type 은 내부 비트의 일부를 값을 표현하기 위한 용도가 아닌 다른 용도(부호 비트)로 사용할 수 있으나 unsigned char 는 이것이 허락되지 않습니다.

	따라서, 임의의 메모리에 바이트 단위로 접근해 값을 다룰 때에는 반드시 unsigned char 를 사용해야 full portability 를 얻을 수 있는 것입니다. 또한, 그와 같은 이유로 signed char 가 표현할 수 있는 값의 개수보다 unsigned char 가 표현할 수 있는 값의 개수가 많다는 사실에도 유의할 필요가 있습니다. signed char <-> unsigned char 사이의 값 변환이 1:1 로 이루어질 수 "없는" 경우도 있음을 의미합니다.

	이런 이유로, 표준이 바이트 값에 접근해야 하는 경우나 문자에 접근해야 하는 경우 (예: mem(), str() 함수들) 에는 모두 unsigned char 로 접근하도록 요구하고 있습니다.

	출처 : https://kldp.org/node/75686

	

### 2.5. memset에서 int형 배열을 초기화할때 주의점

- 바이트 단위로 초기화 하기 때문에 int형 배열을 초기화 할 때는 주의해야 한다.

	예를 들면 ft_memset(arr, 1, sizeof(arr))을 호출하면 arr 배열이 모두 1로 초기화 된다고 생각하는데, 실제로는 배열이 모두 `16843009`로 초기화 된다. 16843009의 2진수 표현은 `0001 00000001 00000001 00000001` 이다. 즉, arr 배열은 1바이트(8비트)당 1로 초기화 된 것이다. *바이트가 딱 떨어지게 초기화 되지 않기 때문에 int형 배열의 요소를 1로 초기화 할 수 없다.* 다른 정수도 모두 마찬가지다. 딱 4개의 값만 가능하다고 한다. `0`, `-1`, `0x3f`, `0x7f`.

	출처 : https://blog.naver.com/chogahui05/221484049429