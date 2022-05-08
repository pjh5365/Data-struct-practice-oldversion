#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 50

typedef struct graph{	//그래프 
	int node;
	struct graph *link;
}Graph;

typedef struct graphhead{	//그래프의 헤더노드 
	int n;
	Graph *arr[MAX_NODE];
}Head;

void init(Head *g)
{
	int i;
	g->n = 0;
	for(i = 0; i < MAX_NODE; i++)
		g->arr[i] = NULL;
}

void insert_node(Head *g, int input)	//단순 노드의 번호편의를 위해삽입? 
{
	if((g->n) + 1 > MAX_NODE)
	{
		printf("그래프 : 정점의 갯수 초과. \n");
		return;
	}
	g->n++; 
}

void insert_link(Head *g, int a, int b)
{
	Graph *node = (Graph *)malloc(sizeof(Graph));
	if(a >= g->n || b >= g->n)
	{
		printf("그래프 : 정점 번호 오류. \n");
		return;
	}
	node->node = b;
	node->link = g->arr[a];
	g->arr[a] = node;
}

void print_arr(Head *g)
{
	int i;
	for(i = 0; i < g->n; i++)
	{
		Graph *p = g->arr[i];
		printf("정점 %d의 인접리스트", i);
		while(p != NULL)
		{
			printf("-> %d ", p->node);
			p = p->link;
		}
		printf("\n");
	}
}

int main(void)
{
	Head *g = (Head *)malloc(sizeof(Head));
	init(g);
	int i;
	for(i = 0; i < 4; i++)
		insert_node(g, i);
	insert_link(g, 0, 1);
	insert_link(g, 1, 0);
	insert_link(g, 0, 2);
	insert_link(g, 2, 0);
	insert_link(g, 0, 3);
	insert_link(g, 3, 0);
	insert_link(g, 1, 2);
	insert_link(g, 2, 1);
	insert_link(g, 2, 3);
	insert_link(g, 3, 2);
	print_arr(g);
	free(g);
	
	
	return 0;
}
