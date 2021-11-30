#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
	struct point * ptr; // 구조체 변수의 멤버로 자신의 구조체 포인터 변수를 둘 수 있습니다. 
};

int main(void)
{
	struct point pos1 = {1, 1};
	struct point pos2 = {2, 2};
	struct point pos3 = {3, 3};
	
	pos1.ptr = &pos2;
	pos2.ptr = &pos3;
	pos3.ptr = &pos1;
	
	printf("점의 연결 관계 \n");
	printf("[%d, %d] => [%d, %d] \n", pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos); // *(pos1.ptr).xpos 사용 불가
	printf("[%d, %d] => [%d, %d] \n", pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos); // 연결된 모습을 확인 가능합니다. 
	printf("[%d, %d] => [%d, %d] \n", pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
	
	return 0;
}
