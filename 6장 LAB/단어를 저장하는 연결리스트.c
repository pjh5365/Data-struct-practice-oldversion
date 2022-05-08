#include <stdio.h>

typedef struct node{
	char word[100];
	struct node *link;
}Node;

Node * insert_first(Node *head, char input[])
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	strcpy(newnode->word, input);
	newnode->link = head;
	head = newnode;
	return head;
}

void print_node(Node *head)
{
	Node *readnode;
	
	for(readnode = head; readnode != NULL; readnode = readnode->link)	//p�� ��尡 �������ִ� �ּҷ� �ʱ�ȭ�����ְ� �� �ּҰ� �ΰ��� ���������� ����Ʈ��Ÿ���� ���� 
		printf("%s -> ", readnode->word);
		
	printf("NULL");
}

int main(void)
{
	Node *head = NULL;
	char word[100];
	int i;
	for(i = 0; i < 3; i++) 
	{
		scanf("%s", word);
		getchar();
		head = insert_first(head, word);
		print_node(head);
	}
	
	return 0;
}
