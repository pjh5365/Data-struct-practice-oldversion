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
	
	return head;	//��忡 ���ο� ����� �ּҸ� �����ѵ� ��ȯ���� 
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
		printf("%d��°����� �� %d \n", i, find_node->data);
	
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
		while(con->link != NULL)	//ù��° ����Ʈ�� ��������尡 �ΰ��� ����ų������ �ݺ� 
			con = con->link;
		
		con->link = head2;
		return head1;
	}
} 

Node * reverse(Node *head)
{
	Node *p, *q, *r;
	p = head;
	q = NULL;	
	while(p != NULL)
	{
		r = q;	//�Ųٷ� ���Թٲ۰� r�� 
		q = p;	//p�� ������ ��带 �������� 
		p = p->link;	//p�� ��ĭ������ 
		q->link = r;	//q�� ��带 �Ųٷ��帣�� �ٲ� 
	}
	return q;	//p�� �ΰ��� �ɶ����� �ݺ��ϴϱ� q�� �ΰ��ٷ����̹Ƿ� q�� ��ȯ���� 
}

int main(void)
{
	Node *head = NULL;
	Node *head1 = NULL;
	
	head = insert_first(head, 1);
	head = insert_first(head, 2);
	head = insert_first(head, 3);
	head = insert_first(head, 4);
	head = insert_first(head, 5);
	
	print_node(head);

	head1 = reverse(head);
	print_node(head1);

	
	
	return 0;
}
