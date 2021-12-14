#include <stdio.h>
#include "DLinkedList.h"

int main(void) {
	List list;
	int data;
	ListInit(&list);
	
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	if(LFirst(&list, &data))
	{
		if(data==2) {
			LRemove(&list);
		}
		
		while(LNext(&list, &data)) {
			if(data==2) {
				LRemove(&list);
			}
		}
	}
	
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	return 0;
}
