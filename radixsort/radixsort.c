#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct data {
	int data;
	struct data* next;
}Data;

typedef struct node
{
	int index;
	Data* data;
	struct node* pre;
	struct node* next;
}Node;



Node* createNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = NULL;
	newNode->pre = NULL;
	newNode->next = NULL;
	return newNode;
}

void createQuenue(Node** front,Node** rear) {
	for (int i = 0; i < 10; i++)
	{
		if (*front == NULL)
		{
			Node* newNode = createNode();
			newNode->index = 0;
			*front = newNode;
			*rear = newNode;
		}
		else
		{
			Node* newNode = createNode();
			newNode->index = i;
			(*rear)->next = newNode;
			newNode->pre = (*rear);
			(*rear) = newNode;
		}
		
	}

}

void Dequenue(Node* front,Node* rear,int A[],int size) {
	Node* f = front;
	Data* tmp = f->data;
	int index = 0;

	while (index != size)
	{
		if (f != NULL)
		{
			tmp = f->data;
			while (tmp != NULL)
			{
				A[index] = tmp->data;
				index++;
				tmp = tmp->next;
			}
		}
		f = f->next;
	}
	f = front;

	while (f != NULL)
	{
		f->data = NULL;
		f = f->next;
	}

}

int Max(int A[],int size) {
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		int d = A[i];
		while (1)
		{
			d = d / 10;
			count++;
			if (d == 0)
			{
				break;
			}
		}
		max = (max > count) ? max : count;
	}
	return max;
}

void radixSort(Node* front,Node* rear ,int A[], int size) {
	createQuenue(&front, &rear);
	Node* f = front;
	int max = Max(A, size);
	int mod = 10;
	int dmin = 1;
	for (int k = 0; k < max; k++)
	{
		for (int j = 0; j < size; j++)
		{
			int decimal = (A[j] % mod) / dmin;
			for (int i = 0; f != NULL; i++)
			{
				if (f->index == decimal)
				{
					Data* newData = (Data*)malloc(sizeof(Data));
					newData->data = A[j];
					newData->next = NULL;
					Data* tmp = f->data;
					if (f->data == NULL)
					{
						f->data = newData;

					}
					else
					{
						while (tmp->next != NULL)
						{
							tmp = tmp->next;
						}
						tmp->next = newData;
					}
					f = front;
					break;
				}
				else
				{
					f = f->next;
				}
			}
		}

		Dequenue(front, rear, A, size);

		mod *= 10;
		dmin *= 10;
	}
	}
	

int main()
{
	Node* front = NULL;
	Node* rear = NULL;
	int A[7] = { 251,231,362,431,954,656,932 };
	int size = sizeof(A) / sizeof(int);

	radixSort(front,rear,A,size);
	

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
