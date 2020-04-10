/*
큐의 구조체
큐의 front와 rear 그리고 크기(size)를 가리키는 구조체
큐를 생성 및 초기화
노드 생성 및 초기화
큐 삽입
큐 삭제
큐 탐색
https://www.youtube.com/watch?v=fCRTmqjTKIc

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

	struct node* next;
	char* data;

}Node;


typedef struct quenue {
	Node* front;
	Node* rear;
	int size;
}Quenue;


void createQuenue(Quenue* quenue) {
	(*quenue) = (Quenue*)malloc(sizeof(Quenue));
	(*quenue)->front = NULL;
	(*quenue)->rear = NULL;
	(*quenue)->size = 0;

}

Node* createNode(char* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(sizeof(strlen(data) + 1));
	strcpy(newNode->data,data);
	newNode->next = NULL;
	
	return newNode;
}


void deleteNode(Node* node) {
	free(node->data);
	free(node);
}


void Enquenue(Quenue* quenue,Node* node) {
	if (quenue->size == 0)
	{
		quenue->front = node;
		quenue->rear = node;
	}
	else
	{
		quenue->rear->next = node;
		quenue->rear = node;
	}
	quenue->size++;


}

Node* Dequenue(Quenue* quenue) {
	Quenue* cur = quenue;
	if (quenue->size == 0)
	{
		printf("Empty !!");
		return;
	}
	else
	{
		quenue->front = quenue->front->next;
	}

	return cur->front;
}


Node* deleteQuneue(Quenue* quenue) {
	Node* cur = Dequenue(quenue);
	deleteNode(cur);
	quenue->size--;
}


int main()
{
	Quenue* quenue;
	createQuenue(&quenue);

	Enquenue(quenue, createNode("C"));
	Enquenue(quenue, createNode("A"));
	Enquenue(quenue, createNode("B"));
	Enquenue(quenue, createNode("D"));



	for (int i = 0; i < quenue->size; i++)
	{
		printf("%c",quenue->front->data);
		quenue->front = quenue->front->next;
	}

	return 0;


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
