﻿//https://www.youtube.com/watch?v=aPYE0anPZqI&t=249s 참고용
#include <stdio.h>

void hanoi(int num, int from, int to, int other) {
	
	if (num == 0)
	{
		return;
	}
	hanoi(num - 1, from, other, to); //맨아래 바로 윗블럭을 목적지가 아닌곳으로 옮김(2번), 그 윗블럭을 옮김(1번)
	printf("%d에서 %d로 이동 \n",from,to);
	hanoi(num - 1, other, to, from); // 자기의 윗블럭을 자기한테로 옮김(이때 기준은 2번블럭임), 2번블럭위 윗블럭n-1은 2번블럭의 목적지가 아닌곳에
	//있으므로 이곳이 1번 블럭의출발지가 된다. 그리고 도착지는 2번 블럭의 목적지 이므로 to이다.

}
// (1) 윗블럭(n - 1)을 목적지가 아닌곳으로 옮긴다.
// (2) 맨 아래 블럭(n번째 블럭)을 목적지로 옮긴다.(맨 아래 블럭이 옮겨진 후에는 그 윗블럭이 자기 위로 와야됨)
// (3) 1번에서 옮겻던 블록을 2번으로 옮긴다.                <-|




int main()
{
	hanoi(2, 0, 1, 2);

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
