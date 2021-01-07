## 0. 구현 목록

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`



## 1. ft_lstnew

**프로토타입**

`t_list *ft_lstnew(void *content);`

**설명**

> malloc(3)을 할당하고 새로운 요소(노드)를 반환. 변수 'content'는 매개변수 'content'의 값에 따라 초기화된다. 변수 'next'는 NULL로 초기화된다.
>
> 즉, 새로운 리스트를 초기화하는 함수이다.

**파라미터**

- `content` : 새로운 요소(노드)를 만들 content


**리턴값**

- 새로운 요소

**구현**

```c
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}
```



## 2. ft_lstadd_front

**프로토타입**

`void ft_lstadd_front(t_list **lst, t_list *new);`

**설명**

> 리스트의 시작부분에 요소 `new`를 추가.
>
> 기존에 있는 리스트에서 맨앞에 새로운 노드를 추가한다.

**파라미터**

- `**lst` : 첫 번째 링크 리스트의 포인터 주소
- `*new` : 새로운 노드의 포인터 조수

**리턴값**

- None

**구현**

```c
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new) //*lst == NULL 도 예외처리 잡아야할까?
		return ;
	new->next = *lst;
	*lst = new;
}
```

lst가 2중포인터인것은 *lst에 저장되는 값이 연결된 리스트들의 첫값을 담고있기 때문입니다.
new->next = *lst를 하여도 new라는 리스트 뒤에 *lst에 저장되어있던 리스트가 연결되었을 뿐 연결리스트의 시작이 new인것은 아니기 때문에 이를 명시하기위하여 *lst에 new를 담는것입니다.(이전 피신때 ft_ultimate_range를 생각해보시면 됩니다.)

*lst에 list1->list2->list3가 있고 new라는 list를 제일 앞에 붙인다고 하면
new->next = *lst를 통해
new->list1->list2->list3라는 연결구조가 생기겠죠?
그러면 이 리스트가 반환이 되어야 하지만 이 함수는 void함수입니다.
따라서 new가 시작임을 명시해주어야 하는데, 이를 위해 받아오는 파라미터 자체가 2중포인터인것입니다.
*lst = new를 담음으로써 *lst엔 new->list1->list2->list3로 연결되는 연결구조가 담기는것이죠.

## 3. ft_lstsize

**프로토타입**

`int ft_lstsize(t_list *lst);`

**설명**

>  리스트의 노드의 갯수를 센다.

**파라미터**

- `*lst` : 리스트의 시작

**리턴값**

- 리스트의 길이

**구현**

```c
int		ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
```



## 4. ft_lstlast

**프로토타입**

`t_list *ft_lstlast(t_list *lst);`

**설명**

> 리스트의 마지막 노드를 반환.

**파라미터**

- `*lst` : 리스트의 시작

**리턴값**

- 리스트의 마지막 노드

**구현**

```c
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
```



## 5. ft_lstadd_back

**프로토타입**

`void ft_lstadd_back(t_list **lst, t_list *new);`

**설명**

> 리스트의 끝에 `new` 노드를 추가.

**파라미터**

- 첫 번째 연결리스트의 포인터 주소
- 새로 추가할 노드의 포인터 주소

**리턴값**

- None

**구현**

```c
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == 0)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}
```



## 6. ft_lstdelone

**프로토타입**

`void ft_lstdelone(t_list *lst, void (*del)(void *));`

**설명**

> 매개변수로 요소를 가져오고 매개변수로 주어진 함수 'del'을 적용시켜 요소의 content의 주소를 free하고 난 뒤 요소를 free. 'next'의 주소는 free되지 않아야함.

**파라미터**

- free할 노드
- content를 삭제하는데 사용되는 함수 포인터

**리턴값**

- None

**구현**

```c
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
```



## 7. ft_lstclear

**프로토타입**

`void ft_lstclear(t_list **lst, void (*del)(void *));`

**설명**

> 함수 'del'과 free(3)을 사용하여, 
>
> 주어진 노드와 해당 노드의 모든 후속 노드를 삭제하고 free함.

**파라미터**

- 노드의 포인터 주소
- 노드의 content를 삭제하는데 사용되는 함수 포인터

**리턴값**

- None

**구현**

```c
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = 0;
}
```



## 8. ft_lstiter

**프로토타입**

`void ft_lstiter(t_list *lst, void (*f)(void *));`

**설명**

> 리스트 'lst'를 반복하여 각 요소의 content에 함수 'f'를 적용시킴.

**파라미터**

- 노드의 포인터
- 리스트에 반복적으로 사용되는 함수 포인터

**리턴값**

- None

**구현**

```c
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
```



## 9. ft_lstmap

**프로토타입**

`t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`

**설명**

> 리스트 'lst'를 반복하여 각 요소의 content에 함수 'f'를 적용. 
>
> 함수 'f'를 연속적으로 적용시켜 새로운 리스트를 만듬. 
>
> 필요한 경우 함수 'del'은 요소의 content를 삭제하는데 사용됨.

**파라미터**

- 노드의 포인터주소
- 리스트에 반복적으로 사용되는 함수 포인터
- 필요한 경우 노드의 content를 삭제하기 위해 사용되는 함수 포인터

**리턴값**

- 새로운 리스트
- 할당 실패시 NULL

**구현**

```c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	res = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, tmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (res);
}
```

