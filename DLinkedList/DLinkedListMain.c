#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(char * d1, char * d2)
{
	if(d1[0] < d2[0])
		return 0;
	else
		return 1; // 1이면 종료 
}

int main(void)
{
	// 리스트의 생성 및 초기화
	List list;
	LData data;
	int sum = 0;
	ListInit(&list);
	
	SetSortRule(&list, WhoIsPrecede); // 정렬의 기준을 등록합니다. 
	
	// 5개의 데이터 저장
	LInsert(&list, "다"); 
	LInsert(&list, "라");
	LInsert(&list, "가");
	LInsert(&list, "나");
	
	// 저장된 데이터의 전체 출력
	printf("현재 데이터 수: %d \n", LCount(&list));
	
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
