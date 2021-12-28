#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq) // ÅÖºó °æ¿ì µ¿ÀÏ À§Ä¡ °¡¸®Å´ 
{
	pq->front = 0;
	pq->rear = 0;
}
int QIsEmpty(Queue * pq) {
	if(pq->front == pq->rear) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int NextPosIdx(int pos)
{
	if(pos == QUE_LEN-1)
		return 0;
	else
		return pos+1;
}

void Enqueue(Queue * pq, Data data)
{
	if(NextPosIdx(pq->rear) == pq->front) { // Å¥°¡ ²Ë Ã¡´Ù¸é 
		printf("Queue Memory Error!");
		exit(-1);
	}
	
	pq->rear = NextPosIdx(pq->rear); // rear¸¦ ÇÑ Ä­ ÀÌµ¿
	pq->queArr[pq->rear] = data; 
}

Data Dequeue(Queue * pq)
{
	if(QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	
	return pq->queArr[NextPosIdx(pq->front)];
}
