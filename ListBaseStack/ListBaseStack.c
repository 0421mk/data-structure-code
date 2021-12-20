#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack) // 스택 초기화
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack) // 스택이 비었는지 확인 
{
	if(pstack->head == NULL)
	{
		return TRUE;
	} else {
		return FALSE;
	}
}

void SPush(Stack * pstack, Data data) // 스택의 데이터 삽입
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = pstack->head;
	
	// printf("[스택 추가 %d, %d] > ", data.x, data.y);
	
	pstack->head = newNode;
}

Data SPop(Stack * pstack) // 스택의 최상단 값 반환 및 삭제
{
	Data rdata; // 삭제 데이터 
	Node * rnode; // 삭제 데이터의 주소값
	
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1);
	}
	
	rdata = pstack->head->data;
	rnode = pstack->head;
	
	pstack->head = pstack->head->next;
	
	// printf("[스택 삭제 %d, %d] > ", rdata.x, rdata.y);
	free(rnode);
	
	return rdata;
}

Data SPeek(Stack * pstack) // 스택의 최상단 데이터 반환
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1);
	}
		
	return pstack->head->data;
}
