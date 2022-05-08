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

int main(void)
{
	Node *head = NULL;
	Node *find = NULL;
	head = insert_first(head, 1);
	head = insert_first(head, 2);
	head = insert_first(head, 3);
	head = insert_first(head, 4);
	head = insert_first(head, 5);
	
	
	find = find_data(head, 3);
	
	printf("����Ʈ���� %d�� ã�ҽ��ϴ�.", find->data);
	
	return 0;
}
