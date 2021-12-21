#include <stdio.h>
#include "DBLinkedList.h"

int main(void) {
	List list;
	int data;
	ListInit(&list);
	
	// 1부터 8까지 8개의 데이터를 저장해주세요. 
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	
	// 저장된 데이터를 조회해주세요.
	// 8 7 6 5 5 6 7 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8
	// 조회된 데이터는 위와 같은 순서를 갖습니다.
	// LNext와 LPrevious를 이용해서 순서대로 출력해주세요. 
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
