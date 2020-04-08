//https://www.youtube.com/watch?v=4x4X0t0iTAQ

/*
head 포인터를 유지하는게 중요하다.
main에서 선언된 head 변수를 다른함수들에서는 이중포인터로 받아서 계속해서 변경해준다.
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	struct Node *pre;
	struct Node *next;
	int data;

}node;

node *create_node(int n) {
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = n;
	new_node->pre = NULL;
	new_node->next = NULL; 

	return new_node;

}

void insert_head(node **phead, int n) {
	
	node *new_node = create_node(n);

	if (*phead == NULL)
	{
		*phead = new_node;
		return;
	}
	else
	{
		(*phead)->pre = new_node;
		new_node->next = *phead;
		*phead = new_node;
	}

}

void insert_tail(node **phead,int n) {
	node *new_node = create_node(n);
	node *cur = *phead;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	if (*phead == NULL)
	{
		*phead = new_node;
		return;
	}
	else
	{
		cur->next = new_node;
		new_node->pre = cur;
	}
}

void display(node** phead) {
	node* cur = *phead;
	while (cur != NULL)
	{
		printf("[%d] ",cur->data);
		cur = cur->next;
	}

}

void reverse_display(node** phead) {
	node* cur = *phead;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	while (cur != NULL)
	{
		printf("[%d] ",cur->data);
		cur = cur->pre;
	}
}

int main()
{

	node *head = NULL;
	insert_head(&head, 100);
	insert_head(&head, 200);
	insert_head(&head, 300);
	insert_head(&head, 400);
	insert_tail(&head, 500);
	//display(&head);
	reverse_display(&head);

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
