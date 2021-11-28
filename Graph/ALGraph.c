#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h" // 링크드 리스트를 기반으로 그래프를 만듭니다. 

int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv) {
	int i;
	
	pg->adjList = (List*)malloc(sizeof(List)*nv); // 리스트가 정점의 수만큼 존재합니다.
	pg->numV = nv;
	pg->numE = 0; // 처음 간선의 수는 0개
	
	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i])); // 정점 별로 리스트 초기화를 해줍니다.
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); 
	} 
}

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg) {
	if(pg->adjList != NULL)
		free(pg->adjList);
}

// 간선의 추가
// 무방향 배열 
void AddEdge(ALGraph * pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1; // 간선의 수 
}

// 간선의 정보 출력
void  ShowGraphEdgeInfo(ALGraph * pg) {
	int i;
	int vx; // 임시적으로 데이터를 출력하기 위해 필요한 메모리 공간
	
	for(i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);
		
		if(LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65); // A, B, C .. 상수화 
			
			while(LNext(&(pg->adjList[i]), &vx))
			{
				printf("%c ", vx + 65);
			}
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if(data1 < data2)
		return 0;
	else
		return 1;
}
