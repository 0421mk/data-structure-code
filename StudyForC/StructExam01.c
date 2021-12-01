#include <stdio.h>

struct employee
{
	char name[20];
	char pid[20];
	int salary;
};

int main(void)
{
	struct employee emp;
	
	printf("종업원 이름: ");
	scanf("%s", emp.name);
	printf("%s", emp.name);
	
	printf("\n");
	
	printf("주민등록번호: ");
	scanf("%s", emp.pid);
	printf("%s", emp.pid);
	
	printf("\n");
	
	printf("급여 정보: ");
	scanf("%d", &emp.salary);
	printf("%d", emp.salary);
	
	printf("\n");
	
	return 0;
}
