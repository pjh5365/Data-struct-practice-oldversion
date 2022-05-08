#include <stdio.h>

typedef struct listnode{	//���� �������� ������ ���� ����� ������ �ľ����� �� ������ ���� �־��ٻ��°� �������� Ȯ���ϱ� 
	int data;
	struct likedlist *link;
}Listnode;

void insert_first(Listnode *head, int value)	//���ο��带 ���ٷε��� �� �Ǿտ� �����ϴ��Լ� 
{
	Listnode *p = (Listnode *)malloc(sizeof(Listnode));	//p��� ��� �����Ҵ����μ��� 
	p->data = value;	//���ο� ��忡 ���Է� 
	p->link = head->link;	//���ο� ����� �ּҴ� ��������Ͱ� �������ִ� �ּҸ��̾���� 
	head->link = p;	//head�� �ּҿ� p �� ���� ������ ����� �ּҰ��� �Ѱ������� ���ο� ��带 ���� 
	
}

void insert(Listnode *pre, int value)	//�̷л�Ϻ��ѵ� pre�� �ּҸ� �Ѱ��� ��������ذ��ؾ���....... 
{
	Listnode *p = (Listnode *)malloc(sizeof(Listnode));
	p->data = value;
	p->link = pre->link;	//������尡 �������ִ� �ּҸ� p�� �Ѱ������ν� p�� ���������� �߰����� 
	pre->link = p;
}

void delete_first(Listnode *head)	//ù��°��带 ������Լ� 
{
	Listnode * remove;	//ù��°����� �ּҸ� �������� 
	if(head == NULL)
	{
		printf("������ ��尡 �����ϴ�. \n");
	}
	remove = head->link;	//ù��°����� �ּҸ� �Է� 
	head->link = remove->link;	//��������Ͱ� ����Ű�� �ּҿ� ù��°��尡 ����Ű�� �ּ��Է� 
	free(remove);	//remove�� ����Ű���ּ� �� ������ ����� �ּҸ� �Ҵ�����
}

void delete_node(Listnode *pre)	//�̷л� �Ϻ��ѵ�? ������带 ��� ������������ �ذ��ؾ���.... 
{
	Listnode *remove;	//������尡 ����Ű�� �ּҸ� ���� ���� 
	remove = pre->link;
	pre->link = remove->link;	//��������� �ּҿ� ��������� �ּҰ� ����Ű�� �ּҰ� ����Ű�°��Է� 
	free(remove);	//remove�� ����Ű���ּ� �� ������ ����� �ּҸ� �Ҵ�����
}

void print_list(Listnode *head)	//���Ḯ��Ʈ ���θ� ����ϴ��Լ� 
{
	Listnode *p;	//p��� ����ü�� �ּҸ� �޾��ٺ��� 
	
	for(p = head->link; p != NULL; p = p->link)	//p�� ��尡 �������ִ� �ּҷ� �ʱ�ȭ�����ְ� �� �ּҰ� �ΰ��� ���������� ����Ʈ��Ÿ���� ���� 
		printf("%d -> ", p->data);
		
	printf("NULL \n");
}

int main(void)
{
	int i;
	int input;
	Listnode *head = (Listnode *)malloc(sizeof(Listnode));	//�̷��� �Ҵ��ؼ� �ϴ��� �ƴ� �������ͷ� �����ص� �Ǵµ�
	head->link = NULL;										//�������ͷ� �Ҳ��� �Լ��� �����Ҷ� ����������� �ּҸ� ��ȯ�ϰ� ���� ��忡�ٰ� ����������� 
	
	for(i = 0; i < 5; i++)
	{
		printf("������ �Է��ϼ��� : ");
		scanf("%d", &input);
		getchar();
		insert_first(head, input);
	}
	
	print_list(head);	
	for(i = 0; i < 5; i++)
	{
		delete_first(head);
		print_list(head);	
	}
	free(head);
	return 0;
} 
