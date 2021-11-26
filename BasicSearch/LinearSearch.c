#include <stdio.h>

int LSearch(int ar[], int len, int target) // ���� Ž�� �˰��� 
{
	int i;
	
	for(i = 0; i < len; i++)
	{
		if(ar[i] == target) // ���� �� ������ ����� Ƚ���� ���� �츮�� �ð� ���⵵(���� �ð��� �м� ���)�� �� �� �ֽ��ϴ�. 
			return i; // ã�� �����Ϳ� ��ġ�ϴ� �ε����� ��ȯ�ϵ��� �մϴ�.	
	}
	
	return -1; // �迭���� ã�� ���� ���� ���մϴ�. 
}

int main(void)
{
	int arr[] = {3, 5, 2, 4, 9}; // ����� 20 ����Ʈ 
	int idx;
	
	// 4��� ������ ���� ã�ƺ��ô�.
	idx = LSearch(arr, sizeof(arr)/sizeof(int), 7);
	
	if(idx == -1) {
		printf("Ž�� ���� \n");
	}
	else
	{
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	}
	
	return 0;
}
