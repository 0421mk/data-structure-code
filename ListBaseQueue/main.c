#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main2(void) {
	Queue q;
	QueueInit(&q);
	
	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);
	
	while(!QIsEmpty(&q)) {
		printf("%d ", Dequeue(&q));
	}
	
	return 0;
}
