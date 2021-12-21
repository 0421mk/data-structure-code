#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	// 양방향 연결리스트는 양방향으로 연결되므로 next와 prev 포인터 변수를 사용합니다. 
	Data data;
	struct _node * next;
	struct _node * prev;
} Node;

typedef struct _DBLinkedList
{
	Node * head;
	Node * cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata); // LNext 함수의 반대 방향으로 노드 참조
int LCount(List * plist);

#endif
