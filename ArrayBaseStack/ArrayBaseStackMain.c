#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	// Stack의 생성 및 초기화
	Stack stack;
	StackInit(&stack);
	
	// 데이터 넣기
	SPush(&stack, 1); 
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	
	while(!SIsEmpty(&stack))
	{
		printf("%d ", SPop(&stack)); // 가장 마지막에 들어간 값이 가장 먼저 나옵니다. 
	}
	
	return 0;
}
