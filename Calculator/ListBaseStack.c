#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack) {
	pstack->head = NULL;
}
int SIsEmpty(Stack * pstack) {
	if(pstack->head == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = pstack->head;
	
	pstack->head = newNode;
	// 데이터 위쪽부터 삽입 
}

Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;
	
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	rdata = pstack->head->data;
	rnode = pstack->head;
	
	pstack->head = pstack->head->next; // 아래로 이동
	free(rnode);
	
	return rdata; 
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->head->data;
}
