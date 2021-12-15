#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(char * d1, char * d2)
{
	if(d1[0] < d2[0])
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
	LInsert(&list, "��"); 
	LInsert(&list, "��");
	LInsert(&list, "��");
	LInsert(&list, "��");
	
	// ����� �������� ��ü ���
	printf("���� ������ ��: %d \n", LCount(&list));
	
	if(LFirst(&list, &data))
	{
		printf("%s ", data);
		
		while(LNext(&list, &data))
		{
			printf("%s ", data);
			sum += data;	
		}
	}
	
	return 0;
}
