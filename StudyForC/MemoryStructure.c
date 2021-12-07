// 아래 코드 전체가 코드 영역 
#include <stdio.h>

int sum = 25; // 데이터 영역 

void add(int num) // 스택 영역 
{
	num += 10;
	printf("add 함수: %d \n", num);
	sum += num;
}

int main(void) // 스택 영역 
{
	int num = 10;
	add(num);
	printf("main 함수: %d \n", num);
	printf("전역 변수 sum: %d \n", sum); // 어떤 함수 안에서든 접근 가능 

	return 0;
}
