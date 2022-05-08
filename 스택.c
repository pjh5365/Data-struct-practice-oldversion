#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef char element;	//���ÿ� ���� ����� �ڷ����̹Ƿ� �̰͸� �ٲٸ� �ٸ����� �ȹٲ㵵�� (���������� ���������� ������ �׳� char�θ� �ٲٸ��) 

typedef struct stack{	//������ ����ü 
	element data[MAX_SIZE];
	int top;
}Stack;

void stack_init(Stack *p)	//�����ʱ�ȭ�Լ� 
{
	p->top = -1;
}

void push(Stack *p, element item)	//push���� 
{
	if(is_full(p))
	{
		fprintf(stderr, "���� ��ȭ ���� \n");
		exit(1);
	}
	else
		p->data[++(p->top)] = item;
}

element pop(Stack *p)	//pop���� 
{
	if(is_empty(p))
	{
		fprintf(stderr, "���� ���� ���� \n");
		exit(1);
	}
	else
		return p->data[(p->top)--];	//�ش���ġ�� ���� ��ȯ�ϰ� top�� --�ϹǷ� �ȿ��� ���� ������ �����ֱ��� 
} 

element peek(Stack *p)	//peek���� 
{
	if(is_empty(p))
	{
		fprintf(stderr, "���� ���� ���� \n");
		exit(1);
	}
	else
		return p->data[(p->top)];	//�ش���ġ�� ���� ��ȯ�� 
} 

int size(Stack *p)
{
	return p->top+1;
}

int is_empty(Stack *p)	//������°����Լ� 
{
	return (p->top == -1);
}

int is_full(Stack *p)	//��ȭ���°����Լ� 
{
	return (p->top == (MAX_SIZE - 1));
}

int main(void)
{
	Stack s1, s2;
	stack_init(&s1);
	stack_init(&s2);
	int i = 0, count = 0;
	char st[MAX_SIZE];
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", st);
	
	while(st[i] != '\0')
	{
		push(&s1, st[i]);
		i++;
	}

	while(s1.top != -1)
	{
		push(&s2, pop(&s1));
	}
	i = 0;
	while(st[i] != '\0')
	{
		push(&s1, st[i]);
		i++;
	}
	
	while(!is_empty(&s1))
	{
		if(pop(&s1) == pop(&s2))
			count++;
	}
	
	if(count == strlen(st))
		printf("���Դϴ�. \n");
		
	else
		printf("���̾ƴմϴ�. \n");
	return 0;
}
