#include <stdio.h>

typedef struct point
{
	int xpos;
	int ypos;
} Point;

void add(Point * pos)
{
	pos->xpos += 10;
	pos->ypos += 10;
}

void ShowPosition(Point pos)
{
	printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

int main(void)
{
	Point pos = {1, 5};
	add(&pos);
	ShowPosition(pos);
	
	return 0;
}
