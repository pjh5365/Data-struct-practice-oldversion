#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{	//단순히 식을가지고있는리스트 
	int coef;	//계수
	int expon;	//지수
	struct listnode *link;
}Listnode;

typedef struct listtype{	//식을가르키는 리스트를 가르키는 헤더노드 
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
	if(plist->tail == NULL)	//리스트가 비어있을때 
		plist->head = plist->tail = tmp;
	else
	{
		plist->tail->link = tmp;	//헤더노드의 테일이 가르키는 즉 식이들어있는 마지막노드가 가르키는 값에다가 tmp의 주소를 입력 
		plist->tail = tmp;	//헤더노드의 테일이 tmp를 가르키도록 입력 이런식으로 하지않으면 테일은 여전히 추가하기전의 마지막노드를 가르키고있음 
	}
	plist->size++;
}

void poly_add(Listtype *plist1, Listtype *plist2, Listtype *plist3)
{
	Listnode *a = plist1->head;
	Listnode *b = plist2->head;
	int sum;
	
	while(a != NULL && b != NULL)	//a와b가 둘다 널이아닐때? 하나라도 널이라면 종료 
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
	
	//둘중 하나가 남았을때 진행 
	
	for(; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for(; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
} 

void poly_print(Listtype *plist)
{
	Listnode *p = plist->head;
	printf("다항식 = ");
	for(; p; p = p->link)	//p가 널이아닐때까지반복 
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
