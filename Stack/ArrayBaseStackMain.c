#include <stdio.h>
#include "ArrayBaseStack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	// Stack�� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);
	
	// ������ �ֱ�
	SPush(&stack, 1); 
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	
	while(!SIsEmpty(&stack))
	{
		printf("%d ", SPop(&stack)); // ���� �������� �� ���� ���� ���� ���ɴϴ�. 
	}
	
	return 0;
}
