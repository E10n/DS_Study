/*
노드를 생성할때 new주소를 자기 자신의 주소로 한다.
그리고 새로운 노드를 생성할때마다 첫번째 주소값을 옮겨준다.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;


}node;

node* create_node(int n) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = n;
	new_node->next = new_node;

	return new_node;
}

void add_node(node** ptail,int n) {
	if (*ptail == NULL)
	{
		*ptail = create_node(n);
		return;
	}
	else
	{
		node* new_node = create_node(n);		
		new_node->next = (*ptail)->next;
		(*ptail)->next = new_node;
		*ptail = new_node;
	}

}

void display(node** ptail) {
	node* cur = *ptail;

	while (cur != NULL)
	{
		printf("[%d ]", cur->data);
		cur = cur->next;
	}
}


int main()
{
	node* tail = NULL;
	add_node(&tail, 4);
	add_node(&tail, 5);
	add_node(&tail, 6);
	display(&tail);
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
