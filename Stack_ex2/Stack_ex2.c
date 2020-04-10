/*
스택 예제 2번
https://claude-u.tistory.com/75
미로탐색 문제

<요령?>
1.이미 방문한 위치에는 표시를 해서 무한루프를 방지한다.
2.현재 위치에서 일정한 규칙으로 다음 위치로 이동한다.
  (1) 북,동,남,서 의 순서로 검사하여 그 방향으로 갈 수 있으면, 즉 아직 안가본 위치면서
  벽이 아니면 그 방향으로 간다.
  
3.아무 방향으로도 갈 수 없으면 그 위치에 오기 직전 위치로 되돌아 간다.



현재 위치는 (0,0).
  1.현재 위치에 방문했다는 표시를 함
  2.현재 위치가 출구라면 종료
  3.현재 위치에서 북, 동, 남, 서, 순서대로 탐색
    (1) 그 방향으로 이동가능성 따짐(벽이 아니고, 미로의 외부도 아님, 이미 반문한 위치도 아님)
        갈수 있으면 이동 -> push
  4.만약 3번에서 4방향 중 어느 쪽으로도 가지 못한다면 현재위치 이전의 위치로 돌아간다. => pop
*/


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>

#define MAX 5
#define WALL 1
#define PATH 0
#define VISITED 2
#define BACKTREACKED 3

pose Entrance = { 1,0 };
pose Exit = { MAX-2,MAX-1 };

bool searchFlag = false;

int map[MAX][MAX] = {
        {1,1,1,1,1},
        {0,0,0,0,0},
        {1,1,0,1,1},
        {1,1,0,0,0},
        {1,1,1,1,1}
};

pose search(pose* cur_pose,bool searchFlag) {

    /*
    현재 방향에서 북,동,남,서 좌표
    */
    pose North = { (cur_pose->x) - 1 ,cur_pose->y };
    pose East = { cur_pose->x ,(cur_pose->y) + 1 };
    pose South = { (cur_pose->x) + 1 ,cur_pose->y };
    pose West = { cur_pose->x,(cur_pose->y) - 1 };

    
    searchFlag = false; //이동가능한 방향을 찾았는지

    for (int i = 0; i < 4; i++)
    {
        if (searchFlag == false && map[North.x][North.y] <= PATH)
        {
            map[cur_pose->x][cur_pose->y] = VISITED;
            searchFlag = true;
            push(*cur_pose);
            return North;
        }

        if (searchFlag == false && map[East.x][East.y] <= PATH)
        {
            map[cur_pose->x][cur_pose->y] = VISITED;
            push(*cur_pose);
            searchFlag = true;
            return East;
        }

        if (searchFlag == false && map[South.x][South.y] <= PATH)
        {
            map[cur_pose->x][cur_pose->y] = VISITED;
            push(*cur_pose);
            searchFlag = true;
            return South;
        }

        if (searchFlag == false && map[West.x][West.y] <= PATH)
        {
            map[cur_pose->x][cur_pose->y] = VISITED;
            push(*cur_pose);
            searchFlag = true;
            return West;
        }
        else
        {
            map[cur_pose->x][cur_pose->y] = VISITED;
            return pop();
        }

    }
    
}


int main()
{
    

    pose cur_pose = Entrance;
    while (1)
    {
        if (cur_pose.x == Exit.x && cur_pose.y == Exit.y)
        {
            printf("%d %d\n", cur_pose.x, cur_pose.y);
            printf("Finishi!!");
            break;
        }
        printf("%d %d\n", cur_pose.x,cur_pose.y);
        cur_pose = search(&cur_pose,searchFlag);
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
