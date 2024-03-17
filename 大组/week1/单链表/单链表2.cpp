#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct ElemType
{
	int num;
};
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkedList;
	LinkedList L;//头指针
void Menu( )
{
	int choose;
	void CreateList1(LinkedList & L);
	void Distroy_List2(LinkedList & L);
	void ListInsert_L3(LinkedList & L);
	void Delect_List4(LinkedList & L);
	void List_Print5(LinkedList L);
	void List_Find6(LinkedList L);
	void List_rollback7(LinkedList & L);
	void List_Circle8(LinkedList & L);
	LinkedList List_Find_Middle9(LinkedList & L);
	void List_exchange10(LinkedList & L);
	do
	{
	system("cls");
	printf("\n\n单链表ADT\n\n");
	printf("1.创建空链表\n2.销毁链表\n3.插入节点\n4.删除节点\n5.遍历链表\n6.查找数据\n7.反转链表\n8.判断链表是否成环\n9.找到单链表的中点\n10.单链表的奇偶调换\n其他.退出\n\n");
	printf("请输入对应数据\n\n");
	scanf("%d", &choose);
	getchar();
	switch (choose)
	{
	case 1:CreateList1(L); break;
	case 2:Distroy_List2(L); break;
	case 3:ListInsert_L3(L); break;
	case 4:Delect_List4(L); break;
	case 5:List_Print5(L); break;
	case 6:List_Find6(L); break;
	case 7:List_rollback7(L); break;
	case 8:List_Circle8(L); break;
	case 9:L=List_Find_Middle9(L); break;
	case 10:List_exchange10(L); break;
	default:break;
	}
	} while (1<=choose&&choose<=10);
}
int main()
{
	Menu();
	getchar();
}
void CreateList1(LinkedList& L)
{
	system("cls");
	L = (LNode*)malloc(sizeof(LNode));//制作头节点，不储存数据
	L->next = NULL;
	printf("\n创建链表成功！\n");
	getchar();
	
}
void Distroy_List2(LinkedList& L)
{
	system("cls");
	if (L)
	{
		LinkedList p = L->next;
		while (p)
		{
			free(L);
			L = p;
			p = p->next;
		}
		printf("销毁成功\n");
	}
	else
	{
		printf("为空链表！\n");
	}
	getchar();

}
void Delect_List4(LinkedList& L)
{
	system("cls");
	if (L)
	{
		int del;
		printf("输入将删除的数据...\n");
		scanf("%d", &del);
		getchar();
		LinkedList p = L->next,q=L;
		while (p&&p->data.num!=del)
		{
			q = p;
			p = p->next;
		}
		if (!p)
			printf("没找到该数据\n");
		else
		{
			q->next = p->next;
			free(p);
			printf("删除成功!\n");
		}
	}
	else
	{
		printf("为空链表！\n");
	}
	getchar();
	
}
void ListInsert_L3(LinkedList& L)
{
	system("cls");
	if (L != NULL)
	{
	
	LinkedList insert = (LNode*)malloc(sizeof(LNode));
	LinkedList p = L;
	printf("请输入数据:\n");
	scanf("%d", &insert->data.num);
	getchar();
	while (p->next)
	{
		p = p->next;
	}
	p->next = insert;
	insert->next = NULL;
	printf("输入数据成功！\n");
    }
	else
	{
		printf("为空链表\n");
	}
	getchar();

}
void List_Print5(LinkedList L)
{
	system("cls");
	if (L)
	{
		LinkedList p = L->next;
		for (int i = 1; p; i++)
		{
			printf("第%d个数据是%d\n", i, p->data.num);
			p = p->next;
		}
		printf("遍历已完成\n");
	}
	else
	{
		printf("为空链表\n");
	}
	getchar();
	
}
void List_Find6(LinkedList L)
{
	system("cls");
	if (L)
	{
		int find;
		printf("请输入要查询的数据...\n");
		scanf("%d", &find);
		getchar();
		LinkedList p = L->next;
		while (p)
		{
			if (p->data.num == find)
			{
				printf("已找到...\n");
				break;
			}
			p = p->next;
		}
		if(!p)
			printf("没找到...\n");
	}
	else
	{
		printf("为空链表\n");
	}
	getchar();

}
void List_rollback7(LinkedList& L)
{
	system("cls");
	if (L)
	{
		LinkedList Prev=NULL, Curr=L->next, Next;
		while (Curr)
		{
			Next = Curr -> next;
			Curr->next = Prev;
			Prev = Curr;
			Curr = Next;
		
		}
		L->next  = Prev;
		printf("反转了（\n");
	}
	else
	{
		printf("为空链表\n");
	}
	getchar();

}
void List_Circle8(LinkedList& L)//没有做循环函数，但是可以把List_rollback7函数里面的Curr=L->next改成Curr=L来构成循环函数
{
	system("cls");
	if (L)
	{
		LinkedList fast = L, slow = L;
		while (fast)
		{
			if (fast->next)
				fast = fast->next;
			else
			{
				printf("为非环链表\n");
				break;
			}
			if (fast->next)
				fast = fast->next;
			else
			{
				printf("为非环链表\n");
				break;
			}
				slow = slow->next;
				if (slow == fast)
				{
					printf("为环链表\n");
					break;
				}
		}
	}
	else
	{
		printf("为空链表\n");
	}
	getchar();

}
LinkedList List_Find_Middle9(LinkedList& L)
{
	system("cls");
	if (L)
	{
		LinkedList fast = L, slow = L;
		int i = 1;
		while (fast)
		{
			if (fast->next)
			{
				fast = fast->next;
			}
			else
			{
				break;
			}
			if (fast->next)
			{
				fast = fast->next;
			}
			else
			{
				break;
			}
			slow = slow->next;
			i++;
		}
		printf("第%d个为中间点，已返回该指针！(无数据的头结点也计入数的情况下)\n",i);
		getchar();
		return slow;
	}
	else
	{
		printf("为空链表\n");
	}
	getchar();
	return L;
}
void List_exchange10(LinkedList& L)
{
	system("cls");
	if (L)
	{
		LinkedList Curr = L->next, Next = L->next;
		if (Next)
		{
			ElemType t;
			Next = Next->next;
			while (Next)
			{
				t = Curr->data;
				Curr->data = Next->data;
				Next->data = t;
				if (Next->next)
				{
					if (Next->next->next)
					{
						Next = Next->next->next;
						Curr = Curr->next->next;
					}
					else
						break;
				}
				else
					break;
			}
		}
		printf("交换完成！\n");
	}
	else
	{
		printf("为空链表\n");
	}
	getchar();
}
