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

Tree * new_node(int item)	//새로할당한 노드의 주소를 반환하기위해 반환형사용 
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
		
		Tree *tmp = min_value(root->right);	//후계자를 삭제할노드의 큰값의 최솟값으로 결정
		root->data = tmp->data;	//삭제할 값에 후계자를 덮어씌움 
		root->right = delete_node(root->right, tmp->data);	//후계자노드의 삭제 
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
		printf("트리에서 30발견 \n");
	else
		printf("발견실패 \n");*/
	
	return 0;
}
