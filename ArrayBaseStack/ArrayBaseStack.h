#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack); // 스택의 초기화 
int SIsEmpty(Stack * pstack); // 스택이 비었는지 확인합니다. 

void SPush(Stack * pstack, Data data); // 스택의 데이터 추가 
Data SPop(Stack * pstack); // 스택의 데이터 삭제 

Data Speek(Stack * pstack); // 스택의 최상단 데이터 확인

#endif
