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
	
	// 버블 정렬 구현 예제
	// 1. 배열을 처음 값과 그 다음 값을 비교해서 처음값이 더 크다면 서로 교환합니다. 
	// 2. 위 작업을 배열의 마지막 앞의 값과 마지막 값을 교환할때까지 반복합니다.
	// 3. 1, 2번 작업을 한번 끝낼때마다 가장 큰 수 하나는 무조건 오른쪽에 배치됩니다.
	// 4. 따라서 1, 2번 작업을 배열의 개수 - 1 만큼 반복합니다.
	// 5. 배열의 수만큼 반복하려고 하니 오른쪽에 무조건 배치되는 값들은 조회할 필요가 없습니다. 
	// 6. 따라서 매반복마다 비교 범위를 줄여줍니다. 
}

void SelectionSort(int arr[], int n)
{
	int i, j;
	int temp;
	int minIdx;
		
	for(j=0; j<n-1; j++) {
		
		minIdx = j;
		
		for(i=j+1; i<n; i++) {
			if(arr[minIdx] > arr[i]) {
				minIdx = i;
			}	
		}
		
		temp = arr[j];
		arr[j] = arr[minIdx];
		arr[minIdx] = temp;
	}
	
	// 삽입 정렬 구현 로직 
	// 1. 배열을 처음부터 배열의 끝까지 순회해서 최솟값을 찾습니다.
	// 2. 찾은 최솟값을 첫번째 위치에 배정시킵니다.
	// 3. 첫번째 위치는 완료했으므로 두번째 위치부터 배열의 끝까지 순회해서 최솟값을 찾습니다.
	// 4. 찾은 최솟값을 두번째 위치에 배정시킵니다.
	// 5. 위와 같은 작업을 n-1번 반복하며 정렬을 구현합니다.
	// 6. 반복을 수행할 수록 배열의 앞부분의 인덱스들은 최솟값 순으로 고정되어 있으므로 더이상 조사할 필요가 없습니다.
	// 7. 따라서 비교 범위를 줄여줍니다. 
	
}

int main(void) {
	int arr[5] = {5, 3, 2, 4, 1};
	
	//BubbleSort(arr, sizeof(arr)/sizeof(int));
	SelectionSort(arr, sizeof(arr)/sizeof(int));
	
	int i;
	
	for(i=0; i<5; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}
