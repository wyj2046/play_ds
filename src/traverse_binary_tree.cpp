#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>

#include <iostream>

using namespace std;


template <typename T>
class TreeNode
{
public:
    TreeNode() : left(NULL), right(NULL), isFirst(true) {}
    T value;
    TreeNode* left;
    TreeNode* right;
    bool isFirst;
    bool operator<=(const TreeNode& rhs)
	{
	    return value <= rhs.value;
	}
    virtual ~TreeNode()
	{
	    
	}
};

template <typename T>
void my_swap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}

template <typename T>
int partition(T array[], int begin, int end)
{
    int j = begin - 1;
    T temp = array[end];
    for (int i = begin; i < end; ++i)
    {
	if (array[i] <= temp)
	{
	    my_swap(array[j+1], array[i]);
	    ++j;
	}
    }
    swap(array[j+1], array[end]);
    return j+1;
}

template <typename T>
void quickSort(T array[], int begin, int end)
{
    if (begin < end)
    {
	int pivot = partition(array, begin, end);
	quickSort(array, begin, pivot-1);
	quickSort(array, pivot+1, end);
    }
}

template <typename T>
TreeNode<T>* buildTree(TreeNode<T> array[], int begin, int end)
{
    if (begin < end)
    {
	int middle = begin + (end - begin + 1) / 2;
	array[middle].left = buildTree(array, begin, middle-1);
	array[middle].right = buildTree(array, middle+1, end);
	return array+middle;
    }
    else if (begin == end)
    {
	return array + begin;
    }
    else
    {
	return NULL;
    }
}

template <typename T, typename VisitFun>
void visitTree(TreeNode<T>* current, VisitFun visit_fun)    //层序遍历
{
    queue<TreeNode<T>*> node_queue;
    node_queue.push(current);
    while (!node_queue.empty())
    {
	current = node_queue.front();
	visit_fun(current->value);
	node_queue.pop();
	if (current->left)
	{
	    node_queue.push(current->left);
	}
	if (current->right)
	{
	    node_queue.push(current->right);
	}
    }
}

template <typename T, typename VisitFun>
void pre_order_visit(TreeNode<T>* p_tree, VisitFun visitFun)
{
    if (p_tree)
    {
	visitFun(p_tree->value);
	pre_order_visit(p_tree->left, visitFun);
	pre_order_visit(p_tree->right, visitFun);
    }
}

template <typename T, typename VisitFun>
void pre_order_visit_no_recursive(TreeNode<T>* p_tree, VisitFun visitFun)
{
    stack<TreeNode<T>*> node_stack;
    while (p_tree != NULL || !node_stack.empty())
    {
	if (p_tree != NULL)
	{
	    visitFun(p_tree->value);    //先序就体现在这里了，先访问，
	    node_stack.push(p_tree);    //再入栈
	    p_tree = p_tree->left;      //依次访问左子树
	}
	else
	{
	    p_tree = node_stack.top();    //回溯至父节点
	    node_stack.pop();
	    p_tree = p_tree->right;
	}
    }
}

template <typename T, typename VisitFun>    //貌似这个版本正规些
void pre_order_visit_no_recursive2(TreeNode<T>* p_tree, VisitFun visitFun)
{
    stack<TreeNode<T>*> node_stack;

    while (p_tree != NULL || !node_stack.empty())    //直到p_tree为NULL并且栈为空，则遍历结束
    {
	while (p_tree != NULL)
	{
	    visitFun(p_tree->value);    //访问结点p_tree，
	    node_stack.push(p_tree);    //并将结点p_tree入栈;
	    p_tree = p_tree->left;      //若不为空，则将p_tree的左孩子置为当前的结点p_tree
	}
	if (!node_stack.empty())
	{
	    p_tree = node_stack.top();    //判断结点p_tree的左孩子是否为空，若为空，则取栈顶结点
 	    node_stack.pop();             //并进行出栈操作，
	    p_tree = p_tree->right;       //并将栈顶结点的右孩子置为当前的结点p_tree，循环至1)
	}
    }
}

template <typename T, typename VisitFun>
void in_order_visit(TreeNode<T>* p_tree, VisitFun visitFun)
{
    if (p_tree)
    {
	in_order_visit(p_tree->left, visitFun);
	visitFun(p_tree->value);
	in_order_visit(p_tree->right, visitFun);
    }
}

template <typename T, typename VisitFun>
void in_order_visit_no_recursive(TreeNode<T>* p_tree, VisitFun visitFun)
{
    stack<TreeNode<T>*> node_stack;
    while (p_tree != NULL || !node_stack.empty())    //直到p_tree为NULL并且栈为空则遍历结束
    {
	while (p_tree != NULL)
	{
	    node_stack.push(p_tree);    //若其左孩子不为空，则将p_tree入栈
	    p_tree = p_tree->left;      //并将p_tree的左孩子置为当前的p_tree，然后对当前结点p_tree再进行相同的处理
	}
	if (!node_stack.empty())
	{
	    p_tree = node_stack.top();    //若其左孩子为空，则取栈顶元素并进行出栈操作，
	    node_stack.pop();
	    visitFun(p_tree->value);      //访问该栈顶结点，
	    p_tree = p_tree->right;       //然后将当前的p_tree置为栈顶结点的右孩子
	}
    }
}

template <typename T, typename VisitFun>
void post_order_visit(TreeNode<T>* p_tree, VisitFun visitFun)
{
    if (p_tree)
    {
	post_order_visit(p_tree->left, visitFun);
	post_order_visit(p_tree->right, visitFun);
	visitFun(p_tree->value);
    }
}

template <typename T, typename VisitFun>
void post_order_visit_no_recursive(TreeNode<T>* p_tree, VisitFun visitFun)
{
    stack<TreeNode<T>*> node_stack;
    while (p_tree != NULL || !node_stack.empty())
    {
	while (p_tree != NULL)
	{
	    p_tree->isFirst = true;
	    node_stack.push(p_tree);
	    p_tree = p_tree->left;
	}
	if (!node_stack.empty())
	{
	    p_tree = node_stack.top();
	    node_stack.pop();
	    if (p_tree->isFirst == true)
	    {
		p_tree->isFirst = false;
		node_stack.push(p_tree);
		p_tree = p_tree->right;
	    }
	    else
	    {
		visitFun(p_tree->value);
		p_tree = NULL;
	    }
	}
    }
}

template <typename T, typename VisitFun>
void post_order_visit_no_recursive2(TreeNode<T>* p_tree, VisitFun visitFun)    //有BUG，少最左边的叶子节点？
{
    stack<TreeNode<T>*> node_stack;
    node_stack.push(p_tree);
    TreeNode<T>* p_previous = NULL;
    TreeNode<T>* p_current;

    while (!node_stack.empty())
    {
	p_current = node_stack.top();
	if ((p_current->left == NULL && p_current->right == NULL) || (p_current != NULL && (p_previous == p_current->left || p_previous == p_current->right)))    //如果当前结点没有孩子结点或者孩子节点都已被访问过
	{
	    visitFun(p_current->value);
	    node_stack.pop();
	    p_previous = p_current;
	}
	else
	{
	    if (p_current->right != NULL)
	    {
		node_stack.push(p_current->right);
	    }
	    if (p_current->left != NULL)
	    {
		node_stack.push(p_current->left);
	    }
	}
    }
}

void printInt(int value)
{
    cout << value << ' ';
}


int main(int argc, char *argv[])
{
    const int node_number = 10;
    // srand(time(NULL));
    TreeNode<int> tree[node_number];
    for (int i = 0; i < node_number; ++i)
    {
	tree[i].value = rand() % 100;
    }

    cout << "有序数组: ";
    quickSort(tree, 0, node_number-1);
    for (int i = 0; i < node_number; ++i)
    {
	cout << tree[i].value << ' ';
    }
    cout << endl;

    cout << "建    树: ";
    TreeNode<int>* head = buildTree(tree, 0, node_number-1);
    visitTree(head, printInt);
    cout << endl;

    cout << "先序遍历: ";
    //pre_order_visit(head, printInt);
    pre_order_visit_no_recursive(head, printInt);
    //pre_order_visit_no_recursive2(head, printInt);
    cout << endl;

    cout << "中续遍历: ";
    //in_order_visit(head, printInt);
    in_order_visit_no_recursive(head, printInt);
    cout << endl;

    cout << "后续遍历: ";
    //post_order_visit(head, printInt);
    //post_order_visit_no_recursive(head, printInt);
    post_order_visit_no_recursive2(head, printInt);
    cout << endl;
    return 0;
}
