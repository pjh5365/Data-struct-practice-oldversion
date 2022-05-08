#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data;
	struct tree *left, *right;
}Tree;

void inorder(Tree *root)	//중위 순회 
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

void preorder(Tree *root)	//전위 순회 
{
	if(root != NULL)
	{
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void posorder(Tree *root)	//후위 순회 
{
	if(root != NULL)
	{
		posorder(root->left);
		posorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main(void)
{
	Tree *n1, *n2, *n3, *n4, *n5;
	n1 = (Tree *)malloc(sizeof(Tree));
	n2 = (Tree *)malloc(sizeof(Tree));
	n3 = (Tree *)malloc(sizeof(Tree));
	n4 = (Tree *)malloc(sizeof(Tree));
	n5 = (Tree *)malloc(sizeof(Tree));
	
	n1->data = 1;
	n1->left = n2;
	n1->right = n3;
	n2->data = 2;
	n2->left = n4;
	n2->right = n5;
	n3->data = 3;
	n3->left = NULL;
	n3->right = NULL;
	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;
	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;
	printf("전위 순회 : ");
	preorder(n1);
	printf("\n");
	printf("중위 순회 : ");
	inorder(n1);
	printf("\n");
	printf("후위 순회 : ");
	posorder(n1);
	printf("\n");
	 
	
	return 0;
}
