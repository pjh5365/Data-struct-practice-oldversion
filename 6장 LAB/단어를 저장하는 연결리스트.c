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
	
	for(readnode = head; readnode != NULL; readnode = readnode->link)	//p에 헤드가 가지고있는 주소로 초기화시켜주고 그 주소가 널값을 만날때까지 리스트를타고가게 만듦 
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
