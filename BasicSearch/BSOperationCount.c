#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1; // 인덱스는 0부터 시작하므로 마지막 인덱스는 배열의 크기 -1 입니다.
	int mid;
	int opCnt = 0; // 비교 연산의 횟수를 기록합니다. 
	
	while(first <= last)
	{
		mid = (first + last) / 2;
		
		if(target == ar[mid])
		{
			return mid;
		}
		else { // 만약 찾지 못했다면 업앤 다운으로 접근합니다. 
			if(target < ar[mid]) // 다운이라면 
			{
				last = mid - 1; // -1 한 이유 : 앞서 ar[mid]에서 target 변수를 찾지 못했으므로 굳이 또 ar[mid]를 범위에 포함시킬 필요가 없습니다. 
			} else { // 업이라면 
				first = mid + 1; // +1 한 이유 : -1 한 이유와 동일합니다. 
			}
		}
		
		opCnt++; // 연산 1회당 비교 연산 값 1 추가 
	}
	
	printf("비교연산횟수: %d \n", opCnt);
	
	return -1; // 데이터 탐색 실패 
}

int main(void)
{
	int arr1[500] = {0,}; // 배열의 모든 요소가 0으로 초기화됩니다. 순차 탐색의 경우 -1을 찾을 때 500번 찾습니다. 
	int arr2[5000] = {0,}; // 배열의 모든 요소가 0으로 초기화됩니다. 순차 탐색의 경우 -1을 찾을 때 5000번 찾습니다. 
	int arr3[50000] = {0,}; // 배열의 모든 요소가 0으로 초기화됩니다. 순차 탐색의 경우 -1을 찾을 때 50000번 찾습니다. 
	int idx;
	
	idx = BSearch(arr3, sizeof(arr3)/sizeof(int), -1); // 없는 값을 찾는 이유는 최악의 경우를 확인할 수 있어서입니다.
	
	if(idx == -1)
	{
		printf("탐색 실패 \n");
	} else {
		printf("타겟 저장 인덱스: %d \n", idx);
	}
	
	return 0;
} 
