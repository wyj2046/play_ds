#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BinaryTreeNode;

typedef BinaryTreeNode* BinaryTree;

void pre_order_traverse(BinaryTree tree);

void in_order_traverse(BinaryTree tree);

void post_order_traverse(BinaryTree tree);

void create_binary_tree(BinaryTree* tree);


BinaryTree create_tree();

void pre_order_no_recursive(BinaryTreeNode* p_tree);

#endif /* _BINARY_TREE_H_ */
