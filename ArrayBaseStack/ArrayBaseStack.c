#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) // ������ �ʱ�ȭ
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack) // ������ ������� Ȯ���մϴ�.
{
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) // ������ ������ �߰�
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) // ������ ������ ���� 
{
	int rIdx; // ���� �ε��� ����
	
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1);
	}
	
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1; // ���� ���� 
	
	return pstack->stackArr[rIdx];
}

Data Speek(Stack * pstack) // ������ �ֻ�� ������ Ȯ��
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}
