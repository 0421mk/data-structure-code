#include <stdio.h>

void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;
	
	for(j=0; j<n-1; j++) {
		for(i=0; i<n-j-1; i++)
		{
			if(arr[i] > arr[i+1]) {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;	
			}
		}
	}
}

int BubbleSort(void) {
	int arr[5] = {5, 3, 2, 4, 1};
	
	BubbleSort(arr, sizeof(arr)/sizeof(int));
	
	int i;
	
	for(i=0; i<5; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}
