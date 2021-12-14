#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next; // ���� ����� ������ �ּҰ��� ���� �� �ֽ��ϴ�. 
} Node;

int main(void)
{
	Node * head = NULL; // ����� �Ӹ� �ּ� 
	Node * tail = NULL; // ����� ���� �ּ�
	Node * cur = NULL; // ������ ����, ������ �ʿ��� �ӽ� �ּ� ���Դϴ�.
	
	Node * newNode =  NULL; // ����ڷκ��� �Է¹��� ������ ���� ����Դϴ�.
	int readData; // ����ڷκ��� �Է¹��� ������ ����
	
	head = (Node*)malloc(sizeof(Node)); // ���� ��� �߰� �ڵ��Դϴ�. 
	tail = head;
	
	while(1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;
			
		// ��� �߰� ����
		newNode = (Node*)malloc(sizeof(Node)); // Node ����ü �޸� �Ҵ� 
		newNode->data = readData;
		newNode->next = NULL; // �ű� ����̹Ƿ� ���� ������ ���� �����ϴ�.
		
		tail->next = newNode; 
		tail = newNode; 
	}
	
	printf("\n\n");
	
	// �Է� ���� ������ ��ü ���
	if(head == tail)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");	
	} 
	else
	{
		cur = head; // cur ���, ù��° �ּҰ� ����
		
		while(cur->next != NULL) // ������ ���� ������ �ݺ��մϴ�. 
		{
			cur = cur->next; // ���� �����Ͱ� �ִٸ� cur ��ġ ��ĭ �̵� 
			printf("%d ", cur->data); // �̵��� ��ġ�� ������ ��� 
		}
	}
	
	printf("\n\n");
	
	// �޸� ���� ����
	if(head == tail)
	{
		return 0;
	} 
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next;
		
		while(delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			
			printf("%d�� �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}
	
	return 0;
}
