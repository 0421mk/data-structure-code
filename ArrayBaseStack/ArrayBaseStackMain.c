#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	// Stack�� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);
	
	// ������ �ֱ�
	// ���� �տ� �ִ� ���� topIndex 
	SPush(&stack, 1); 
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	SPush(&stack, 6); 
	SPush(&stack, 7);
	SPush(&stack, 8);
	SPush(&stack, 9);
	SPush(&stack, 10);
	
	// ������ ��� �����͸� ��ȸ���ּ���.
	// ������ �ֻ�� �����͸� ��ȸ�����ϹǷ� ��� �����͸� ��ȸ�Ϸ��� ������ ���ݵǾ�� �մϴ�. 
	// SIsEmpty �Լ��� �̿��ϸ� �˴ϴ�. 
	while(!SIsEmpty(&stack))
	{
		printf("%d ", SPop(&stack)); // ���� �������� �� ���� ���� ���� ���ɴϴ�. 
	}
	
	printf("\n\n");
	
	// ���� ���ÿ� �����Ͱ� ������ �����Դϴ�.
	// ������ ���¿��� �����͸� �ٽ� �ѹ� ��ȸ���ּ���.
	int i;
	
	for(i=0; i<10; i++) {
		printf("%d ", stack.stackArr[i]); 
	}
	
	// ��� �����Ͱ� ������ �������� �ʾҽ��ϴ�.
	// �迭�� ���� ������ �����͸� �ʱ�ȭ���� �ʰ� ���ܵ� �� ������ ����� ����մϴ�.
	// (�迭�� ó������ �̹� �޸� ������ �����Ǿ� �����Ƿ�) 
	// ���Ḯ��Ʈ�� �ٸ��ϴ�. 
	
	return 0;
}
