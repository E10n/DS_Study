/*
push : stack 이 생성되면 아래 주소를 가르도록 하고 새로 생성된 주소를 top 주소로 지정한다.
pop : top주소의 pre값을 top주소에 주고 원래 top이엿던 값을 free 시킨다. ( 이때 임시로 top의 주소를 cur에 복사해서 사용)
연결리스트로 구현
괄호검사 예제
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node* pre;
	char data;
}node;

node* top = NULL;

node* create_node(char n) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->pre = NULL;
	new_node->data = n;
	return new_node;
}

void push(char n) {
	if (top == NULL)
	{
		top = create_node(n);
		return;
	}
	else
	{
		node* new_node = create_node(n);
		new_node->pre = top;
		top = new_node;
		
	}
}

char pop() {
	node* cur = top;
	char result = cur->data;
	top = (top)->pre;
	free(cur);
	return result;
}

void show_all() {
	node* cur = top;

	while (cur != NULL)
	{
		printf("[%c] ", cur->data);
		cur = cur->pre;
	}
}


int main()
{
	char data[] = {"[{(a+b)*(a-b)-a}]"};
	for (int i = 0; i < strlen(data); i++)
	{
		if (data[i] == '(' || data[i] == '{' || data[i] == '[')
		{
			push(data[i]);
		}
		else if (data[i] == ')' || data[i] == '}' || data[i] == ']')
		{
			char tmp = top->data;
			if (tmp == '[' && data[i] == ']')
			{
				pop();
			}
			if (tmp == '{' && data[i] == '}')
			{
				pop();
			}
			if (tmp == '(' && data[i] == ')')
			{
				pop();
			}
		}
		
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
