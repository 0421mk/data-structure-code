#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(LData d1, LData d2)
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
	LData data;
	int sum = 0;
	ListInit(&list);
	
	SetSortRule(&list, WhoIsPrecede); // ������ ������ ����մϴ�. 
	
	// 5���� ������ ����
	LInsert(&list, 2); 
	LInsert(&list, 4);
	LInsert(&list, 6);
	LInsert(&list, 8);
	
	// ����� �������� ��ü ���
	printf("���� ������ ��: %d \n", LCount(&list));
	
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
		{
			printf("%d ", data);
			sum += data;	
		}
	}
	
	return 0;
}
