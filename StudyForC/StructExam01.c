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
	
	printf("������ �̸�: ");
	scanf("%s", emp.name);
	printf("%s", emp.name);
	
	printf("\n");
	
	printf("�ֹε�Ϲ�ȣ: ");
	scanf("%s", emp.pid);
	printf("%s", emp.pid);
	
	printf("\n");
	
	printf("�޿� ����: ");
	scanf("%d", &emp.salary);
	printf("%d", emp.salary);
	
	printf("\n");
	
	return 0;
}
