#include <stdio.h>

struct employee
{
	char name[20];
	char pid[20];
	int salary;
};

int main(void)
{
	struct employee emp[3];
	int i;
	
	for(i=0; i<3; i++)
	{
		printf("종업원 이름: ");
		scanf("%s", emp[i].name);
		
		printf("주민등록번호: ");
		scanf("%s", emp[i].pid);
		
		printf("급여 정보: ");
		scanf("%d", &emp[i].salary);
	}
	
	for(i=0; i<3; i++)
	{
		printf("종업원 이름: %s \n", emp[i].name);
		printf("주민등록번호: %s \n", emp[i].pid);
		printf("급여 정보: %d \n", emp[i].salary);
	}
	
	return 0;
}
