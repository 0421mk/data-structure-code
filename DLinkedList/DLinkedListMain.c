#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
	if(d1 < d2)
		return 0;
	else
		return 1; // 1�̸� ���� 
}

int main(void)
{
	// ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	int data;
	int sum = 0;
	ListInit(&list);
	
	SetSortRule(&list, WhoIsPrecede); // ������ ������ ����մϴ�. 
	
	// 5���� ������ ����
	LInsert(&list, 2); 
	LInsert(&list, 6);
	LInsert(&list, 10);
	LInsert(&list, 8);
	LInsert(&list, 4);
	
	// ����� �������� ��ü ���
	printf("���� ������ ��: %d \n", LCount(&list));
	
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		sum += data;
		
		while(LNext(&list, &data))
		{
			printf("%d ", data);
			sum += data;	
		}
	}
	
	printf("\n\n");
	
	printf("sum : %d \n", sum);
	
	printf("\n\n");
	
	// ���� 22�� �˻��Ͽ� ��� ����
	if(LFirst(&list, &data))
	{
		if(data % 2 == 0) // data�� ��ġ�ϴ� ������ cur �ּҰ��� LRemove�� ���ϴ�. 
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data % 2 == 0)
				LRemove(&list);
		}
	}
	
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);	
	}
	
	
	return 0;
}
