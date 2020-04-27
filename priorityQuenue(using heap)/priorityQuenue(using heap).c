
#include <stdio.h>

void swap(int *a,int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Enquenue(int A[],int n,int data) {
	A[n] = data;
}

void Dequenue() {


}

void MaxHeap(int A[],int n,int i) {
	int l = (i * 2) + 1;
	int r = (i * 2) + 2;
	int largest = i;

	if (l < n && A[l] > A[largest])
	{
		largest = l;
	}
	if (r < n && A[r] > A[largest])
	{
		largest = r;
	}

	if (i != largest)
	{
		swap(&A[i], &A[largest]);
		MaxHeap(A, n, largest);
	}
}

void CreateQuenue(int A[], int n) {

	for (int i = 2 ; i >= 0; i--)
	{
		MaxHeap(A, n, i);
	}
	

}

int main()
{
	int A[100] = { 1,4,5,2,3,7,9};
	int n = sizeof(A) / sizeof(A[0]);

	CreateQuenue(A,n);
	Enquenue(A, n, 10);

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
