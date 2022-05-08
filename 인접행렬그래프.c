#include <stdio.h>
#include <stdlib.h>

typedef struct graph{
	int n;
	int arr[50][50];
}Graph;

void init(Graph *g)
{
	int r, c;
	g->n = 0;
	for(r = 0; r < 50; r++)
		for(c = 0; c <50; c++)
			g->arr[r][c] = 0;
}

void insert_node(Graph *g, int input)	//단순히 노드순서의 편의를 위해? 
{
	if((g->n) +1 > 50)	//50까지 전부 찼을때
	{
		printf("정점의 갯수 초과 \n");
		return;
	}
	g->n++;
}

void insert_link(Graph *g, int start, int end)
{
	if(start >= g->n || end >= g->n)
	{
		printf("정점번호 에러 \n");
		return;
	}
	g->arr[start][end] = 1;
	g->arr[end][start] = 1;
}

void print_arr(Graph *g)
{
	int i, j;
	for(i = 0; i < g->n; i++)
	{
		for(j = 0; j < g->n; j++)
				printf("%2d ", g->arr[i][j]);	
		
		printf("\n");
	}
}

int main(void)
{
	int i;
	Graph *a = (Graph *)malloc(sizeof(Graph));
	init(a);
	for(i = 0; i < 4; i++)
		insert_node(a, i);
	
	insert_link(a, 0, 1);
	insert_link(a, 0, 2);
	insert_link(a, 0, 3);
	insert_link(a, 1, 2);
	insert_link(a, 2, 3);
	print_arr(a);
	
	free(a); 
	
	return 0;
}
