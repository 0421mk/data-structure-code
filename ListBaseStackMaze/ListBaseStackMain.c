#include <stdio.h>
#include "ListBaseStack.h"

int main(void)
{
	Stack stack; // ������ �޸� ������ �Ҵ�˴ϴ�. 
	StackInit(&stack); // ���� �ʱ�ȭ
	
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
