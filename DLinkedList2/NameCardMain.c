#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "NameCard.h"

int NameCardMain(void)
{
	List list;
	LData nameCard;
	ListInit(&list);
	
	nameCard = MakeNameCard("최사장", "010-1111-1111");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("김사장", "010-2222-2222");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("박사장", "010-3333-3333");
	LInsert(&list, nameCard);
	
	printf("모든 정보 출력");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		ShowNameCardInfo(nameCard);
		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		}
	}
	
	printf("\n");
	printf("박사장의 정보 출력");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		if(!NameCompare(nameCard, "박사장")) {
			ShowNameCardInfo(nameCard);
		}
		
		while(LNext(&list, &nameCard)) {
			if(!NameCompare(nameCard, "박사장")) {
				ShowNameCardInfo(nameCard);
			}
		}
	}
	
	printf("\n");
	printf("박사장의 정보 변경");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		if(!NameCompare(nameCard, "박사장")) {
			ChangePhoneNum(nameCard, "010-9999-9999");
		}
		
		while(LNext(&list, &nameCard)) {
			if(!NameCompare(nameCard, "박사장")) {
				ChangePhoneNum(nameCard, "010-9999-9999");
			}
		}
	}
	
	printf("\n");
	printf("모든 정보 출력");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		ShowNameCardInfo(nameCard);
		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		}
	}
	
	printf("\n");
	printf("박사장의 정보 삭제");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		if(!NameCompare(nameCard, "박사장")) {
			LRemove(&list);
			free(nameCard);
		}
		
		while(LNext(&list, &nameCard)) {
			if(!NameCompare(nameCard, "박사장")) {
				LRemove(&list);
				free(nameCard);
			}
		}
	}
	
	printf("\n");
	printf("모든 정보 출력");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		ShowNameCardInfo(nameCard);
		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		}
	}
	
	printf("\n");
	
	printf("현재 데이터의 수: %d\n", LCount(&list));
	
	return 0;
}
