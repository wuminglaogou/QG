#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct Elemtype
{
	int num;
};
typedef struct DuLnode {
	Elemtype data;
	struct DuLnode* prior, * next;
}DuLnode, * DuLinkList;
DuLinkList L;
void Menu()
{
	void CreateList1(DuLinkList & L);
	void Top_Insert_List3(DuLinkList & L);
	void List_Print6(DuLinkList L);
	void Bottom_Insert_List4(DuLinkList & L);
	void Distroy_List2(DuLinkList & L);
	void Delect_List5(DuLinkList & L);
	int choose;
	do
	{
		system("cls");
		printf("\n\n单链表ADT\n\n");
		printf("1.创建空链表\n2.销毁链表\n3.头插法插入数据\n4.尾插法插入数据\n5.删除数据\n6.遍历链表\n其他.删去\n\n");
		printf("请输入对应数据\n\n");
		scanf("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1:CreateList1(L); break;
		case 2:Distroy_List2(L); break;
		case 3:Top_Insert_List3(L); break;
		case 4:Bottom_Insert_List4(L); break;
		case 5:Delect_List5(L); break;
		case 6:List_Print6(L); break;

		default:break;
		}
	} while (1 <= choose && choose <=6);
}
int main()
{
	Menu();
	getchar();
}
void CreateList1(DuLinkList& L)
{
	system("cls");
	L = (DuLinkList)malloc(sizeof(DuLnode));//制作不储存数据的头结点
	L->next = NULL;
	L->prior = NULL;
	printf("\n创建链表成功！\n");
	getchar();
}
void Distroy_List2(DuLinkList& L)
{
	system("cls");
	if (L)
	{
		DuLinkList p = L->next;
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
void Top_Insert_List3(DuLinkList &L)
{
	system("cls");
	if (L)
	{
		DuLinkList insert = (DuLinkList)malloc(sizeof(DuLnode));
		printf("请输入数据\n");
		scanf("%d", &insert->data.num);
		getchar();
		insert->next = L->next;
		if(L->next)
		L->next->prior = insert;
		L->next = insert;
		insert->prior = L;
		printf("输入数据成功！\n");
	}
	else
	{
		printf("为空链表\n");
	}
	getchar();
}
void Bottom_Insert_List4(DuLinkList& L)
{
	system("cls");
	if (L)
	{
		DuLinkList insert = (DuLinkList)malloc(sizeof(DuLnode));
		DuLinkList p = L;
		printf("请输入数据:\n");
		scanf("%d", &insert->data.num);
		getchar();
		while (p->next)
		{
			p = p->next;
		}
		p->next = insert;
		insert->next = NULL;
		insert->prior = p;
		printf("输入数据成功！\n");
	}
	else
	{
		printf("为空链表\n");
	}
	getchar();
}
void List_Print6(DuLinkList L)
{
	system("cls");
	if (L)
	{
		DuLinkList p = L->next;
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
void Delect_List5(DuLinkList& L)
{
	system("cls");
	if (L)
	{
		int del;
		printf("输入将删除的数据...\n");
		scanf("%d", &del);
		getchar();
		DuLinkList p = L->next, q = L;
		while (p&&p->data.num!=del)
		{
			p = p->next;
			q = q->next;
		}
		if (p)
		{
			q->next = p->next;
			if (p->next)
				p->next->prior = q;
			free(p);
			printf("删除成功!\n");
		}
		else
		{
			printf("没找到\n");
		}
		
	}
	else
	{
		printf("为空链表！\n");
	}
	getchar();
}

