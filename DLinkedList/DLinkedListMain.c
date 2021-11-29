#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
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
	int data;
	int sum = 0;
	ListInit(&list);
	
	SetSortRule(&list, WhoIsPrecede); // 정렬의 기준을 등록합니다. 
	
	// 5개의 데이터 저장
	LInsert(&list, 2); 
	LInsert(&list, 6);
	LInsert(&list, 10);
	LInsert(&list, 8);
	LInsert(&list, 4);
	
	// 저장된 데이터의 전체 출력
	printf("현재 데이터 수: %d \n", LCount(&list));
	
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
	
	// 숫자 22을 검색하여 모두 삭제
	if(LFirst(&list, &data))
	{
		if(data % 2 == 0) // data가 일치하는 순간에 cur 주소값이 LRemove로 들어갑니다. 
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
