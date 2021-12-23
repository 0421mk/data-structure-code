#include <string.h>
#include <stdlib.h>
#include <ctype.h> // 값 체크 라이브러리
#include "ListBaseStack.h"

int GetOpPrec(char op)
{
	switch(op)
	{
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
	}
	
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);
	
	if(op1Prec > op2Prec) {
		return 1; // 규칙 1번 Pop 처리 
	} else if(op1Prec < op2Prec) {
		return -1; // 규칙 2번 Push 처리 
	} else {
		return 0; // 같으면 규칙 1번(Pop 처리) 
	}
}

void ConvToPostfix(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1); // 문자열 마지막 바이트는 null
	
	int i, idx = 0;
	char tok, popOp;
	
	memset(convExp, 0, sizeof(char)*expLen + 1); // 0으로 초기화 
	StackInit(&stack);
	
	for(i=0; i<expLen; i++)
	{
		tok = exp[i]; // 수식 문자 하나씩 체크
		
		if(isdigit(tok))
		{
			convExp[idx++] = tok;
		} else {
			switch(tok)
			{
				case '(' : // 가장 낮은 우선순위 
					SPush(&stack, tok);
					break;
				case ')' : 
					while(1)
					{
						popOp = SPop(&stack);
						if(popOp == '(') { // 연산자 (을 만나면 종료, (와 )는 convExp에 들어가지 못함 
							break;
						}
						convExp[idx++] = popOp;
					}
					break;
				case '+' :
				case '-' :
				case '*' :
				case '/' :
					while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) {
						convExp[idx++] = SPop(&stack);
					} // 우선순위가 높으면 스택에서 Pop하고 추가, 아니면 그냥 추가 
					SPush(&stack, tok);
					break;
			}
		}
	}
	
	// 위 연산후 스택에 연산자가 남아있으면 배열에 삽입 
	while(!SIsEmpty(&stack)) {
		convExp[idx++] = SPop(&stack);
	}
	
	strcpy(exp, convExp); // exp에 복사(call by reference) 
	free(convExp); // 이제 convExp는 필요없음 
}
 
