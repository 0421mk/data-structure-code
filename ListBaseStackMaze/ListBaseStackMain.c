#include <stdio.h>
#include "ListBaseStack.h"

int main(void)
{
	Stack stack; // 스택이 메모리 공간에 할당됩니다. 
	StackInit(&stack); // 스택 초기화
	
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	
	while(!SIsEmpty(&stack))
	{
		int num = SPop(&stack);
		printf("%d ", num);
	}
		
	return 0;
}
