#include <stdio.h>
#include <stdlib.h>

//헤드포인터의 헤드와 꼬리가 널값으로 초기화된 모양임
//헤드포인터에 이은 첫번째 노드의 헤드는 헤드포인터를 가르키지않고 널값을 가르킴
//마지막 노드의 꼬리는 헤드의 값을가지지 않고 널값을 가짐
//head -> 1 <-> 2 <-> 3 <-> 4 -> NULL 이런모양으로 생김 
//이중연결리스트를 추가할때 순서를 잘 생각해서 코드를 짜야 엉키지않고 정상적으로 연결된다. 

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

void d_insert(D_node *before, int item)	//새로운데이터를 before 오른쪽에 입력 
{
	D_node *new_node = (D_node *)malloc(sizeof(D_node));
	new_node->data = item;
	
	if(before->data == NULL)	//입력된 before가 head일때 
	{
		new_node->hlink = NULL;	//노드를 생성할때 첫번째 노드의 앞부분은 널값을 가르키도록 만든다 
		new_node->tlink = before->tlink;	//새로운 노드의 뒷부분을 이전이 가르키던 노드와 연결 
		
		if(before->tlink != NULL)	//head와 연결된 노드가 있었다면 
			before->tlink->hlink = new_node;	//원래head뒤에 있던노드와 새로운노드 연결
			
		before->tlink = new_node;	//head를 새로운 노드와 연결 
		
	}
	else	//입력된before가 head가 아닐경우 
	{
		new_node->hlink = before;	//새로운 노드의 앞부분을 before와 연결 
		new_node->tlink = before->tlink;	//새로운 노드의 뒷부분을 원래 before가 가지고 있던 뒷부분과 연결 
		before->tlink->hlink = new_node;	//원래before뒤에 있던노드와 새로운노드 연결 
		before->tlink = new_node;	//before를 새로운 노드와 연결 
	}
}

void d_delete(D_node *head, D_node *remove)
{
	if(head->tlink == NULL)
	{
		printf("삭제할 리스트가 없습니다. \n");	
		return;
	}
	if(remove->hlink == NULL)	//삭제할노드가 첫번째 노드일때 
	{
		if(remove->tlink == NULL)
		{
			printf("\n\n마지막 데이터를 삭제했습니다. \n\n");
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
	printf("추가단계 \n");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &input);
		getchar();
		d_insert(head, input);
		print_node(head);
	}
	printf("삭제단계 \n");
	for(i = 0; i < 5; i++)
	{
		print_node(head);
		d_delete(head, head->tlink);
	}
	free(head); 
	return 0;
}
