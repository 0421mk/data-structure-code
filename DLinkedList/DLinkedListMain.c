#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	// 리스트의 생성 및 초기화
	List list;
	int data;
	int sum = 0;
	ListInit(&list);
	
	// 5개의 데이터 저장
	LInsert(&list, 1); 
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	
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
