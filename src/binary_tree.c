#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

void pre_order_traverse(BinaryTree tree)
{
    if (tree == NULL)
    {
	return;
    }

    printf ("%d\n", tree->data);
    pre_order_traverse(tree->left);
    pre_order_traverse(tree->right);
}

void in_order_traverse(BinaryTree tree)
{
    if (tree == NULL)
    {
	return;
    }

    in_order_traverse(tree->left);
    printf ("%d\n", tree->data);
    in_order_traverse(tree->right);
}

void post_order_traverse(BinaryTree tree)
{
    if (tree == NULL)
    {
	return;
    }

    post_order_traverse(tree->left);
    post_order_traverse(tree->right);
    printf ("%d\n", tree->data);
}

void create_binary_tree(BinaryTree* tree)
{
    int input_number;
    scanf("%d", &input_number);

    if (input_number == 0)
    {
	*tree = NULL;
    }
    else
    {
	*tree = (BinaryTree)malloc(sizeof(BinaryTreeNode));
	if (*tree == NULL)
	{
	    return;
	}

	(*tree)->data = input_number;
	create_binary_tree(&(*tree)->left);
	create_binary_tree(&(*tree)->right);
    }    
}

int main(int argc, char *argv[])
{
    BinaryTree tree = NULL;
    create_binary_tree(&tree);
    return 0;
}
