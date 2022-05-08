#include <stdio.h>

typedef struct listnode{	//따로 사이즈라는 변수를 만들어서 노드의 갯수를 파악한후 그 갯수를 토대로 넣었다빼는게 가능한지 확인하기 
	int data;
	struct likedlist *link;
}Listnode;

void insert_first(Listnode *head, int value)	//새로운노드를 헤드바로뒤쪽 즉 맨앞에 생성하는함수 
{
	Listnode *p = (Listnode *)malloc(sizeof(Listnode));	//p라는 노드 동적할당으로선언 
	p->data = value;	//새로운 노드에 값입력 
	p->link = head->link;	//새로운 노드의 주소는 헤드포인터가 가지고있던 주소를이어받음 
	head->link = p;	//head의 주소에 p 즉 새로 생성한 노드의 주소값을 넘겨줌으로 새로운 노드를 생성 
	
}

void insert(Listnode *pre, int value)	//이론상완벽한데 pre의 주소를 넘겨줄 방법부터해결해야함....... 
{
	Listnode *p = (Listnode *)malloc(sizeof(Listnode));
	p->data = value;
	p->link = pre->link;	//이전노드가 가지고있던 주소를 p에 넘겨줌으로써 p를 정상적으로 추가해줌 
	pre->link = p;
}

void delete_first(Listnode *head)	//첫번째노드를 지우는함수 
{
	Listnode * remove;	//첫번째노드의 주소를 담을변수 
	if(head == NULL)
	{
		printf("삭제할 노드가 없습니다. \n");
	}
	remove = head->link;	//첫번째노드의 주소를 입력 
	head->link = remove->link;	//헤드포인터가 가르키는 주소에 첫번째노드가 가르키던 주소입력 
	free(remove);	//remove가 가르키는주소 즉 끊어진 노드의 주소를 할당해제
}

void delete_node(Listnode *pre)	//이론상 완벽한듯? 이전노드를 어떻게 받을건지부터 해결해야함.... 
{
	Listnode *remove;	//이전노드가 가르키는 주소를 담을 변수 
	remove = pre->link;
	pre->link = remove->link;	//이전노드의 주소에 이전노드의 주소가 가르키는 주소가 가르키는값입력 
	free(remove);	//remove가 가르키는주소 즉 끊어진 노드의 주소를 할당해제
}

void print_list(Listnode *head)	//연결리스트 전부를 출력하는함수 
{
	Listnode *p;	//p라는 구조체의 주소를 받아줄변수 
	
	for(p = head->link; p != NULL; p = p->link)	//p에 헤드가 가지고있는 주소로 초기화시켜주고 그 주소가 널값을 만날때까지 리스트를타고가게 만듦 
		printf("%d -> ", p->data);
		
	printf("NULL \n");
}

int main(void)
{
	int i;
	int input;
	Listnode *head = (Listnode *)malloc(sizeof(Listnode));	//이렇게 할당해서 하던지 아님 널포인터로 구현해도 되는듯
	head->link = NULL;										//널포인터로 할꺼면 함수를 구현할때 헤드포인터의 주소를 반환하게 만들어서 헤드에다가 저장해줘야함 
	
	for(i = 0; i < 5; i++)
	{
		printf("정수를 입력하세요 : ");
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
