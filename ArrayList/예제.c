#include <stdio.h>
#include "ArrayList.h"

int exam2(void) {
	
	// ArrayList�� ���� �� �ʱ�ȭ 
	List list; // �ּҰ� �Ҵ� 
	int data;
	int sum = 0;
	ListInit(&list);
	
	// 10���� ������ ����
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	LInsert(&list, 9);
	
	printf("=== ��ü ������ ��ȸ ===\n");
	
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data)) 
		{
			printf("%d ", data);
		}
	}
	
	if(LFirst(&list, &data)) 
	{
		
		sum += data;
		
		while(LNext(&list, &data)) 
			sum += data;
	}
	
	printf("\n\n");
	printf("Sum: %d", sum);
	printf("\n\n");
	
	if(LFirst(&list, &data)) 
	{
		if(data % 2 == 0 || data % 3 == 0) {
			LRemove(&list);
		}
		
		while(LNext(&list, &data))
		{
			if(data % 2 == 0 || data % 3 == 0) {
				LRemove(&list);
			}
		}
	}
	
	printf("=== ��ü ������ ��ȸ ===\n");
	
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data)) 
		{
			printf("%d ", data);
		}
	}
	
	return 0;
}
