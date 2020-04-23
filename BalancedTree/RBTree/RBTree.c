/*
https://brunch.co.kr/@toughrogrammer/12
https://www.youtube.com/watch?v=gF20ZSplxZE
https://zeddios.tistory.com/237
레드-블랙 트리
이진탐색트리의 일종
1. 각 노드는 red or black 이다.
2. 루트노드는 black
3. 모든 리프노드는 black
4. red의 자식은 black, black의 자식은 red or black
5. 모든 노드에 대해서 그 노드로부터 자손인 리프노드에 이르는 모든 경로에는 동일한 개수의
black 노드가 존재한다. -> 모든 경로에서 루트노드 -> nil노드까지 가는데 만나는 black 노드 개수는
같다.
6. 어떤노드 의 높이는 그 노드에서 nil노드까지 가는 거리이다.
7. 어떤노드의 블랙노드 높이는 그 노드에서 nil 노드 까지 가는데 만나는 black 개수이다.(노드 자신포함X)

 
균형잡힌 트리(balanced tree): O(log n)
search insert delete 연산을 최악의 경우에도 O(log n)이다.

노드는 하나의 키, 왼쪽자식, 오른쪽 자식, 부모노드 주소 저장
자식노드가 없으면 NIL 노드를 자식으로 가진다.
모든 리프노드 = NIL노드
루트의 부모노드도 NIL노드
노드들은 내부와 NIL노드로 구성됨
*/

#include <stdio.h>
#include <stdlib.h>

enum type {RED,BLACK};

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	enum type color;
};


void LeftRotate(struct Node** T, struct Node** x)
{
	//T is root, x is parent
	//x가 G의 좌측일때랑 우측일때가 다름.
	struct Node* y = (*x)->right;
	(*x)->right = y->left;
	if (y->left != NULL)
	{
		y->left->parent = (*x);
	}
	y->parent = (*x)->parent;
	if ((*x)->parent->right == (*x))
	{
		(*x)->parent->right = y;
	}
	else
	{
		(*x)->parent->left = y; //7,9 링킹 안됨
	}
	y->left = (*x);
	(*x)->parent = y;



}
void RightRotate(struct Node** T, struct Node** x)
{
	struct Node* y = (*x)->left;
	(*x)->left = y->right;
	if (y->right != NULL)
	{
		y->right->parent = (*x);
	}
	y->parent = (*x)->parent;
	if ((*x)->parent->left == (*x))
	{
		(*x)->parent->left = y;
	}
	else
	{
		(*x)->parent->right = y;
	}
	y->right = (*x);
	(*x)->parent = y;

}


void RB_insert_fixup(struct Node** T, struct Node** z)
{
	struct Node* parentp = NULL;
	struct Node* grandparent = NULL;

	while ((*z)!=(*T) && (*z)->color != BLACK && (*z)->parent->color == RED)
	{
		parentp = (*z)->parent;
		grandparent = parentp->parent;

		if (parentp == grandparent->left)
		{
			struct Node* uncle = grandparent->right;
			if (uncle != NULL && uncle->color == RED) // uncle is red
			{
				parentp->color = BLACK;
				uncle->color = BLACK;
				grandparent->color = RED;
				(*z) = grandparent; //6,7 입력 안됨

			}
			else // uncle is black
			{
				if ((*z) == parentp->right)
				{
					LeftRotate(T,&parentp); //@@@
					(*z) = parentp;
					parentp = (*z)->parent;
				}
				
				RightRotate(T,&grandparent); //
				parentp->color = BLACK;
				grandparent->color = RED;
				(*z) = parentp; //없으면 7 넣는데 오류 생김
				
			}

		}
		else // parent is grandparent's right
		{
			struct Node* uncle = grandparent->left;

			if (uncle != NULL && uncle->color == RED)
			{
				uncle->color = BLACK;
				parentp->color = BLACK;
				grandparent->color = RED;
				(*z) = grandparent;
			}
			else // uncle is black
			{
				if ((*z) == parentp->left)
				{
					RightRotate(T, &parentp);
					(*z) = parentp;
					parentp = (*z)->parent;
				}

				LeftRotate(T, &grandparent);
				grandparent->color = RED;
				parentp->color = BLACK;
				(*z) = parentp;  //없으면 7 넣는데 오류 생김
			}
		}
	}

	(*T)->color = BLACK;

}

struct Node* RB_insert(struct Node* T, int data)
{
	struct Node* z = (struct Node*)malloc(sizeof(struct Node));
	z->data = data;
	z->left = NULL;
	z->right = NULL;
	z->parent = NULL;
	z->color = RED;

	struct Node* x = T;
	struct Node* y = NULL;

	
	while (x != NULL)
	{
		y = x;
		if (x->data < z->data)
		{
			x = x->right;
		}
		else
		{
			x = x->left;
		}
	}
	z->parent = y;

	if (T == NULL)
	{
		T = z;
	}
	else if (y->data < z->data)
	{
		y->right = z;
	}
	else
	{
		y->left = z;
	}



	RB_insert_fixup(&T,&z);
	
	return T;
}

void preorder(struct Node* root)
{
    if (root == NULL)
        return;

    printf("%d\n", root->data);  
    preorder(root->left);
    preorder(root->right);
}


int main()
{
	struct Node* RBT = NULL; // root node
	RBT = RB_insert(RBT, 2);
	RBT = RB_insert(RBT, 1);
	RBT = RB_insert(RBT, 4);
 	RBT = RB_insert(RBT, 5);
	RBT = RB_insert(RBT, 9);
	RBT = RB_insert(RBT, 3);
	RBT = RB_insert(RBT, 6);
	RBT = RB_insert(RBT, 7);


    printf("\nPreorder - ");
    preorder(RBT);

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
