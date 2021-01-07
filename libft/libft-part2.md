## 0. 구현 목록

- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmpi`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`



## 1. ft_substr

**프로토타입**

`char	*ft_substr(char const *s, unsigned int start, size_t len);`

**설명**

> `malloc()`으로 메모리를 할당한 뒤
>
> `s` 의  `start` 부터  `len` 개 까지의 부분 문자열을 저장하여 반환한다.

**파라미터**

- `s` : 부분 문자열을 만들 문자열

- `start` : 문자열 's'에 있는 부분 문자열의 시작 인덱스

- `len` : 부분 문자열의 최대 길이

**리턴값**

- 부분문자열을 리턴한다.
- `s` 가 null이면 null이 리턴된다.
- 할당에 실패하면 null을 리턴한다.
- `len(s) < start` 일때 빈문자열을 반환한다.

**허용함수**

- `malloc`

**구현**

```c
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && start + i < ft_strlen(s))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
```

`len(s) < start` 일때 null을 리턴하면 될 줄 알았는데 빈문자열을 반환해야지 테스터에 통과했다.



## 2. ft_strjoin

**프로토타입**

`char    *ft_strjoin(char const *s1, char const *s2)`

**설명**

> `malloc()`으로 새로운 문자열을 할당하고 반환한다.
>
> 새로운 문자열은 문자열 `s1`과 문자열 `s2` 가 연결된 형태이다.

**파라미터**

- `s1` : 앞에 올 문자열
- `s2` : 뒤에 올 문자열

**리턴값**

- `s1`과 `s2`가 합쳐진 새로운 문자열
- 실패시 null 반환

**허용함수**

- `malloc`

**구현**

```c
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (!s1 ? (char*)s2 : (char*)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_s)
		return (0);
	ft_memcpy(new_s, s1, s1_len);
	ft_memcpy(new_s + s1_len, s2, s2_len);
	new_s[s1_len + s2_len] = 0;
	return (new_s);
}
```



## 3. ft_strtrim

**프로토타입**

`char	*ft_strtrim(char const *s1, char const *set);`

**설명**

> 문자열 `s1` 의 앞에서 부터 탐색하면서 문자열 `set` 에 포함된 문자가 있다면 제거한다. 
>
> 같은방식으로 문자열 `s1` 의 뒤에서부터 탐색하면서  문자열 `set` 에 포함된 문자가 있다면 제거한다. 
>
> 그 결과를  `malloc` 으로 할당한 뒤 리턴한다.

**파라미터**

- `s1` : 원형 문자열
- `set` : 원형 문자열 앞, 뒤에서 삭제할 문자열

**리턴값**

- trim이 완료된 문자열을 반환한다.
- s1이 null이면 null을 리턴한다.
- set이 null이면 s1을 그대로 리턴한다.
- 실패시 null을 반환한다.

**허용함수**

- `malloc`

**구현**

```c
int		ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return ((char*)s1);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_char_in_set(s1[end], set))
		end--;
	new_s = (char*)malloc(sizeof(char) * (end - start + 2));
	if (!new_s)
		return (0);
	i = 0;
	while (start <= end)
	{
		new_s[i] = s1[start];
		i++;
		start++;
	}
	new_s[i] = 0;
	return (new_s);
}
```



## 4. ft_split

**프로토타입**

`char **ft_split(char const *s, char c);`

**설명**

> 문자 `c` 를 기준으로 문자열 `s` 를 분할하여 새로운 문자열 배열로 반환한다.
>
> 새로운 문자열 배열은 NULL로 끝나야한다.

**파라미터**

- `s` : 원형 문자열
- `c` : 원형 문자열에서 분할을 할 때 기준이 될 문자

**리턴값**

- 분할된 문자열 배열
- 할당 실패시 NULL

**허용함수**

- `malloc`

**구현1**

```c
char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*copy;

	if (!src || n <= 0)
		return (0);
	copy = (char*)malloc(sizeof(char) * (n + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

size_t	ft_word_count(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while(s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			cnt++;
		}
		else
			i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	res_idx;
	unsigned int	s_idx;
	unsigned int	c_cnt;

	if (!s)
		return (0);
	if (!(res = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (0);
	res_idx = 0;
	s_idx = 0;
	while (s[s_idx] && s_idx < ft_strlen(s))
	{
		c_cnt = 0;
		if (s[s_idx] != c)
		{
			while (s[s_idx + c_cnt] != c && s[s_idx + c_cnt])
				c_cnt++;
			res[res_idx] = ft_strndup((char*)s + s_idx, c_cnt);
			res_idx++;
		}
		s_idx += c_cnt + 1;
	}
	res[res_idx] = 0;
	return (res);
}

```





## 5. ft_itoa

**프로토타입**

`int ft_get_length(int n)`

**설명**

> 정수를 문자열로 바꾸어 리턴한다. (음수도 처리 해야한다.)

**파라미터**

- `n` : 정수

**리턴값**

- 정수를 나타내는 문자열
- 할당 실패시 NULL.

**허용함수**

- `malloc`

**구현1**

```c
//길이구하고 malloc, 나머지를 뒤에서부터 채워넣기
int		ft_get_length(int n)
{
	int		len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		ft_abs(long n)
{
	return ((n < 0) ? -n : n);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	len = ft_get_length(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = 0;
	len--;
	while (len >= 0)
	{
		res[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
        // n = n / 10; 절대값을 안취해도 상관없다. 웨에서 절대값되기 때문에
		len--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
```

**구현2**

```c
// 나머지를 앞에서부터 채워넣고 뒤집기
```





## 6. ft_strmpi

**프로토타입**

```C
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

**설명**

> 문자열 `s`의 각 문자에 `f`함수를 연속적으로 적용시킨 새로운 문자열을 만들기.
>
> s의 길이를 재서 s 길이 + 1만큼 result에 malloc해주고
> result의 요소 각각에 (*f)(i, s[i])한 결과를 담은 뒤 
> 마지막을 null terminating 해준다.

**파라미터**

- `s` : 처리할 문자열
- `(*f)` : 문자열을 처리할 함수

**리턴값**

-  `(*f)(i, s[i])` 한 결과들을 포인터 배열에 담아서 리턴한다.
- 할당 실패시 NULL.

**허용함수**

- `malloc`

**구현**

```c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
        // res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
```





## 7. ft_putchar_fd

**프로토타입**

`void ft_putchar_fd(char c, int fd);`

**설명**

> 문자 'c'를 주어진 파일디스크립터로 출력한다.

**파라미터**

- `c` : 출력할 문자
- `fd` : 쓰여질 파일디스크립터

**리턴값**

- None

**허용함수**

- `write`

**구현**

```c
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
```



## 8. ft_putstr_fd

**프로토타입**

`void ft_putstr_fd(char *s, int fd);`

**설명**

> 문자열 `s` 를 주어진 파일디스크립터로 출력한다.

**파라미터**

- `s` : 출력할 문자열
- `fd` : 쓰여질 파일디스크립터

**리턴값**

- None

**허용함수**

- `write`

**구현**

```c
void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}
```



## 9. ft_putendl_fd

**프로토타입**

`void ft_putendl_fd(char *s, int fd);`

**설명**

> 문자열 `s` 를 주어진 파일디스크립터로 출력하고 newline으로 끝내기.

**파라미터**

- `s` : 출력할 문자열
- `fd` : 쓰여질 파일디스크립터

**리턴값**

- None

**허용함수**

- `write`

**구현**

```c
void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
```



## 10. ft_putnbr_fd

**프로토타입**

`void ft_putnbr_fd(int n, int fd);`

**설명**

> 정수 `n`을 주어진 파일디스크립터로 출력한다.

**파라미터**

- `n` : 출력할 정수
- `fd` : 쓰여질 파일디스크립터

**리턴값**

- None

**허용함수**

- `write`

**구현**

```c
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = (n < 0) ? -n : n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}
```

