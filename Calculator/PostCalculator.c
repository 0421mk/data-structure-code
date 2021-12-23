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
			SPush(&stack, tok-'0'); // ������ ���ڷ� ��ȯ (�ƽ�Ű�ڵ� ����) 
		} else { // ����(������)�� �ǿ����� ���������� 2�� ������ ��� 
			op2 = SPop(&stack); // �տ� �ִ°� �ι�° �ǿ����� 
			op1 = SPop(&stack); // ù��° �ǿ�����
			
			switch(tok)
			{
				case '+':
					SPush(&stack, op1+op2); // ��� �� �ٽ� ���ÿ� ���� 
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
	
	// ���� ��� ���ÿ� ���� 
	return  SPop(&stack);
}
