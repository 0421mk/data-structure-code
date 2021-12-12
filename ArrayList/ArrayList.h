#ifndef __ARRAY_LIST_H__ // ArrayList.h 파일이 존재하지 않는 경우에만 참조될 수 있도록 하는 매크로 
#define __ARRAY_LIST_H__

#define TRUE 1 // C언어에서는 TRUE라는 논리값이 없습니다. 그래서 매크로로 define 해준 것입니다. 
#define FALSE 0

#define LIST_LEN 100 // 리스트의 크기는 100으로 지정해놓았습니다. 
//typedef int LData; // 앞으로 Data가 될 값입니다. typedef는 별칭을 붙여주는 것 -> LDate 자료형은 int로 컴퓨터가 인식합니다

#include "Point.h"
typedef Point * LData;

//#include "NameCard.h"
//typedef NameCard * LData;

typedef struct __ArrayList // 배열 기반 리스트를 정의한 구조체 
{
	LData arr[LIST_LEN]; // 리스트 저장소
	int sizeOfData; // 저장된 데이터의 수
	int curPosition; // 데이터 참조위치 
} ArrayList; // 앞으로 사용할 구조체 이름 

typedef ArrayList List; // ArrayList -> List 이름으로 사용하겠다고 명시합니다.

void ListInit(List * plist); // 초기화 기능 
void LInsert(List * plist, LData data); // 데이터 삽입 기능 

int LFirst(List * plist, LData * pdata); // 첫 데이터 참조 기능 
int LNext(List * plist, LData * pdata); // 두번째 데이터 참조 기능 

LData LRemove(List * plist); // 데이터 삭제 기능 
int LCount(List * plist); // 데이터의 총 합을 구하는 기능 

#endif
