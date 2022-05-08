#include <stdio.h>

#define MAX_SIZE 100

typedef int element;

typedef struct list{
	element data[MAX_SIZE];
	int size;
}List;

void error(char *msg)
{
	printf("%s \n", msg);
}

void list_insert(List *p, int pos, element item)
{
	if(p->size >= MAX_SIZE)
	{
		error("리스트 오버플로우");
	}
	else
	{
		int i;
		for(i = p->size; i > pos - 1; i--)
		{
			p->data[i] = p->data[i - 1];
		}
		p->data[pos-1] = item;
		p->size++;	
	}
}

void list_insert_last(List *p, element item)
{
	if(p->size >= MAX_SIZE)
	{
		error("리스트 오버플로우");
	}
	else
		p->data[p->size++] = item;
}

void list_insert_first(List *p, element item)
{
	if(p->size >= MAX_SIZE)
	{
		error("리스트 오버플로우");
	}
	else
	{
		int i;
		for(i = p->size; i > 0; i--)
		{
			p->data[i] = p->data[i - 1];
		}
		p->data[0] = item;
		p->size++;	
	} 
}

void list_delete(List *p, int pos)	
{
	if(p->size == MAX_SIZE)
	{
		error("리스트가 이미 비어있습니다.");
	}
	else
	{
		int i;
		for(i = pos; i <= p->size; i++)
		{
			p->data[i - 1] = p->data[i];
		}
		p->size--;	
	}
}

void list_init(List *p)
{
	p->size = 0;
}

int is_full(List *p)
{
	return p->size == MAX_SIZE;
}

int is_empty(List *p)
{
	return p->size == 0;
}

void print_list(List *p)
{
	int i;
	for(i = 0; i < p->size; i++)
	{
		printf("%d -> ", p->data[i]);
	}
	printf("\n");
}

int main(void)
{
	int i;
	int input;
	List l;
	list_init(&l);
	for(i = 0; i < 10; i++)
	{	
		printf("정수를 입력하세요 : ");
		scanf("%d", &input);
		getchar();
		list_insert_first(&l, input);
	}
	list_insert(&l, 5, 100);
	list_delete(&l, 6);
	printf("%d \n\n", l.size);
	print_list(&l);
	
	
	return 0;
}
