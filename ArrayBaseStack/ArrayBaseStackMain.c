#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	// Stack의 생성 및 초기화
	Stack stack;
	StackInit(&stack);
	
	// 데이터 넣기
	// 가장 앞에 있는 값이 topIndex 
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
	
	// 스택의 모든 데이터를 조회해주세요.
	// 스택은 최상단 데이터만 조회가능하므로 모든 데이터를 조회하려면 삭제가 수반되어야 합니다. 
	// SIsEmpty 함수를 이용하면 됩니다. 
	while(!SIsEmpty(&stack))
	{
		printf("%d ", SPop(&stack)); // 가장 마지막에 들어간 값이 가장 먼저 나옵니다. 
	}
	
	printf("\n\n");
	
	// 현재 스택에 데이터가 삭제된 상태입니다.
	// 삭제한 상태에서 데이터를 다시 한번 조회해주세요.
	int i;
	
	for(i=0; i<10; i++) {
		printf("%d ", stack.stackArr[i]); 
	}
	
	// 사실 데이터가 완전히 삭제되지 않았습니다.
	// 배열의 삭제 연산은 데이터를 초기화하지 않고 남겨둔 뒤 덮어씌우는 방식을 사용합니다.
	// (배열은 처음부터 이미 메모리 공간이 배정되어 있으므로) 
	// 연결리스트는 다릅니다. 
	
	return 0;
}
