#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� �����ϳ� ���� 

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

void d_insert(D_node *before, char data[])	//before�� �����ʿ� ��带 �߰��ϴ��Լ�
{
	D_node *new_node = (D_node *)malloc(sizeof(D_node));
	strcpy(new_node->data, data);
	
	if(strcmp(before->data, "\0") == 0)	//head�� �ԷµǾ����� 
	{
		new_node->hlink = NULL;
		new_node->tlink = before->tlink;
		
		if(before->tlink != NULL)	//head�� ����� ��尡 �־��ٸ� 
			before->tlink->hlink = new_node;	//����head�ڿ� �ִ����� ���ο��� ����
			
		before->tlink = new_node;	//head�� ���ο� ���� ���� 
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
	if(remove->hlink == NULL)	//�����ҳ�尡 ù��°����ϋ�
	{
		if(remove->tlink == NULL)	//ù��°������� ����������϶�
		{
			printf("������ ��带 �����߽��ϴ�. \n");
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
	while(p->tlink != NULL)	//p�� ��������������ų������ �ݺ� 
		p = p->tlink; 

	print_node(head);
	do
	{
		printf("\n\n��ɾ �Է��ϼ��� (<,>,q) : ");
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
