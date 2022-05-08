#include <stdio.h>
#include <stdlib.h>

//����������� ���� ������ �ΰ����� �ʱ�ȭ�� �����
//��������Ϳ� ���� ù��° ����� ���� ��������͸� ����Ű���ʰ� �ΰ��� ����Ŵ
//������ ����� ������ ����� ���������� �ʰ� �ΰ��� ����
//head -> 1 <-> 2 <-> 3 <-> 4 -> NULL �̷�������� ���� 
//���߿��Ḯ��Ʈ�� �߰��Ҷ� ������ �� �����ؼ� �ڵ带 ¥�� ��Ű���ʰ� ���������� ����ȴ�. 

typedef struct double_node{
	int data;
	struct double_node *hlink;
	struct double_node *tlink;
}D_node;

void init(D_node *head)
{
	head->hlink = NULL;
	head->tlink = NULL;
	head->data = NULL; 
}

void print_node(D_node *head)
{
	D_node *p;
	for(p = head->tlink; p != NULL; p = p->tlink)
		printf("<-| %d |-> ", p->data);
	printf("\n");
}

void d_insert(D_node *before, int item)	//���ο���͸� before �����ʿ� �Է� 
{
	D_node *new_node = (D_node *)malloc(sizeof(D_node));
	new_node->data = item;
	
	if(before->data == NULL)	//�Էµ� before�� head�϶� 
	{
		new_node->hlink = NULL;	//��带 �����Ҷ� ù��° ����� �պκ��� �ΰ��� ����Ű���� ����� 
		new_node->tlink = before->tlink;	//���ο� ����� �޺κ��� ������ ����Ű�� ���� ���� 
		
		if(before->tlink != NULL)	//head�� ����� ��尡 �־��ٸ� 
			before->tlink->hlink = new_node;	//����head�ڿ� �ִ����� ���ο��� ����
			
		before->tlink = new_node;	//head�� ���ο� ���� ���� 
		
	}
	else	//�Էµ�before�� head�� �ƴҰ�� 
	{
		new_node->hlink = before;	//���ο� ����� �պκ��� before�� ���� 
		new_node->tlink = before->tlink;	//���ο� ����� �޺κ��� ���� before�� ������ �ִ� �޺κа� ���� 
		before->tlink->hlink = new_node;	//����before�ڿ� �ִ����� ���ο��� ���� 
		before->tlink = new_node;	//before�� ���ο� ���� ���� 
	}
}

void d_delete(D_node *head, D_node *remove)
{
	if(head->tlink == NULL)
	{
		printf("������ ����Ʈ�� �����ϴ�. \n");	
		return;
	}
	if(remove->hlink == NULL)	//�����ҳ�尡 ù��° ����϶� 
	{
		if(remove->tlink == NULL)
		{
			printf("\n\n������ �����͸� �����߽��ϴ�. \n\n");
			head->tlink = NULL; 
			free(remove);
			return;
		} 
		head->tlink = remove->tlink;
		remove->tlink->hlink = NULL;
		free(remove);
	}
	else
	{
		remove->tlink->hlink = remove->hlink;
		remove->hlink->tlink = remove->tlink;	
		free(remove);
	}
}

int main(void)
{
	int i;
	int input; 
	D_node *head = (D_node *)malloc(sizeof(D_node));
	init(head);
	printf("�߰��ܰ� \n");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &input);
		getchar();
		d_insert(head, input);
		print_node(head);
	}
	printf("�����ܰ� \n");
	for(i = 0; i < 5; i++)
	{
		print_node(head);
		d_delete(head, head->tlink);
	}
	free(head); 
	return 0;
}
