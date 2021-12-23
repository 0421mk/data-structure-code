#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int Calculate(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;
	
	StackInit(&stack);
	
	for(i=0; i<expLen; i++) {
		tok = exp[i];
		
		if(isdigit(tok))
		{
			SPush(&stack, tok-'0'); // 정수면 숫자로 변환 (아스키코드 뺄셈) 
		} else { // 문자(연산자)면 피연산자 위에서부터 2개 꺼내서 계산 
			op2 = SPop(&stack); // 앞에 있는게 두번째 피연산자 
			op1 = SPop(&stack); // 첫번째 피연산자
			
			switch(tok)
			{
				case '+':
					SPush(&stack, op1+op2); // 계산 후 다시 스택에 삽입 
					break;
				case '-':
					SPush(&stack, op1-op2);
					break;	
				case '*':
					SPush(&stack, op1*op2);
					break;	
				case '/':
					SPush(&stack, op1/op2);
					break;
			} 
		}
	}
	
	// 최종 결과 스택에 저장 
	return  SPop(&stack);
}
