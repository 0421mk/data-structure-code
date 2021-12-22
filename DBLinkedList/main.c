#include <stdio.h>
#include "DBLinkedList.h"

int main(void) {
	List list;
	int data;
	ListInit(&list);
	
	// 1부터 8까지 8개의 데이터를 오름차순으로 저장해주세요. 
	LInsert(&list, 8);
	LInsert(&list, 7);
	LInsert(&list, 6);
	LInsert(&list, 5);
	LInsert(&list, 4);
	LInsert(&list, 3);
	LInsert(&list, 2);
	LInsert(&list, 1);
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	printf("\n\n");
	
	printf("현재 데이터 수: %d", LCount(&list));
	
	printf("\n\n");
	
	// 저장된 데이터를 조회해주세요.
	// 1 2 3 4 <- 4 3 2 1 -> 2 3 4 5 6 7 8 <- 7 6 5 4 3 2 1
	// 조회된 데이터는 위와 같은 순서를 갖습니다.
	// LNext와 LPrevious를 이용해서 위와 같이 참조해주세요. 
	// 중간에 화살표 방향도 체크해주세요.
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
		
		printf("<- ");
				
		while(LPrevious(&list, &data)) {
			printf("%d ", data);
		}
		
		printf("-> ");
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
			n++;
		}
		
		printf("<- ");
		
		while(LPrevious(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	return 0;
}
