#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "DLinkedList.h" // 링크드 리스트를 기반으로 그래프를 만듭니다. 

// 정점의 이름을 상수화
enum {A, B, C, D, E, F, G, H, I, J};

// 상수 A = 'B';

typedef struct _alg
{
	int numV; // 정점의 수 
	int numE; // 간선의 수
	List * adjList; // 간선의 정보, 정점마다 가지고 있는 간선의 데이터들 
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

// 간선의 정보 출력
void  ShowGraphEdgeInfo(ALGraph * pg);

#endif
