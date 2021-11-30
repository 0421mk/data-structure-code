#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) // 스택의 초기화
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack) // 스택이 비었는지 확인합니다.
{
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) // 스택의 데이터 추가
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) // 스택의 데이터 삭제 
{
	int rIdx; // 삭제 인덱스 변수
	
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1);
	}
	
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1; // 삭제 연산 
	
	return pstack->stackArr[rIdx];
}

Data Speek(Stack * pstack) // 스택의 최상단 데이터 확인
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}
