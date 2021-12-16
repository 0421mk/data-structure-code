#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "NameCard.h"

int NameCardProgram(void)
{
	List list;
	LData nameCard;
	ListInit(&list);
	int item;
	
	while(1) {
		printf("\n");
		printf("***** MENU *****\n");
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Modify\n");
		printf("4. Delete\n");
		printf("5. Print All\n");
		printf("6. Count\n");
		printf("7. Exit\n");
		
		printf("Choose the item: ");
		scanf("%d", &item);
		
		if(item == 1){ 
			NameCard newName; 
			
			printf("[ INSERT ]\n");
			printf("Input Name: ");
			scanf("%s", &newName.name);
			printf("Input Tel Number: ");
			scanf("%s", &newName.phone);
			
			nameCard = MakeNameCard(newName.name, newName.phone);
			LInsert(&list, nameCard);
			
			printf("Data Inserted\n");
		} else if(item == 2) {
			NameCard newName; 
			
			printf("[ SEARCH ]\n");
			printf("Search Name: ");
			scanf("%s", &newName.name);
			
			int isNull = -1;
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, newName.name)) {
					ShowNameCardInfo(nameCard);
					isNull = 0;
				}
				
				while(LNext(&list, &nameCard)) {
					if(!NameCompare(nameCard, newName.name)) {
						ShowNameCardInfo(nameCard);
						isNull = 0;
					}
				}
			}
			
			if(isNull == -1) {
				printf("존재하지 않는 이름입니다.\n");
			} else {
				printf("Data Searched\n");
			}
		} else if(item == 3) {
			NameCard newName; 
			
			printf("[ MODIFY ]\n");
			printf("Search Name: ");
			scanf("%s", &newName.name);
			
			int isNull = -1;
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, newName.name)) {
					printf("Input Tel Number: ");
					scanf("%s", &newName.phone);
					
					ChangePhoneNum(nameCard, newName.phone);
					isNull = 0;
				}
				
				while(LNext(&list, &nameCard)) {
					if(!NameCompare(nameCard, newName.name)) {
						printf("Input Tel Number: ");
						scanf("%s", &newName.phone);
						
						ChangePhoneNum(nameCard, newName.phone);
						isNull = 0;
					}
				}
			}
			
			if(isNull == -1) {
				printf("존재하지 않는 이름입니다.\n");
			} else {
				printf("Data Modified\n");
			}
		} else if(item == 4) {
			NameCard newName; 
			
			printf("[ DELETE ]\n");
			printf("Delete Name: ");
			scanf("%s", &newName.name);
			
			int isNull = -1;
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, newName.name)) {
					LRemove(&list);
					free(nameCard);
					
					isNull = 0;
				}
				
				while(LNext(&list, &nameCard)) {
					if(!NameCompare(nameCard, newName.name)) {
						LRemove(&list);
						free(nameCard);
						
						isNull = 0;
					}
				}
			}
			
			if(isNull == -1) {
				printf("존재하지 않는 이름입니다.\n");
			} else {
				printf("Data Deleted\n");
			}
		} else if(item == 5) {
			printf("[ PRINT ALL ]\n");
			
			if(LCount(&list) == 0) {
				printf("데이터가 존재하지 않습니다.\n");
				continue;
			}
			
			if(LFirst(&list, &nameCard)) {
				ShowNameCardInfo(nameCard);
				
				while(LNext(&list, &nameCard)) {
					ShowNameCardInfo(nameCard);
				}
			}
		} else if(item == 6) {
			printf("[ Count ]\n");
			printf("현재 데이터의 수: %d\n", LCount(&list));
		} else if(item == 7) {
			printf("[ EXIT ]\n");
			printf("프로그램을 종료합니다.\n");
			
			break;
		}
	}

	return 0;
}
