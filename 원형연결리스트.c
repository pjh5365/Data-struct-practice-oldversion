#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}Node;

void insert_first(Node *head, int item)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *p = head->link;
	
	new_node->data = item;
	
	if(head->link == NULL)
	{
		head->link = new_node;
		new_node->link = head->link;
	}
	else
	{
		while(p->link != head->link)
		{
			p = p->link;
		}
		new_node->link = head->link;
		p->link = new_node;
		head->link = new_node;
	}
}

void insert_last(Node *head, int item)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *p = head->link;
	new_node->data = item;
	
	if(head->link == NULL)
	{
		head->link = new_node;
		new_node->link = head->link;
	}
	else
	{
		while(p->link != head->link)
		{
			p = p->link;
		}
		new_node->link = p->link;
		p->link = new_node;
	}
}

void print_node(Node *head)
{
	Node *p;
	p = head->link;
	//while(p != head->link)
	do{
		printf("%d -> ", p->data);
		p = p->link;
	}while(p != head->link);
}

int main(void)
{
	Node *head = (Node *)malloc(sizeof(Node));
	head->link = NULL;
	
	insert_first(head, 1);
	insert_first(head, 2);
	insert_first(head, 3);
	insert_first(head, 4);
	insert_first(head, 5);
	
	insert_last(head, 50);
	
	print_node(head);
	free(head);
	
	return 0;
} 
