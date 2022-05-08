#include <stdio.h>

typedef struct node{
	int data;
	struct node *link;
}Node;

Node * insert_first(Node *head, int input)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = input;
	new_node->link = head;
	head = new_node;
	
	return head;	//헤드에 새로운 노드의 주소를 복사한뒤 반환해줌 
}

void print_node(Node *head)
{
	Node *read_node;
	for(read_node = head; read_node != NULL; read_node = read_node->link)
		printf("%d -> ", read_node->data);
		
	printf("NULL \n");
}

Node *find_data(Node *head, int find)
{
	int i;
	Node *find_node;
	for(i = 1, find_node = head; find_node->data != find; find_node = find_node->link, i++)
		printf("%d번째노드의 값 %d \n", i, find_node->data);
	
	return find_node;
}

Node *connect_node(Node *head1, Node *head2)
{
	if(head1 == NULL)
		return head2;
	
	else if(head2 == NULL)
		return head1;
	else
	{
		Node *con;
		con = head1;
		while(con->link != NULL)	//첫번째 리스트의 마지막노드가 널값을 가르킬때까지 반복 
			con = con->link;
		
		con->link = head2;
		return head1;
	}
} 

int main(void)
{
	Node *head1 = NULL;
	Node *head2 = NULL;
	Node *total = NULL;
	head1 = insert_first(head1, 1);
	head1 = insert_first(head1, 2);
	head1 = insert_first(head1, 3);
	head2 = insert_first(head2, 4);
	head2 = insert_first(head2, 5);
	
	print_node(head1);
	print_node(head2);
	
	total = connect_node(head1, head2);
	print_node(total);
	
	
	
	return 0;
}
