#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int * ptr = (int*)malloc(sizeof(int)*10);
	// malloc 으로 할당된 메모리는 배열로 접근 가능합니다. 
	// ptr[i] => *(ptr+i) 로도 접근 가능합니다.
	// ptr[i]는 값이므로 scanf할 때 주소값인 &ptr[i]를 선언해야 합니다. 
	
	for(i=0; i<10; i++)
	{
		scanf("%d", &ptr[i]);
	}
	
	for(i=0; i<10; i++)
	{
		printf("%d ", *(ptr+i));
	}
	
	free(ptr);
	
	return 0;
}
