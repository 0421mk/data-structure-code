/*
구조체로 선언된 Person 회원을 입력받습니다.
프로그램 시작 후 입력은 계속 받을 수 있으나 0을 입력받으면 입력 받기를 중단하고 입력받은 모든 데이터를 출력합니다.
출력한 후 모든 데이터의 메모리를 반납합니다. 

[ 프로그램 예시 ]
회원을 추가하시겠습니까?: 1 [엔터] 
1번째 회원의 이름을 입력해주세요. : aa [엔터]
1번째 회원의 나이를 입력해주세요. : 11 [엔터]
회원을 추가하시겠습니까?: 1 [엔터]  
2번째 회원의 이름을 입력해주세요. : bb [엔터]
2번째 회원의 나이를 입력해주세요. : 22 [엔터] 
회원을 추가하시겠습니까?: 0 [엔터] 

== 전체 회원 리스트 ==
1번째 회원 : aa, 11살
2번째 회원 : bb, 22살

== 메모리 반납 ==
1번째 사람의 메모리를 반납합니다.
2번째 사람의 메모리를 반납합니다.
존재하는 메모리가 없습니다. 

[ 힌트 ]
구조체를 3개 정의해야 합니다.
Person * current = NULL;
Person * first = NULL;
Person * last = NULL;

처음 사람은 두번째 사람의 위치를 알아야 합니다.
두번째 사람은 세번째사람의 위치를 알아야 합니다.
마지막 사람의 next 변수에는 NULL이 들어가야 합니다.
처음사람의 위치가 주어진 상황에서 반복문을 통해, 마지막 사람까지 접근하여주세요.
first 변수에는 처음사람의 위치가 들어가야 합니다.
current 변수에는 지금 막 태어난(malloc으로 만들어진) 사람의 위치가 들어가거나, 반복문에서 각각의 사람에게 접근할 때 사용됩니다.
last 변수에는 가장 마지막에 추가된(만들어진, malloc으로 생성된) 사람의 주소가 들어가야 합니다.
last변수에는 회원이 추가될 때 마다(즉 새로운 사람이 추가될 때 마다) 값이 바뀌어야 합니다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _person
{
	char name[20];
	int age;
	struct _person * next;
} Person;

int main(void)
{
	
	int input = 1;
	int i = 0;
	
	Person * current = NULL;
	Person * first = NULL;
	Person * last = NULL;
	
	while(1) {
		printf("회원을 추가하시겠습니까?: ");
		scanf("%d", &input);
		
		if(input == 0)
		{
			break;
		}
		
		Person * current = (Person*)malloc(sizeof(Person)); // 구조체 포인터 변수
		// 주소기 때문에 값에 접근해야 합니다. 
		
		printf("%d번 회원의 이름을 입력해주세요.: ", i + 1);
		scanf("%s", (*current).name);
		
		printf("%d번 회원의 나이를 입력해주세요.: ", i + 1);
		scanf("%d", &(*current).age);
		
		current->next = NULL;
		
		if(first == NULL)
		{
			first = current;
		} else {
			last->next = current; 
		}
		
		last = current; // 첫번째 실행때 last는 current와 같습니다. 주소값이 같으므로 
		i++;
	}
	
	i = 0;
	
	printf("== 전체 회원 리스트 ==\n");
	current = first;
	
	while(1)
	{
		printf("%d번째 회원 : %s, %d살\n", i + 1, current->name, current->age);
		
		if(current->next == NULL)
		{
			break;
		}
	
		current = current->next;
		i++;
	}
	
	i = 0;
	
	printf("== 메모리 반납 ==\n");
	current = first;
	
	while(1)
	{
		 
		printf("%d번 사람의 메모리를 반납합니다.\n", i+1);
		free(current);
		
		if(current->next == NULL)
		{
			printf("존재하는 메모리가 없습니다. \n");
			break;
		}

		current = current->next;
		i++;
	}
	
	return 0;
}
