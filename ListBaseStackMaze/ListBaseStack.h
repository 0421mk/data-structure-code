#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE 1
#define FALSE 0

typedef struct _point
{
	int x;
	int y;
} Point;

typedef Point Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack
{
	Node * head; // 노드 주소값을 담을 수 있는 자료형으로 ListStack을 정의 
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack); // 스택 초기화 
int SIsEmpty(Stack * pstack); // 스택이 비었는지 확인 

void SPush(Stack * pstack, Data data); // 스택의 데이터 삽입 
Data SPop(Stack * pstack); // 스택의 최상단 값 반환 및 삭제 
Data SPeek(Stack * pstack); // 스택의 최상단 데이터 반환 

#endif
