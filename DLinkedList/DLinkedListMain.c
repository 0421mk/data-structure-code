#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(LData d1, LData d2)
{
	if(d1 < d2)
		return 0;
	else
		return 1; // 1이면 종료 
}

int main(void)
{
	// 리스트의 생성 및 초기화
	List list;
	LData data;
	ListInit(&list);
	
	SetSortRule(&list, WhoIsPrecede); // 정렬의 기준을 등록합니다. 
	
	while(1) {
		printf("자연수 입력: ");
		scanf("%d", &data);
		
		if(data < 1) {
			break;
		}
		
		LInsert(&list, data);
	}
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	return 0;
}
