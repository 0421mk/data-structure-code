#include <stdio.h>
#include "ALGraph.h"

int main(void) {
	ALGraph graph; // 이 선언만으로 메모리 공간이 할당됩니다.
	GraphInit(&graph, 5); // A ~ E

	AddEdge(&graph, A, B); // 문자는 숫자로 해석됩니다. A->B
	AddEdge(&graph, A, D); // A->D
	AddEdge(&graph, B, C); // B->C ..
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);

	ShowGraphEdgeInfo(&graph); // 그래프의 모든 간선 정보를 출력합니다.
	GraphDestroy(&graph); // 그래프의 리소스 소멸 

	return 0;
}
