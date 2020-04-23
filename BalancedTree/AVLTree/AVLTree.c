/*
https://ratsgo.github.io/data%20structure&algorithm/2017/10/27/avltree/
*/

#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
	struct node* left;
	struct node* right;
	int data;
	int height;
}Node;

int Height(Node* node) {
	if (node == NULL)
	{
		return 0;
	}
	return node->height;
};

int Balance(Node* node) {
	if (node == NULL)
	{
		return 0;
	}
	return Height(node->left) - Height(node->right);
}

int Max(int a,int b) {
	return (a > b) ? a : b;
}

Node* leftRotate(Node* root) {
	Node* x = root;
	Node* y = x->right;
	Node* z = y->left;

	y->left = x;
	x->right = z;

	x->height = Max(Height(x->left), Height(x->right)) + 1;
	y->height = Max(Height(y->left), Height(y->right)) + 1;

	return y;
}

Node* rightRotate(Node* root) {
	Node* x = root;
	Node* y = x->left;
	Node* z = y->right;

	y->right = x;
	x->left = z;

	x->height = Max(Height(x->left), Height(x->right)) + 1;
	y->height = Max(Height(y->left), Height(y->right)) + 1;

	return y;
}

Node* newNode(int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->right = NULL;
	tmp->left = NULL;
	tmp->height = 1;
	return tmp;
}

Node* Insert(struct node* Root,int data) {
	if (Root == NULL)
	{
		return newNode(data);
	}
	if (Root->data < data)
	{
		Root->right = Insert(Root->right, data);
	}
	else if (Root->data > data)
	{
		Root->left = Insert(Root->left,data);
	}
	else
	{
		return Root;
	}

	Root->height = Max(Height(Root->left), Height(Root->right)) + 1;

	int balance = Balance(Root);

	if (balance > 1 && Root->left->data < data)
	{
		Root->left = leftRotate(Root->left);
		return rightRotate(Root);
	}
	if (balance > 1 && Root->left->data > data)
	{
		return rightRotate(Root);
	}
	if (balance < -1 && Root->right->data < data)
	{
		return leftRotate(Root);
	}
	if (balance < -1 && Root->right->data > data)
	{
		Root->right = rightRotate(Root->right);
		return leftRotate(Root);
	}


	return Root;
};

Node* finMin(Node* node) {
	
	if (node->left == NULL)
	{
		return node;
	}
	else
	{
		node = node->left;
		finMin(node);
	}
}

Node* Delete(Node* root, int n) {

	if (root == NULL)
	{
		return root;
	}
	else if (root->data < n)
	{
		root->right = Delete(root->right, n);
	}
	else if (root->data > n)
	{
		root->left = Delete(root->left, n);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			Node* tmp = root->left;
			root = root->left;
			free(tmp);
		}
		else if (root->right != NULL && root->left == NULL)
		{
			Node* tmp = root->right;
			root = root->right;
			free(tmp);
		}
		else
		{
			Node* tmp = finMin(root->right);
			root->data = tmp->data;
			root->right = Delete(root->right, tmp->data);

		}
	}
	if (root==NULL)
	{
		return root;
	}
	
	root->height = Max(Height(root->left), Height(root->right)) + 1;

	int balance = Balance(root);

	if (balance > 1 && Balance(root->left) >= 0) // do not know
	{
		return rightRotate(root);
	}
	if (balance > 1 && Balance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && Balance(root->right) < 0)
	{
		return leftRotate(root);
	}
	if (balance < -1 && Balance(root->right) >= 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;

}



void predorder(Node* root) {
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ",root->data);
		predorder(root->left);
		predorder(root->right);
	}
}



int main()
{
	Node* AVL = NULL;
	AVL = Insert(AVL, 5);
	AVL = Insert(AVL, 10);
	AVL = Insert(AVL, 15);
	AVL = Insert(AVL, 25);
	AVL = Insert(AVL, 30);
	AVL = Insert(AVL, 14);
	AVL = Insert(AVL, 23);
	AVL = Insert(AVL, 6);
	AVL = Insert(AVL, 24);
	AVL = Insert(AVL, 3);

	AVL = Delete(AVL, 10);

	predorder(AVL);

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
