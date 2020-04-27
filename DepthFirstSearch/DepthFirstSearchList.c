#include <stdio.h>
#include <stdlib.h>

struct Graph
{
	int v;
	struct AdjList* array;
};

struct AdjList
{
	struct AdjListNode* head;
};

struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

void DfsUtil(struct Graph* graph,int v,int visited[]) {
	visited[v] = 1;
	printf("%d ", v);

	struct AdjListNode* crawl;
	for (crawl = graph->array[v].head ; crawl != NULL ; crawl = crawl->next)
	{
		if (!visited[crawl->dest])
		{
			DfsUtil(graph, crawl->dest, visited);
		}
	}


}

void DFS(struct Graph* graph,int v) {
	int* visited = (int*)malloc(sizeof(int) * v);
	for (int i = 0; i < graph->v; i++)
	{
		visited[i] = 0;
	}
	
	DfsUtil(graph, v, visited);

}

struct AdjListNode* createAdjListNode(int dest) {
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;

	return newNode;
}

void addEdge(struct Graph* graph,int src,int dst) {
	struct AdjListNode* newNode = createAdjListNode(dst);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = createAdjListNode(src);
	newNode->next = graph->array[dst].head;
	graph->array[dst].head = newNode;


}

struct Graph* createGraph(int v) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;
	graph->array = (struct AdjList*)malloc(sizeof(struct AdjList) * v);
	
	for (int i = 0; i < v; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

int main()
{
	struct Graph* graph = createGraph(5);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	DFS(graph, 0);

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
