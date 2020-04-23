/*
노드 생성
노드를 트리에 붙힘
루트노드를 입력받고 왼쪽자식 노드가 없을경우 왼쪽, 있을경우 오른쪽 자식 노드에 넣어줌

[출력]
이진트리 높이
중위(inorder)
전위(preorder)
후위(postorder)
-> 재귀로 구현

[검사]
해당 노드가 leap 인지

해당 트리가 포화이진트리
해당 트리가 완전이진트리


비교->자식노드가 있는지 확인 -> 이동 -> 재귀
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node* left;
	int data;
	struct node* parent;
	struct node* right;
}Node;



Node* CreateNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->data = data;

	return newNode;
}

void SearchInsertLocation(Node* node, Node* newNode) {
	Node* curNode = node;
	if (curNode->data < newNode->data)
	{
		if (curNode->right == NULL)
		{
			curNode->right = newNode;
			newNode->parent = curNode;
		}
		else
		{
			SearchInsertLocation(curNode->right, newNode);

		}
		
	}
	else if(curNode->data > newNode->data)
	{
		if (curNode->left == NULL)
		{
			curNode->left = newNode;
			newNode->parent = curNode;
		}
		else
		{
			SearchInsertLocation(curNode->left, newNode);
		}
		
	}

}

void InsertNode(Node** proot, Node* newNode) {

	if (*proot == NULL)
	{
		*proot = newNode;
		return;
	}
	else
	{
		SearchInsertLocation(*proot, newNode);
	}
};

Node* DelNodeSearch(Node* node,int data) {
	Node* curNode = node;
	if (curNode->data == data)
	{
		return curNode;
	}
	else if (curNode->data < data)
	{
		curNode = curNode->right;
		DelNodeSearch(curNode, data);
	}
	else if (curNode->data > data)
	{
		curNode = curNode->left;
		DelNodeSearch(curNode, data);
	}
}

Node* SearchMin(Node* node) {
	Node* cur = node;

	if (cur->left != NULL)
	{
		SearchMin(cur->left);
	}
	else
	{
		return cur;
	}
}

void DelNode(Node* node,int data) {
	Node* cur = DelNodeSearch(node,data);

	if (cur->left == NULL && cur->right == NULL)
	{
		cur->parent = NULL;
		free(cur);
	}
	else if (cur->left != NULL && cur->right != NULL)
	{
		Node* subtreeMin = SearchMin(cur->right);
		cur->data = subtreeMin->data;
		if (subtreeMin->right != NULL)
		{
			subtreeMin->parent = cur->parent;
		}
		else
		{
			cur->parent = NULL;
		}
		free(cur);
	}
	else
	{
		if (cur->left != NULL)
		{
			cur->left->parent = cur->parent;
		}
		if (cur->right != NULL)
		{
			cur->right->parent = cur->parent;
		}
		free(cur);
	}


}

int main()
{
	Node* root = NULL;
	InsertNode(&root, CreateNode(4));
	InsertNode(&root, CreateNode(2));
	InsertNode(&root, CreateNode(6));
	InsertNode(&root, CreateNode(1));
	InsertNode(&root, CreateNode(10));
	InsertNode(&root, CreateNode(3));
	InsertNode(&root, CreateNode(5));
	DelNode(root, 4);

	
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
