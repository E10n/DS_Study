/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	struct node* left;
	struct node* middle;
	struct node* right;
	struct node* parent
	int firstKey;
	int secondKey;
	int size;
}Node;

Node* newNode(int data){
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = NULL;
	tmp->middle = NULL;
	tmp->right = NULL;
	tmp->firstKey = data;
	tmp->secondKey = -1;
	

	return tmp;
}

Node* Swap(Node* node,int data) {
	int tmp;
	tmp = node->firstKey;
	node->firstKey = data;
	node->secondKey = tmp;
	return node;
}

Node* SplitNode(Node* node,int data) {

}

bool isLeap(Node* node) {
	if (node->left == NULL && node->right == NULL )
	{
		return true;
	}
	else
	{
		return false;
	}
}



Node* Insert(Node* root, int data) {
	if (root == NULL)
	{
		root = newNode(data);
		return root;
	}
	if (root->size == 2)
	{

	}
	else
	{
		while (root != NULL)
		{
			if (root->firstKey < data)
			{
				root->left = Insert(root->left, data);
			}
			else if (root->firstKey < data && data < root->secondKey)
			{
				root->middle = Insert(root->middle, data);
			}
			else if (root->secondKey < data)
			{
				root->right = Insert(root->right, data);
			}
		}
		
	}

	return root;
}


int main()
{
	Node* TT = NULL;
	TT = Insert(TT, 10);
	TT = Insert(TT, 5);
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
