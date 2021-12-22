#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) // 스택의 초기화
{
	pstack->topIndex = -1;
	// 데이터는 -1로 설정
	// 데이터를 추가할 때마다 topIndex 1씩 증가 
}

int SIsEmpty(Stack * pstack) // 스택이 비었는지 확인합니다.
{
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

// 인덱스는 0~99까지니까 -1 해주어야 한다.
// 스택이 꽉 찼는지 확인합니다. 
int SIsFull(Stack * pstack)
{ 
	if (pstack->topIndex == STACK_LEN-1)
		return TRUE; 
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) // 스택의 데이터 추가
{
	if(SIsFull(pstack))
	{
		printf("Stack Overflow!");
		exit(-1); // 에러 메시지 출력 후 프로세스 종료 
	}
	
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) // 스택의 데이터 삭제 
{
	int rIdx; // 삭제 인덱스 변수
	
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1); // 에러 메시지 출력 후 프로세스 종료 
	}
	
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1; // 삭제 연산
	// rIdx의 데이터 값을 0으로 초기화하지 않는 이유: 배열에서 삭제를 위해 0으로 세팅하는건 의미가 없습니다.
	// 어차피 topIndex 값보다 위에 위치하고 있다면 유효한 데이터로 인정을 못받고 또한 데이터가 삽입될 경우 덮어씌어지면 됩니다. 
	
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
