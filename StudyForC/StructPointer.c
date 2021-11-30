#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point pos1 = {1, 2}; // point 구조체 pos1 초기화
	struct point pos2 = {100, 200}; // point 구조체 pos1 초기화
	struct point * pptr = &pos1; // point 구조체의 포인터 pptr 
	
	(*pptr).xpos += 4; // (*pptr) 접근 방법 
	(*pptr).ypos += 5;
	printf("[%d, %d] \n", (*pptr).xpos, (*pptr).ypos);
	
	pptr = &pos2;
	pptr->xpos += 1;
	pptr->ypos += 2;
	printf("[%d, %d] \n", pptr->xpos, pptr->ypos);
	
	return 0;
}

// typedef 버전

//typedef struct _point
//{
//	int xpos;
//	int ypos;
//} Point;
 
