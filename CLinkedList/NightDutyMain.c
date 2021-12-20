#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee * WhosNightDuty(List * plist, char * name, int day);
void ShowEmployeeInfo(Employee * emp);

int main(void)
{
	int i;
	Employee * pemp;
	
	// ���� ���Ḯ��Ʈ ���� �� �ʱ�ȭ 
	List list;
	ListInit(&list);
	
	// 4���� ������ ����
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1;
	strcpy(pemp->name, "Terry");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2;
	strcpy(pemp->name, "Jery");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3;
	strcpy(pemp->name, "Hary");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4;
	strcpy(pemp->name, "Sunny");
	LInsert(&list, pemp);
	
	// Terry �� 15�� �� �����ڴ�?
	pemp = WhosNightDuty(&list, "Terry", 15);
	ShowEmployeeInfo(pemp);
	
	return 0;
}

Employee * WhosNightDuty(List * plist, char * name, int day) {
	Employee * ret;
	int size = LCount(plist);
	int i;
	
	// �̸� ã��
	LFirst(plist, &ret);
	
	// ù��° �̸��� ���� strcmp �� ����� 0�� ���� ������ �ɸ� ���� �� �ȳ��ɴϴ�. 
	if(strcmp(ret->name, name) != 0) {
		for(i=0; i<size-1; i++) {
			LNext(plist, &ret);
				
			if(strcmp(ret->name, name) == 0) {
				break;
			}
		}
	}	
	
	// ��ĥ �� 
	for(i=0; i<day; i++) {
		LNext(plist, &ret);
	}
	
	return ret;	
}

void ShowEmployeeInfo(Employee * emp) {
	printf("Employee name: %s \n", emp->name);
	printf("Employee number: %d \n", emp->empNum);
}
