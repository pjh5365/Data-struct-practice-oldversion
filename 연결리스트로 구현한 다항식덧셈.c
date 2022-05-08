#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{	//�ܼ��� �����������ִ¸���Ʈ 
	int coef;	//���
	int expon;	//����
	struct listnode *link;
}Listnode;

typedef struct listtype{	//��������Ű�� ����Ʈ�� ����Ű�� ������ 
	int size;
	Listnode *head;
	Listnode *tail;
}Listtype;

Listtype * create(void)
{
	Listtype * plist = (Listtype *)malloc(sizeof(Listtype));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(Listtype *plist, int coef, int expon)
{
	Listnode * tmp = (Listnode *)malloc(sizeof(Listnode));
	tmp->coef = coef;
	tmp->expon = expon;
	tmp->link = NULL;
	if(plist->tail == NULL)	//����Ʈ�� ��������� 
		plist->head = plist->tail = tmp;
	else
	{
		plist->tail->link = tmp;	//�������� ������ ����Ű�� �� ���̵���ִ� ��������尡 ����Ű�� �����ٰ� tmp�� �ּҸ� �Է� 
		plist->tail = tmp;	//�������� ������ tmp�� ����Ű���� �Է� �̷������� ���������� ������ ������ �߰��ϱ����� ��������带 ����Ű������ 
	}
	plist->size++;
}

void poly_add(Listtype *plist1, Listtype *plist2, Listtype *plist3)
{
	Listnode *a = plist1->head;
	Listnode *b = plist2->head;
	int sum;
	
	while(a != NULL && b != NULL)	//a��b�� �Ѵ� ���̾ƴҶ�? �ϳ��� ���̶�� ���� 
	{
		if(a->expon == b->expon)
		{
			sum = a->coef + b->coef;
			if(sum != 0)
			{
				insert_last(plist3, sum, a->expon);
				a = a->link;
				b = b->link;
			}
		} 
		else if(a->expon > b->expon)
			{
				insert_last(plist3, a->coef, a->expon);
				a = a->link;
			}
		else if(a->expon < b->expon)
			{
				insert_last(plist3, b->coef, b->expon);
				b = b->link;
			}
	}
	
	//���� �ϳ��� �������� ���� 
	
	for(; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for(; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
} 

void poly_print(Listtype *plist)
{
	Listnode *p = plist->head;
	printf("���׽� = ");
	for(; p; p = p->link)	//p�� ���̾ƴҶ������ݺ� 
		printf("%d^%d + ", p->coef, p->expon);
	printf("\n"); 
} 

int main(void)
{
	Listtype *list1, *list2, *list3;
	
	list1 = create();
	list2 = create();
	list3 = create();
	
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);
	
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);
	
	poly_print(list1);
	poly_print(list2);
		
	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1);
	free(list2);
	free(list3);
	
	return 0;
}
