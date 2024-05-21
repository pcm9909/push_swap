* push_swap

## 목차
컴파일(##1.-컴파일)

과제 소개

func

## 1. 컴파일
컴파일
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

##2. 과제 소개
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

