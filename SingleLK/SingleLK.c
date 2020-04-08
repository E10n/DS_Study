/*
참고 블로그
https://codevkr.tistory.com/49
참고 동영상 
기능 : 추가,삭제,검색

*/
#include <stdio.h>
#include <stdlib.h> //malloc


//구조체를 함수보다 위에 선언한다.
typedef struct Node
{
	struct Node* next;
	int value;
} node;

//노드를 추가할때는 head뒤에 다가 추가
void add_node(node* head,int n) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = n;
	new_node->next = head->next;
	head->next = new_node;
	printf("노드값이 추가됨\n");
}

//head 뒤 노드를 삭제
void del_node(node* head) {
	node* cur = head->next;
	head->next = cur->next;
	free(cur);
	printf("노드값이 삭제됨\n");
}
void search_node(node* head,int n) {
	node* cur = head;
	for (int i = 0; i < n; i++)
	{
		cur = cur->next;
	}
	if (cur == NULL)
	{
		printf("찾는 노드의 값이 없습니다.\n");
		return;
	}
	printf("%d 번쨰 노드의 값은 %d입니다.\n", n, cur->value);

}
void show_all(node* head) {
	node* cur = head->next;
	while (cur != NULL)
	{
		printf("[%d] ", cur->value);
		cur = cur->next;
	}
}

int main()
{

	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	add_node(head,3);
	add_node(head, 4);
	add_node(head, 5);
	del_node(head);
	add_node(head, 2);
	show_all(head);
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
