﻿#include <stdio.h>


int fibot(int n) {
	int tmp;
	int current = 1;
	int last = 0;
	
	
	if (n <= 2)
	{
		return n;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			tmp = current;					//
			current += last;				//
			last = tmp;						//임시변수 tmp를 통해서 n-1 과 n을 바꿔줌
		}
		return current;						//n번째 피보나치의 수 반환
	}


}


int main()
{
	printf("%d", fibot(5));			//출력:5번째 피보나치의 수
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
