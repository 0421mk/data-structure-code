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
	
	// 원형 연결리스트 생성 및 초기화 
	List list;
	ListInit(&list);
	
	// 4명의 데이터 저장
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
	
	// Terry 의 15일 뒤 당직자는?
	pemp = WhosNightDuty(&list, "Terry", 15);
	ShowEmployeeInfo(pemp);
	
	return 0;
}

Employee * WhosNightDuty(List * plist, char * name, int day) {
	Employee * ret;
	int size = LCount(plist);
	int i;
	
	// 이름 찾기
	LFirst(plist, &ret);
	
	// 첫번째 이름의 값을 strcmp 한 결과가 0의 경우로 조건을 걸면 각이 잘 안나옵니다. 
	if(strcmp(ret->name, name) != 0) {
		for(i=0; i<size-1; i++) {
			LNext(plist, &ret);
				
			if(strcmp(ret->name, name) == 0) {
				break;
			}
		}
	}	
	
	// 며칠 뒤 
	for(i=0; i<day; i++) {
		LNext(plist, &ret);
	}
	
	return ret;	
}

void ShowEmployeeInfo(Employee * emp) {
	printf("Employee name: %s \n", emp->name);
	printf("Employee number: %d \n", emp->empNum);
}
