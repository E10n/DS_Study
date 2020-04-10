/*
스택 예제 1)
수식의 표기법
중위 표현법(연산자가 피연산자 중간에 있음) a + b
후위 표현법(연산자가 피연산자 뒤에 있음) ab*
컴퓨터는 사칙연산 계산을 후위표현법으로 구현이 됨.

[알고리즘 설명]

1. 피연산자는 스택에 넣지 않고 그냥 출력한다.

2. 연산자는 스택이 비었으면 스택에 push한다.

3. 연산자는 스택이 비어있지 않으면 스택에 있는 연산자와의 우선순위를 비교해 스택에 있는 연산자의 우선순위가 같거나 크다면 스택에 있는 연산자를 pop을 한 후 출력하고 현재 연산자는 스택에 push한다.

3.5 연산자가 '(' 일시 무조건 스택에 push 한다. 또한 연산자가 ')' 일경우 스택에서 '(' 만날때까지 pop을 한다. (스택에 '('이 있으면 안됨.)

4. 만약 3번에서 우선순위가 현재 연산자가 더 크면 현재 연산자를 push한다.(스택에서 pop하지 않음)

5. 수식이 끝나면 스택이 빌 때 까지 pop을 한 후 출력한다.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Stack
{
	struct Stack* pre;
	char data;
}stack;

stack* top = NULL;

int operator_check(char c) {
	if (c == '+' || c== '-')
	{
		return 1;
	}
	if (c == '*' || c == '/')
	{
		return 2;
	}
	if (c == '(')
	{
		return 0;
	}
}

void push(char c) {
	if (top == NULL)
	{
		top = (stack*)malloc(sizeof(stack));
		top->data = c;
		top->pre = NULL;
		return 0;
	}
	else
	{
		stack* new_stack = (stack*)malloc(sizeof(stack));
		new_stack->data = c;
		new_stack->pre = top;
		top = new_stack;
	}
}

char pop() {
	stack* cur = top;
	char tmp = cur->data;
	top = cur->pre;
	free(cur);
	return tmp;
}

int main()
{
	char string[] = "(A*(B+C))-D";

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] <= 47)
		{
			if (top == NULL)
			{
				push(string[i]);
			}
			else
			{
				if (string[i] == '(')
				{
					push(string[i]);
					continue;
				}
				if(string[i] == ')')
				{
					while (top->data != '(')
					{
						printf("%c", pop());
					}
					pop();
					continue;
				}

				else if (operator_check(top->data) <= operator_check(string[i]))
				{
					push(string[i]);
				}
				else if (operator_check(top->data) > operator_check(string[i]))
				{
					printf("%c", pop());
					push(string[i]);
				}
				
			}
		}
		else
		{
			printf("%c",string[i]);
		}
	
	}

	while (top != NULL)
	{
		printf("%c",pop());
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
