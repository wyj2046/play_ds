#ifndef _TREE_H_
#define _TREE_H_

#define MAXSIZE 20

// 双亲表示法
typedef struct ParentTreeNode
{
    int data;
    int parent;
}ParentTreeNode;

typedef struct ParentTree
{
    ParentTreeNode nodes[MAXSIZE];
    int root;
    int node_number;
}ParentTree;

// 孩子表示法
typedef struct ChildTreeNode
{
    int data;
    ChildTreeNode* next;
}ChildTreeNode;

typedef struct HeaderNode
{
    int data;
    ChildTreeNode* first_child;
}HeaderNode;

typedef struct ChildTree
{
    HeaderNode nodes[MAXSIZE];
    int root;
    int node_number;
}ChildTree;


// 孩子兄弟表示法
typedef struct ChildSiblingTreeNode
{
    int data;
    ChildSiblingTreeNode* child;
    ChildSiblingTreeNode* sibling;
}ChildSiblingTreeNode;

typedef ChildSiblingTreeNode* ChildSiblingTree;

#endif /* _TREE_H_ */
