#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) // ������ �ʱ�ȭ
{
	pstack->topIndex = -1;
	// �����ʹ� -1�� ����
	// �����͸� �߰��� ������ topIndex 1�� ���� 
}

int SIsEmpty(Stack * pstack) // ������ ������� Ȯ���մϴ�.
{
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

// �ε����� 0~99�����ϱ� -1 ���־�� �Ѵ�.
// ������ �� á���� Ȯ���մϴ�. 
int SIsFull(Stack * pstack)
{ 
	if (pstack->topIndex == STACK_LEN-1)
		return TRUE; 
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) // ������ ������ �߰�
{
	if(SIsFull(pstack))
	{
		printf("Stack Overflow!");
		exit(-1); // ���� �޽��� ��� �� ���μ��� ���� 
	}
	
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) // ������ ������ ���� 
{
	int rIdx; // ���� �ε��� ����
	
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1); // ���� �޽��� ��� �� ���μ��� ���� 
	}
	
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1; // ���� ����
	// rIdx�� ������ ���� 0���� �ʱ�ȭ���� �ʴ� ����: �迭���� ������ ���� 0���� �����ϴ°� �ǹ̰� �����ϴ�.
	// ������ topIndex ������ ���� ��ġ�ϰ� �ִٸ� ��ȿ�� �����ͷ� ������ ���ް� ���� �����Ͱ� ���Ե� ��� ��������� �˴ϴ�. 
	
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
