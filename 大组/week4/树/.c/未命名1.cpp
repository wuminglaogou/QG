#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//数 
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node, * NodePtr;
typedef struct {
	NodePtr root;
}Tree;
//栈 
typedef struct StackNode {
	Node node;
	struct StackNode* Next;
}StackNode, * LinkStack;
LinkStack S = NULL;
//队列 
typedef struct Qnode {
	Node node;
	struct Qnode* next;
}Qnode, * QuenePtr;
typedef struct Lqueue
{
	Qnode* front;
	Qnode* rear;
	int length;
}Lqueue;
Lqueue S0;
//初始化 
void InitQnode(Lqueue& S)
{
	S.front = (QuenePtr)malloc(sizeof(Qnode));
	S.front->next = NULL;
	S.rear = S.front;
}
//进入队列 
void get_int(Lqueue& S, Node add)
{
	if (S.front != NULL)
	{
		Qnode* p = (QuenePtr)malloc(sizeof(Qnode));
		p->node = add;
		p->next = NULL;
		S.rear->next = p;
		S.rear = p;
	}
}
//退出队列 
void  pop_Lqueue(Lqueue& S)
{
	Node p = S.front->next->node;
	QuenePtr P = S.front->next;
	S.front->next = P->next;
	if (P == S.rear)
		S.rear = S.front;
	free(P);
}
//获得队头 
Node* get_top_Lqueue(Lqueue& S)
{
	return &S.front->next->node;
}
//入栈 
void push(LinkStack& S, Node p)
{
	LinkStack P = (LinkStack)malloc(sizeof(StackNode));
	P->node = p;
	P->Next = S;
	S = P;
}
//出栈 
Node  pop(LinkStack& S)
{
		Node p = S->node;
		LinkStack P = S;
		S = S->Next;
		free(P);
		return p;
}
//获得栈顶 
Node *get_top(LinkStack& S)
{
	return &S->node;
}
//先序 
void preorder(NodePtr tree)
{
	if (tree != NULL)
	{
		printf("%d ", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
//非递归先序 
void preorder_iterative(NodePtr tree)
{
	if (tree == NULL)
	{
		return;
	}
	push(S, *(tree));
	while (S!=NULL)
	{
		Node node = pop(S);
		printf("%d ", node.data);
		if (node.right)
			push(S, *(node.right));
		if (node.left)
			push(S, *(node.left));
	}
}
//中序 
void inorder(NodePtr tree)
{
	if (tree != NULL)
	{
		inorder(tree->left);
		printf("%d ", tree->data);
		inorder(tree->right);
	}
}
//非递归中序 
void inorder_iterative(NodePtr tree)
{

	if (tree == NULL)
	{
		return;
	}
	NodePtr currentnode = tree;
	while (currentnode||S)
	{
		while (currentnode)
		{
			push(S, *currentnode);
			currentnode = currentnode->left;
		}
		Node p = pop(S);
		printf("%d ", p.data);
		currentnode = p.right;
	}
}
//后序 
void postorder(NodePtr tree)
{
	if (tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d ", tree->data);
	}
}
//非递归后序 
void postorder_iterative(NodePtr tree)
{
	if (tree == NULL)
	{
		return;
	}
	NodePtr currentnode = tree;
	NodePtr visitednode = tree;
	while (currentnode || S)
	{
		while (currentnode)
		{
			push(S, *currentnode);
			currentnode = currentnode->left;
		}
		currentnode = get_top(S);
		if (currentnode->right!=NULL && currentnode->right->data != visitednode->data)
		{
			currentnode = currentnode->right;
		}
		else
		{
			printf("%d ", currentnode->data);
			visitednode->data = currentnode->data;
			currentnode = NULL;
			pop(S);
		}
	}
}
//层序 
void levelOrder(NodePtr tree)
{
	if (tree == NULL)
	{
		return;
	}
	get_int(S0, *tree);
	while (S0.front->next)
	{
		NodePtr node =get_top_Lqueue(S0) ;	
		printf("%d ", node->data);
		if (node->left)
			get_int(S0, *node->left);
		if (node->right)
			get_int(S0, *node->right);
		pop_Lqueue(S0);
	}
}
//插入 
void insert(Tree* tree,int x[],int i)
{
	system("cls");
	int value;
	printf("请输入值:\n");
	scanf("%d", &value);
	getchar();
	x[i] = value;
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	if (tree->root == NULL)
	{
		tree->root = p;
	}
	else
	{
		NodePtr temp = tree->root;
		while (temp!=NULL)
		{
			if (value < temp->data) {
				if (temp->left == NULL)
				{
					temp->left = p;
					printf("插入成功\n");
					getchar();
					return;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				if (temp->right == NULL)
				{
					temp->right = p;
					printf("插入成功\n");
					getchar();
					return;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
	printf("插入成功\n");
	getchar();
}
//获得树高 
int get_height(NodePtr p)
{
	if (p == NULL)
		return 0;
	else
	{
		int left_h = get_height(p->left);
		int righ_h = get_height(p->right);
		int max = left_h > righ_h ? left_h : righ_h;
		return max + 1;
	}

}
//查找 
void find(NodePtr tree)
{
	int num;
	bool find_true = false;
	printf("请输入你要找的值:\n");
	scanf("%d", &num);
	getchar();
	if (tree == NULL)
	{
		printf("无值可找...\n");
		return;
	}
	get_int(S0, *tree);
	while (S0.front->next)
	{
		NodePtr node = get_top_Lqueue(S0);
		if (node->data == num)
		{
			if (find_true == false)
			{
				printf("%d已找到", node->data);
				find_true = true;
			}

		}
		if (node->left)
			get_int(S0, *node->left);
		if (node->right)
			get_int(S0, *node->right);
		pop_Lqueue(S0);
	}
	if (find_true == false)
		printf("没有找到...\n");
}
//删去 
NodePtr delet(NodePtr T, int val)
{
	if (T == NULL)
		return NULL;
	if (T->data > val)
	{
		T->left = delet(T->left, val);
		return T;
	}
	else if (T->data < val)
	{
		T->right = delet(T->right, val);
		return T;
	}
	else if (T->data == val)
	{
		if (T->left == NULL && T->right == NULL)
		{
			NodePtr temp = T;
			free(T);
			temp = NULL;
			return temp;
		}
		else if(T->left!=NULL&&T->right==NULL)
		{
			NodePtr temp = T->left;
			free(T);
			return temp;
		}
		else if (T->left == NULL && T->right != NULL)
		{
			NodePtr temp = T->right;
			free(T);
			return temp;
		}
		else if (T->left != NULL && T->right != NULL)
		{
			NodePtr cur = T->right;
			while (cur->left!=NULL)
			{
				cur = cur->left;
			}
			cur->left = T->left;
			NodePtr temp = T->right;
			free(T);
			return temp;
		}
	}
	return T;
}
//删去入口 
NodePtr del(NodePtr tree)
{
	int n;
	printf("请输入要删去的数:\n");
	scanf("%d", &n);
	getchar();
	tree = delet(tree, n);
	return tree;
}
int main()
{
	InitQnode(S0);
	Tree tree;
	tree.root = NULL;
	int choose = 0;
	int i = 0, x[1000];
	do
	{
		system("cls");
		printf("当前输入为:");
		levelOrder(tree.root);
		printf("\n");
		printf("1.插入\n2.先序遍历(递归)\n3.中序遍历(递归)\n4.后序遍历(递归)\n5.先序遍历(非递归)\n6.中序遍历(非递归)\n7.后序遍历(非递归)\n8.层序遍历\n9.删除\n10.查找\n其他.退出\n");
		scanf("%d", &choose);
		getchar();
		if(1 <= choose && choose <= 8)
		printf("树输出为:\n");
	switch (choose)
	{
	case 1:insert(&tree,x,i); i++; break;
	case 2:preorder(tree.root); getchar(); break;
	case 3:inorder(tree.root); getchar(); break;
	case 4:postorder(tree.root); getchar(); break;
	case 5:preorder_iterative(tree.root); getchar(); break;
	case 6:inorder_iterative(tree.root); getchar(); break;
	case 7:postorder_iterative(tree.root); getchar(); break;
	case 8:levelOrder(tree.root); getchar(); break;
	case 9:tree.root=del(tree.root); getchar(); break;
	case 10:find(tree.root); getchar(); break;
	default:break;
	}
	} while (1 <= choose && choose <= 10);
	//insert(&tree, arr[i]);
	//postorder(tree.root);
	//postorder_iterative(tree.root);
}
