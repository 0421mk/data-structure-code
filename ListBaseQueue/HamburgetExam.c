#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListBaseQueue.h"

#define CUSTOMER_TERM 30

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 45
#define BUL_TERM 60
#define DUB_TERM 80

// 1시간 동안 주문을 받으면서 동시에 조리한다면 얼마나 주문을 처리할 수 있을까?
 
int main(void)
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int cheMake = 0, bulMake = 0, dubMake = 0;
	int sec;
	
	Queue que;
	
	QueueInit(&que);
	srand(time(NULL)); // 1970 1월 1일부터 현재까지 흐른 시간 초단위로 반환(매번 바뀜)
	// srand에 넣으면 진짜 난수 생성 -> srand에 따라 rand 함수 값이 바뀜 
	
	for(sec=0; sec<3600; sec++) // for문의 1회전은 1초의 시간 흐름을 의미 
	{
		if(sec % CUSTOMER_TERM == 0) // 해당 논리식은 고객이 1회 주문할때마다 작동 
		{
			// 주문 섹션 
			switch(rand() % 3) // 난수 생성, 난수의 결과는 0, 1, 2 중 하나 
			{
				///
				case CHE_BUR:
					Enqueue(&que, CHE_TERM);
					cheOrder++;
					break;
				case BUL_BUR:
					Enqueue(&que, BUL_TERM);
					bulOrder++;
					break;
				case DUB_BUR:
					Enqueue(&que, DUB_TERM);
					dubOrder++;
					break;
				///
			}
		}
		
		// 조리 섹션
		if(makeProc<=0 && !QIsEmpty(&que)) {
			makeProc = Dequeue(&que); // 제작중
			
			switch(makeProc)
			{
				case CHE_TERM:
					cheMake++;
					break;
				case BUL_TERM:
					bulMake++;
					break;
				case DUB_TERM:
					dubMake++;
					break;
			}
		}
		
		makeProc--; 
	}
	
	printf("Simulation Report!\n");
	printf(" - 치즈버거 주문량: %d, 실제 주문 처리량: %d\n", cheOrder, cheMake);
	printf(" - 불고기버거 주문량: %d, 실제 주문 처리량: %d\n", bulOrder, bulMake);
	printf(" - 더블버거 주문량: %d, 실제 주문 처리량: %d\n", dubOrder, dubMake);
	
	return 0;
}
