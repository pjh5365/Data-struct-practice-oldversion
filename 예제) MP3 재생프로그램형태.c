#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct d_node{
	char data[100];
	struct d_node *hlink;
	struct d_node *tlink;
}D_node;

D_node *current;

void print_node(D_node *head)
{
	D_node *p;
	for(p = head->tlink; p != NULL; p = p->tlink)
	{
		if(p == current)
			printf("<-|# %s #|-> ", p->data);
		else
			printf("<-| %s |-> ", p->data);
	}
	printf("\n");
}

void d_insert(D_node *before, char data[])	//before의 오른쪽에 노드를 추가하는함수
{
	D_node *new_node = (D_node *)malloc(sizeof(D_node));
	strcpy(new_node->data, data);
	
	if(strcmp(before->data, "\0") == 0)	//head가 입력되었을때 
	{
		new_node->hlink = NULL;
		new_node->tlink = before->tlink;
		
		if(before->tlink != NULL)	//head와 연결된 노드가 있었다면 
			before->tlink->hlink = new_node;	//원래head뒤에 있던노드와 새로운노드 연결
			
		before->tlink = new_node;	//head를 새로운 노드와 연결 
	}
	else
	{
		new_node->hlink = before;
		new_node->hlink = before->tlink;
		before->tlink->hlink = new_node;
		before->tlink = new_node;
	}
}

void d_delete(D_node *head, D_node *remove)
{
	if(remove->hlink == NULL)	//삭제할노드가 첫번째노드일
	{
		if(remove->tlink == NULL)	//첫번째노드이자 마지막노드일때
		{
			printf("마지막 노드를 삭제했습니다. \n");
			head->tlink = NULL;
			free(remove); 
		}
		else
		{
			head->tlink = remove->tlink;
			remove->tlink->hlink = NULL;
			free(remove);
		}
	}
	else
	{
		remove->hlink->tlink = remove->tlink;
		remove->tlink->hlink = remove->hlink;
		free(remove);
	}
} 

int main(void)
{
	char ch;
	D_node *head = (D_node *)malloc(sizeof(D_node));
	D_node *p;
	head->hlink = head->tlink = NULL;
	strcpy(head->data, "\0");
	
	d_insert(head, "Mamamia");
	d_insert(head, "Dancing Queen");
	d_insert(head, "Fernando");
	
	current = head->tlink;
	p = head->tlink;
	while(p->tlink != NULL)	//p가 마지막값을가르킬때까지 반복 
		p = p->tlink; 

	print_node(head);
	do
	{
		printf("\n\n명령어를 입력하세요 (<,>,q) : ");
		ch = getchar();
		getchar();
		printf("\n");
		if(ch == '<')
		{
			if(current->hlink == NULL)
				current = p;
			
			else
				current = current->hlink;
		}
		else if(ch == '>')
		{
			current = current->tlink;
			if(current == NULL)
				current = head->tlink;
		}
		print_node(head);
	}while(ch != 'q');
	
	free(head);
	
	return 0;
}
