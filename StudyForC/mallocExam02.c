#include <stdio.h>
#include <stdlib.h>

typedef struct _person
{
	char name[20];
	int age;
} Person;

int main(void)
{ 
	int i;
	int number;

	printf("사람의 숫자를 입력해주세요: ");
	scanf("%d", &number);
	
	Person * person = (Person*)malloc(sizeof(Person) * number);
	// 포인터의 배열이 아님(주소 값들을 저장하는 배열이 아님) 
	// 구조체 배열의 첫번째 값을 담은 구조체 포인터일뿐
	// 따라서 바로 값으로 참조 가능 
	
	for(i = 0; i<number; i++)
	{
		printf("%d번째 사람의 이름을 입력해주세요: ", i+1);
		scanf("%s", person[i].name); // 배열의 이름은 주소값
		
		printf("%d번째 사람의 나이를 입력해주세요: ", i+1);
		scanf("%d", &person[i].age);
	}
	
	for(i = 0; i<number; i++)
	{
		printf("%d번째 사람의 이름, 나이: %s, %d세 \n", i+1, person[i].name, person[i].age);
	}
	
	free(person);
	
	return 0;
}
