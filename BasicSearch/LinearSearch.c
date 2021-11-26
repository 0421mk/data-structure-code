#include <stdio.h>

int LSearch(int ar[], int len, int target) // 순차 탐색 알고리즘 
{
	int i;
	
	for(i = 0; i < len; i++)
	{
		if(ar[i] == target) // 동등 비교 연산이 실행된 횟수를 통해 우리는 시간 복잡도(수행 시간의 분석 결과)를 알 수 있습니다. 
			return i; // 찾는 데이터와 일치하는 인덱스를 반환하도록 합니다.	
	}
	
	return -1; // 배열에서 찾지 못한 값을 뜻합니다. 
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5}; // 사이즈가 20 바이트 
	int idx;
	
	// 4라는 데이터 값을 찾아봅시다.
	idx = LSearch(arr, sizeof(arr)/sizeof(int), 7);
	
	if(idx == -1) {
		printf("탐색 실패 \n");
	}
	else
	{
		printf("타겟 저장 인덱스: %d \n", idx);
	}
	
	return 0;
}
