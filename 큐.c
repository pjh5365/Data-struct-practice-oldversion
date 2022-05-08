#include <stdio.h>

#define MAX_SIZE 100

typedef int element;

typedef struct queue{
	int front;
	int rear;
	element data[MAX_SIZE];
}Queue;

void error(char *msg)
{
	printf("%s \n", msg);
}

void init(Queue *p)
{
	p->front = 0;
	p->rear = 0;
}

int is_empty(Queue *p)
{
	return (p->front == p->rear);
}

int is_full(Queue *p)
{
	return ((p->rear + 1) % MAX_SIZE == p->front);
}

void queue_print(Queue *p)
{
	printf("Queue(front = %d, rear = %d) = ", p->front, p->rear);
	int i;
	if(!is_empty(p))
	{
		i = p->front;
		do
		{
			i = (i + 1) % MAX_SIZE;
			printf("%d | ", p->data[i]);
			if(i == p->rear)
				break;
		}while(i != p->front);
	}
	printf("\n");
}

void enqueue(Queue *p, element data)
{
	if(is_full(p))
	{
		error("큐가 포화상태입니다.");
	}
	p->rear = (p->rear + 1) % MAX_SIZE;
	p->data[p->rear] = data;
}

element dequeue(Queue *p)
{
	if(is_empty(p))
	{
		error("큐가 공백상태입니다.");
	}
	p->front = (p->front + 1) % MAX_SIZE;
	return p->data[p->front];
}

element peek(Queue *p)
{
	if(is_empty)
	{
		error("큐가 공백상태입니다.");
	}
	return p->data[(p->front + 1) % MAX_SIZE];
}

void Fibo(Queue *p, int n)
{
	int i;
	
	for(i = 2; i <= n; i++)
	{
		enqueue(p, (p->data[p->front + 1] + p->data[p->front + 2]));
		printf("F(%d) = %d \n", i-2, dequeue(p));
	}
}


int main(void)
{
	int input;
	Queue q1;
	init(&q1);
	printf("피보나치를 출력하는 프로그램  \n");
	
	printf("추가할 데이터를 입력하세요 : ");
	scanf("%d", &input);
	enqueue(&q1, 0);
	enqueue(&q1, 1);
	Fibo(&q1, input);
	
	
	printf("큐가 공백상태입니다. \n\n");
	
	return 0;
}
