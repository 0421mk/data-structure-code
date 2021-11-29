#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	// ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	int data;
	int sum = 0;
	ListInit(&list);
	
	// 5���� ������ ����
	LInsert(&list, 1); 
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	
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
