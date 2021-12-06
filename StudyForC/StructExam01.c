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
	
	printf("주민등록번호: ");
	scanf("%s", emp.pid);

	printf("급여 정보: ");
	scanf("%d", &emp.salary);
	
	printf("\n");
	
	printf("종업원 이름: %s \n", emp.name);
	printf("주민등록번호: %s \n", emp.pid);
	printf("급여 정보: %d \n", emp.salary);
	
	printf("\n");
	
	return 0;
}
