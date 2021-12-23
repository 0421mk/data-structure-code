#include <string.h>
#include <stdlib.h>
#include <ctype.h> // �� üũ ���̺귯��
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
		return 1; // ��Ģ 1�� Pop ó�� 
	} else if(op1Prec < op2Prec) {
		return -1; // ��Ģ 2�� Push ó�� 
	} else {
		return 0; // ������ ��Ģ 1��(Pop ó��) 
	}
}

void ConvToPostfix(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1); // ���ڿ� ������ ����Ʈ�� null
	
	int i, idx = 0;
	char tok, popOp;
	
	memset(convExp, 0, sizeof(char)*expLen + 1); // 0���� �ʱ�ȭ 
	StackInit(&stack);
	
	for(i=0; i<expLen; i++)
	{
		tok = exp[i]; // ���� ���� �ϳ��� üũ
		
		if(isdigit(tok))
		{
			convExp[idx++] = tok;
		} else {
			switch(tok)
			{
				case '(' : // ���� ���� �켱���� 
					SPush(&stack, tok);
					break;
				case ')' : 
					while(1)
					{
						popOp = SPop(&stack);
						if(popOp == '(') { // ������ (�� ������ ����, (�� )�� convExp�� ���� ���� 
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
					} // �켱������ ������ ���ÿ��� Pop�ϰ� �߰�, �ƴϸ� �׳� �߰� 
					SPush(&stack, tok);
					break;
			}
		}
	}
	
	// �� ������ ���ÿ� �����ڰ� ���������� �迭�� ���� 
	while(!SIsEmpty(&stack)) {
		convExp[idx++] = SPop(&stack);
	}
	
	strcpy(exp, convExp); // exp�� ����(call by reference) 
	free(convExp); // ���� convExp�� �ʿ���� 
}
 
