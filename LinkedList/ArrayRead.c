#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ArrayRead(void) {
	int arr[10];
	int readCount = 0;
	int readData;
	int i;
	
	while(1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;
		
		arr[readCount++] = readData;
	}
	
	for(i = 0; i < readCount; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
