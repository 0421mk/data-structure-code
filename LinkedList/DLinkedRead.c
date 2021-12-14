#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next; // 다음 노드의 데이터 주소값을 담을 수 있습니다. 
} Node;

int main(void)
{
	Node * head = NULL; // 노드의 머리 주소 
	Node * tail = NULL; // 노드의 꼬리 주소
	Node * cur = NULL; // 데이터 삽입, 삭제시 필요한 임시 주소 값입니다.
	
	Node * newNode =  NULL; // 사용자로부터 입력받은 데이터 저장 노드입니다.
	int readData; // 사용자로부터 입력받은 데이터 변수
	
	head = (Node*)malloc(sizeof(Node)); // 더미 노드 추가 코드입니다. 
	tail = head;
	
	while(1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;
			
		// 노드 추가 과정
		newNode = (Node*)malloc(sizeof(Node)); // Node 구조체 메모리 할당 
		newNode->data = readData;
		newNode->next = NULL; // 신규 노드이므로 다음 데이터 값은 없습니다.
		
		tail->next = newNode; 
		tail = newNode; 
	}
	
	printf("\n\n");
	
	// 입력 받은 데이터 전체 출력
	if(head == tail)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");	
	} 
	else
	{
		cur = head; // cur 헤드, 첫번째 주소값 지정
		
		while(cur->next != NULL) // 데이터 없을 때까지 반복합니다. 
		{
			cur = cur->next; // 다음 데이터가 있다면 cur 위치 한칸 이동 
			printf("%d ", cur->data); // 이동된 위치에 데이터 출력 
		}
	}
	
	printf("\n\n");
	
	// 메모리 삭제 구현
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
			
			printf("%d를 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
	
	return 0;
}
