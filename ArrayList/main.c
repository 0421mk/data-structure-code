#include <stdio.h>
#include "ArrayList.h"

int exam(void) {
	
	// ArrayList�� ���� �� �ʱ�ȭ 
	List list; // �ּҰ� �Ҵ� 
	int data;
	ListInit(&list);
	
	// 5���� ������ ����
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	
	// ����� ������ ���
	if(LFirst(&list, &data)) // data ������ ������ ù��° ������ ���� ����˴ϴ�. 
	{
		printf("%d ", data); // ������ �����͸� ��� 
		
		while(LNext(&list, &data)) // data ������ ������ �ι�° ������ ���� ��������ϴ�.
			printf("%d ", data); 
	}
	
	return 0;
}
