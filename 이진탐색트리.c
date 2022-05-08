#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data;
	struct tree *left, *right;
}Tree;

void inorder(Tree *root)
{
	if(root)
	{
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

Tree * new_node(int item)	//�����Ҵ��� ����� �ּҸ� ��ȯ�ϱ����� ��ȯ����� 
{
	Tree *n_node = (Tree *)malloc(sizeof(Tree));
	n_node->data = item;
	n_node->left = n_node->right = NULL;
	
	return n_node;
}

Tree * insert_node(Tree *node, int item)	 
{
	if(node == NULL)
		return new_node(item); 
	else
	{
		if(item < node->data)
			node->left = insert_node(node->left, item);
		else
			node->right = insert_node(node->right, item);
	}
	return node;
}

Tree * search(Tree *node, int key)
{
	if(node->data == key)
		return node;
	else if(key < node->data)
		return search(node->left, key);
	else
		return search(node->right, key);
}

Tree * min_value(Tree *node)
{
	Tree *current = node;
	
	while(current->left)
		current = current->left;
		
	return current;
}

Tree * delete_node(Tree *root, int key)
{
	if(root == NULL)
		return root;
	
	if(key < root->data)
		root->left = delete_node(root->left, key);

	else if(key > root->data)
		root->right = delete_node(root->right, key);
		
	else
	{
		if(root->left == NULL)
		{
			Tree *tmp = root->right;
			free(root);
			return tmp;
		}
		else if(root->right == NULL)
		{
			Tree *tmp = root->left;
			free(root);
			return tmp;
		}
		
		Tree *tmp = min_value(root->right);	//�İ��ڸ� �����ҳ���� ū���� �ּڰ����� ����
		root->data = tmp->data;	//������ ���� �İ��ڸ� ����� 
		root->right = delete_node(root->right, tmp->data);	//�İ��ڳ���� ���� 
	}
	return root; 
}

int main(void)
{
	Tree *root = NULL;
	
	root = insert_node(root, 10);
	root = insert_node(root, 20);
	root = insert_node(root, 30);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	
	inorder(root);
	printf("\n\n\n");
	delete_node(root, 30);
	inorder(root);
	
	/*
	if(search(root, 30) != NULL)
		printf("Ʈ������ 30�߰� \n");
	else
		printf("�߽߰��� \n");*/
	
	return 0;
}
