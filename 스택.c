#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef char element;	//스택에 들어가는 요소의 자료형이므로 이것만 바꾸면 다른것은 안바꿔도됨 (정수형에서 문자형으로 갈때도 그냥 char로만 바꾸면됨) 

typedef struct stack{	//스택의 구조체 
	element data[MAX_SIZE];
	int top;
}Stack;

void stack_init(Stack *p)	//스택초기화함수 
{
	p->top = -1;
}

void push(Stack *p, element item)	//push연산 
{
	if(is_full(p))
	{
		fprintf(stderr, "스택 포화 에러 \n");
		exit(1);
	}
	else
		p->data[++(p->top)] = item;
}

element pop(Stack *p)	//pop연산 
{
	if(is_empty(p))
	{
		fprintf(stderr, "스택 공백 에러 \n");
		exit(1);
	}
	else
		return p->data[(p->top)--];	//해당위치의 값을 반환하고 top값 --하므로 안에는 값이 여전히 남아있긴함 
} 

element peek(Stack *p)	//peek연산 
{
	if(is_empty(p))
	{
		fprintf(stderr, "스택 공백 에러 \n");
		exit(1);
	}
	else
		return p->data[(p->top)];	//해당위치의 값만 반환함 
} 

int size(Stack *p)
{
	return p->top+1;
}

int is_empty(Stack *p)	//공백상태검출함수 
{
	return (p->top == -1);
}

int is_full(Stack *p)	//포화상태검출함수 
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
	printf("문자열을 입력하세요 : ");
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
		printf("희문입니다. \n");
		
	else
		printf("희문이아닙니다. \n");
	return 0;
}
