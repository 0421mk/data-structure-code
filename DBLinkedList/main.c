#include <stdio.h>
#include "DBLinkedList.h"

int main(void) {
	List list;
	int data;
	ListInit(&list);
	
	// 1���� 8���� 8���� �����͸� �������ּ���. 
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	
	// ����� �����͸� ��ȸ���ּ���.
	// 8 7 6 5 5 6 7 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8
	// ��ȸ�� �����ʹ� ���� ���� ������ �����ϴ�.
	// LNext�� LPrevious�� �̿��ؼ� ������� ������ּ���. 
	int n = 0;
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			if(n == 3) {
				break;
			}
			printf("%d ", data);
			n++;
		}
				
		while(LPrevious(&list, &data)) {
			printf("%d ", data);
		}
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
			n++;
		}
		
		while(LPrevious(&list, &data)) {
			printf("%d ", data);
		}
		
	}
	
	return 0;
}
