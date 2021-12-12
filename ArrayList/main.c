#include <stdio.h>
#include "ArrayList.h"

int exam(void) {
	
	// ArrayList의 생성 및 초기화 
	List list; // 주소값 할당 
	int data;
	ListInit(&list);
	
	// 5개의 데이터 저장
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	
	// 저장된 데이터 출력
	if(LFirst(&list, &data)) // data 변수에 참조된 첫번째 데이터 값이 저장됩니다. 
	{
		printf("%d ", data); // 참조된 데이터를 출력 
		
		while(LNext(&list, &data)) // data 변수에 참조된 두번째 데이터 값이 덮어씌어집니다.
			printf("%d ", data); 
	}
	
	return 0;
}
