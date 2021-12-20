#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

// 양방향 연결리스트는 마지막 노드가 첫번째 노드를 가리켜 모든 노드들이 연결되어 있는 형태를 말합니다.
// 주석 아래 부분에 코드를 입력해주시면 됩니다. 
void ListInit(List * plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data) // 꼬리에 노드를 추가
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		// 데이터를 처음 삽입하면 꼬리가 새로운 노드가 됩니다. 
		// 새로운 노드는 자기 자신을 가리킵니다. 

	} else {
		// 첫번째 데이터는 tail을 활용하여 표현합니다.
		// 새로운 노드는 첫번째 데이터를 가리킵니다.
		// 첫번째 데이터는 새로운 노드가 됩니다.
		// 꼬리는 다시 새로운 노드가 됩니다. 

	}
	
	// 리스트의 데이터 개수가 증가합니다. 
}
void LInsertFront(List * plist, Data data) // 머리에 노드를 추가
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		// 데이터를 처음 삽입하면 꼬리가 새로운 노드가 됩니다. 
		// 새로운 노드는 자기 자신을 가리킵니다. 
		
	}
	else {
		// 첫번째 데이터는 tail을 활용하여 표현합니다.
		// 새로운 노드는 첫번째 데이터를 가리킵니다. 
		// 첫번째 데이터는 새로운 노드가 됩니다. 
		
	}
	
	// 리스트의 데이터 개수가 증가합니다. 
}

int LFirst(List * plist, Data * pdata)
{
	// 꼬리가 존재하지 않는다면 FALSE를 리턴합니다. 
	if() {
		return FALSE;
	}
	
	// before는 꼬리가 됩니다.
	// cur는 첫번째 데이터가 됩니다.
	// 첫번째 데이터는 tail을 활용하여 표현합니다. 
	// before를 꼬리로 만드는 이유는 첫번째 데이터를 cur로 사용하기 위해서입니다. 
	
	
	// 데이터를 pdata 포인터 변수에 삽입합니다.
	
	return TRUE; 
}
int LNext(List * plist, Data * pdata)
{
	// 꼬리가 존재하지 않는다면 FALSE를 리턴합니다. 
	if(plist->tail == NULL) {
		return FALSE;
	}
	
	// LNext를 불러왔다는 것은 LFirst 함수를 사용했고 다음 데이터가 존재하는 상황입니다. 
	// before는 이전 cur의 주소가 됩니다.
	// cur는 다음 데이터가 됩니다. 

	
	// 데이터를 pdata 포인터 변수에 삽입합니다.
	
	return TRUE;
}
Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;
	
	// rpos가 마지막 데이터일 경우 두가지 경우의 수를 예외처리 해야 합니다.
	// (TMI)더미 노드를 만들 경우 해당 예외처리는 안해도 됩니다.
	// 예외 1: 삭제할 데이터가 마지막 위치인 동시에 마지막 남은 데이터라면 NULL을 삽입합니다.
	// 예외 2: 삭제할 데이터가 마지막 위치라면 tail의 주소를 before의 주소로 바꿔줍니다. 
	if(rpos == plist->tail) {
		if(plist->tail == plist->tail->next) {
			
		} else {
			
		}
	}
	
	// 해당 예외 처리만 한다면 모든 경우의 수에 데이터 삭제는 동일하게 적용됩니다.
	// 삭제 처리를 위해 이전 노드가 삭제할 현재 노드의 다음 노드를 가리킵니다.
	// 현재 노드가 삭제되었으므로 현재 노드의 위치를 이전 노드로 변경해줍니다. 
	
	
	// 삭제할 노드의 메모리를 해제합니다.
	// 리스트의 데이터 수를 감소합니다.
	// 삭제할 데이터를 반환합니다. 
	
	 
	// (TMI) 삭제는 연속으로 사용할 수 없습니다. before의 위치 조정이 필요하기 때문입니다.
	// 따라서 LFirst 또는 LNext 호출 후 주소를 세팅한 후 사용해야 합니다. 
}
int LCount(List * plist)
{
	return plist->numOfData;
}
