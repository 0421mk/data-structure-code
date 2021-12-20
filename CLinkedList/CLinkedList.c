#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

// ���� ���Ḯ��Ʈ�� ������ ��尡 ù��° ��带 ������ ��� ������ �������� ����Ǿ� �ִ� ���¸� ���մϴ�. 
void ListInit(List * plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data) // ������ ��带 �߰�
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		// �����͸� ó�� �����ϸ� ������ ���ο� ��尡 �˴ϴ�. 
		// ���ο� ���� �ڱ� �ڽ��� ����ŵ�ϴ�. 
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		// ù��° �����ʹ� tail�� Ȱ���Ͽ� ǥ���մϴ�.
		// ���ο� ���� ù��° �����͸� ����ŵ�ϴ�.
		// ù��° �����ʹ� ���ο� ��尡 �˴ϴ�.
		// ������ �ٽ� ���ο� ��尡 �˴ϴ�. 
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	
	(plist->numOfData)++; // ����Ʈ�� ������ ������ �����մϴ�. 
}
void LInsertFront(List * plist, Data data) // �Ӹ��� ��带 �߰�
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		// �����͸� ó�� �����ϸ� ������ ���ο� ��尡 �˴ϴ�. 
		// ���ο� ���� �ڱ� �ڽ��� ����ŵ�ϴ�. 
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		// ù��° �����ʹ� tail�� Ȱ���Ͽ� ǥ���մϴ�.
		// ���ο� ���� ù��° �����͸� ����ŵ�ϴ�. 
		// ù��° �����ʹ� ���ο� ��尡 �˴ϴ�. 
		newNode->next = plist->tail->next; 
		plist->tail->next = newNode;
	}
	
	(plist->numOfData)++; // ����Ʈ�� ������ ������ �����մϴ�. 
}

int LFirst(List * plist, Data * pdata)
{
	// ������ �������� �ʴ´ٸ� FALSE�� �����մϴ�. 
	if(plist->tail == NULL) {
		return FALSE;
	}
	
	// before�� ������ �˴ϴ�.
	// cur�� ù��° �����Ͱ� �˴ϴ�.
	// ù��° �����ʹ� tail�� Ȱ���Ͽ� ǥ���մϴ�. 
	// before�� ������ ����� ������ ù��° �����͸� cur�� ����ϱ� ���ؼ��Դϴ�. 
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	
	// �����͸� pdata ������ ������ �����մϴ�.
	*pdata = plist->cur->data;
	
	return TRUE; 
}
int LNext(List * plist, Data * pdata)
{
	// ������ �������� �ʴ´ٸ� FALSE�� �����մϴ�. 
	if(plist->tail == NULL) {
		return FALSE;
	}
	
	// LNext�� �ҷ��Դٴ� ���� LFirst �Լ��� ����߰� ���� �����Ͱ� �����ϴ� ��Ȳ�Դϴ�. 
	// before�� ���� cur�� �ּҰ� �˴ϴ�.
	// cur�� ���� �����Ͱ� �˴ϴ�. 
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	// �����͸� pdata ������ ������ �����մϴ�.
	*pdata = plist->cur->data;
	
	return TRUE;
}
Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;
	
	// rpos�� ������ �������� ��� �ΰ��� ����� ���� ����ó�� �ؾ� �մϴ�.
	// (TMI)���� ��带 ���� ��� �ش� ����ó���� ���ص� �˴ϴ�.
	// ���� 1: ������ �����Ͱ� ������ ��ġ�� ���ÿ� ������ ���� �����Ͷ�� NULL�� �����մϴ�.
	// ���� 2: ������ �����Ͱ� ������ ��ġ��� tail�� �ּҸ� before�� �ּҷ� �ٲ��ݴϴ�. 
	if(rpos == plist->tail) {
		if(plist->tail == plist->tail->next) {
			plist->tail = NULL;
		} else {
			plist->tail = plist->before;
		}
	}
	
	// �ش� ���� ó���� �Ѵٸ� ��� ����� ���� ������ ������ �����ϰ� ����˴ϴ�.
	// ���� ó���� ���� ���� ��尡 ������ ���� ����� ���� ��带 ����ŵ�ϴ�.
	// ���� ��尡 �����Ǿ����Ƿ� ���� ����� ��ġ�� ���� ���� �������ݴϴ�. 
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	// ������ ����� �޸𸮸� �����մϴ�.
	// ����Ʈ�� ������ ���� �����մϴ�.
	// ������ �����͸� ��ȯ�մϴ�. 
	free(rpos);
	(plist->numOfData)--;
	return rdata;
	 
	// (TMI) ������ �������� ����� �� �����ϴ�. before�� ��ġ ������ �ʿ��ϱ� �����Դϴ�.
	// ���� LFirst �Ǵ� LNext ȣ�� �� �ּҸ� ������ �� ����ؾ� �մϴ�. 
}
int LCount(List * plist)
{
	return plist->numOfData;
}
