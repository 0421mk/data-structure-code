#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1; // 인덱스는 0부터 시작하므로 마지막 인덱스는 배열의 크기 -1 입니다.
	int mid;
	
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
	}
	
	// 코드 자체로 이해하려고 하면 머리가 아프니 그림을 보면서 구현한 것에 집중하세요.
	
	return -1; // 데이터 탐색 실패 
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	int idx;
	
	idx = BSearch(arr, sizeof(arr)/sizeof(int), 4);
	
	if(idx == -1)
	{
		printf("탐색 실패 \n");
	} else {
		printf("타겟 저장 인덱스: %d \n", idx);
	}
	
	return 0;
} 
