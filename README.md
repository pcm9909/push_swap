* push_swap

## 목차
[Compile](#1.-Compile)

[과제 소개](#2.-과제-소개)

[func](#3.-func)

[tip](#4.-tip)
## 1. Compile
Compile
```
make
make bonus
```
실행
```
./push_swap [value]
./checker [value]

value example >
5 4 3 2 1
"5 4 3 2 1"
```

## 2. 과제 소개
주어진 func를 활용하여 stack을 오름차순으로 정렬하는 것이 목표다

PDF에서 명시된 stack은 우리가 알고 있는 일반적인 stack과 다르다 

stack이라 함은 아래 사진과 같이 최상단(head)에서 삽입(push)과  삭제(pop)이 일어난다

하지만 과제에서 명시된 stack은 rotate, swap 등 최하단(tail)의 값, 최상단(head)의 다음 값도 조작이 가능하다

stack과 dequeue 중간 어딘가인 거 같다.

실행 파일은 중복 없는 int 값만을 인자로 받을 수 있다 정수가 아닌 경우에는 "Error"를 출력해야 한다.

```
./push_swap 1 2 2 3
-> 중복
 
./push_swap 1 2 33333333333333333
-> int범위를 벗어남

./push_swap 2 3 one
-> 정수가 아님
```
먼저 스택을 어떻게 구현할 것인가?

스택은 배열과 연결 리스트로 구현이 가능하다

​

스택의 장점은 탐색 속도가 빠르나 

값을 삽입하거나 삭제할 때 배열 전체를 재할당 해야 하는 구현 복잡성의 문제가 있다

연결 리스트는 탐색 속도가 느리나 

삽입 삭제에 있어 스택에 비해 간편하기 때문에 연결 리스트를 활용해 스택을 구현하였다

어떤 것으로 구현하든 상관 없으나 연결 리스트를 추천한다

```
typedef struct s_node
{
	struct s_node	*prev;
	int				data;
	int				idx;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}				t_stack;
```
먼저 스택을 어떻게 구현할 것인가?

스택은 배열과 연결 리스트로 구현이 가능하다

스택의 장점은 탐색 속도가 빠르나 

값을 삽입하거나 삭제할 때 배열 전체를 재할당 해야 하는 구현 복잡성의 문제가 있다

연결 리스트는 탐색 속도가 느리나 

삽입 삭제에 있어 스택에 비해 간편하기 때문에 연결 리스트를 활용해 스택을 구현하였다

어떤 것으로 구현하든 상관 없으나 연결 리스트를 추천한다

# 3. func

주어진 func는 다음과 같다 
1. push
2. swap
3. rotate
4. reverse_rotate

push(pa, pb) : 스택의 최상단(head) 값을 대상 stack의 최상단(head)으로 삽입한다
```
void	push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!src->head)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	dst->size++;
	src->size--;
	if (!dst->head)
	{
		dst->head = tmp;
		dst->tail = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = dst->head;
		dst->head->prev = tmp;
		dst->head = tmp;
	}
}
```

swap(sa, sb) : 스택에 최상단(head)의 값과 그다음 값을 바꾼다. 
```
void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	tmp->prev = stack->head;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
}
```

rotate(ra, rb, rr) : 최상단(head)의 값을 최하단(tail)으로 보낸다
```
void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = tmp;
	tmp->prev = stack->tail;
	stack->tail = tmp;
	tmp->next = NULL;
}
```

reverse_rotate(rra, rrb, rrr) : rotate의 반대로 최하단(tail)의 값을 최상단(head)로 보낸다
```
void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	stack->head = tmp;
}
```

## 4. tip
알고리즘은 입맛에 맞는 것을 선택하면 된다

1. 모래시계 sort 
2. quick sort
3. merge sort
4. radix sort
5. greedy
   +등등

​

모래시계 sort는 push_swap에만 적용되는 sorting 방식이다

sorting을 공부하고 싶다면 다른 sorting 알고리즘을 선택하는 것을 추천한다 

평가에 숫자 100개의 값이 700번 이하로 숫자 500개의 값이 5500번 이하로 정렬되어야 100점을 받을 수 있다 

직접 값을 넣기는 무리가 있으니 아래 명령어를 사용하는 것을 추천한다 

랜덤 값을 생성해 환경 변수에 저장하고 실행시켜준다 
```
RG=$(seq 10000 | shuf -n [숫자 갯수] | sort -uR | tr '\n' ' ' | sed 's/ $//'); [실행 파일 이름] $RG

예시
RG=$(seq 10000 | shuf -n 5 | sort -uR | tr '\n' ' ' | sed 's/ $//'); ./a.out $RG
정렬 확인
RG=$(seq 10000 | shuf -n 5 | sort -uR | tr '\n' ' ' | sed 's/ $//'); ./a.out $RG | ./checker_linux $RG
명령 횟수 확인
RG=$(seq 10000 | shuf -n 5 | sort -uR | tr '\n' ' ' | sed 's/ $//'); ./a.out $RG | wc -l
```
