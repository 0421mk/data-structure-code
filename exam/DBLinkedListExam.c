#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	// 양방향 연결리스트 초기화 
	plist->head = NULL;
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	// 데이터는 앞쪽부터 삽입됩니다.
	// 새 노드는 head가 됩니다. 
	newNode->next = plist->head;
	
	// head가 존재하지 않는다면(처음 삽입된 값이라면) head의 prev는 새 노드를 가리킵니다. 
	if(plist->head != NULL) {
		plist->head->prev = newNode;	
	}
	
	// 새 노드는 가장 앞에 삽입되므로 prev는 NULL입니다.
	// 새 노드가 삽입되면 head의 위치는 새 노드의 위치와 동일합니다. 
}

int LFirst(List * plist, Data * pdata)
{
	// head가 NULL이라면 연결리스트의 데이터가 없는 것을 뜻합니다. 
	if() {
		return FALSE;
	}
	
	// cur는 head부터 조회합니다.
	// 조회한 데이터는 pdata 메모리 공간에 삽입합니다. 
	
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	// cur 변수의 다음 데이터가 없다면 연결리스트의 데이터가 없는 것을 뜻합니다. 
	if() {
		return FALSE;
	}
	
	// cur의 위치는 다음 한칸 뒤로 당겨집니다. (다음 데이터를 가리킵니다. )
	// 변경된 cur 위치에 데이터를 참조하여 pdata 메모리 공간에 삽입합니다. 
	
	return TRUE;
}

int LPrevious(List * plist, Data * pdata) // LNext 함수의 반대 방향으로 노드 참조
{
	// cur의 이전 위치가 존재하지 않는 경우 더이상 역방향으로 참조할 데이터가 없음을 뜻합니다. 
	if() {
		return FALSE;
	}
	
	// 현재 위치를 한칸 앞으로 당깁니다. (이전 데이터를 가리킵니다.) 
	// 변경된 cur 위치에 데이터를 참조하여 pdata 메모리 공간에 삽입합니다. 
	
	return TRUE;
}

int LCount(List * plist)
{
	return plist->numOfData;
}
