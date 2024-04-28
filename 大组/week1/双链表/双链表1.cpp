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
		printf("\n\n������ADT\n\n");
		printf("1.����������\n2.��������\n3.ͷ�巨��������\n4.β�巨��������\n5.ɾ������\n6.��������\n����.ɾȥ\n\n");
		printf("�������Ӧ����\n\n");
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
	L = (DuLinkList)malloc(sizeof(DuLnode));//�������������ݵ�ͷ���
	L->next = NULL;
	L->prior = NULL;
	printf("\n��������ɹ���\n");
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
		printf("���ٳɹ�\n");
	}
	else
	{
		printf("Ϊ������\n");
	}
	getchar();
}
void Top_Insert_List3(DuLinkList &L)
{
	system("cls");
	if (L)
	{
		DuLinkList insert = (DuLinkList)malloc(sizeof(DuLnode));
		printf("����������\n");
		scanf("%d", &insert->data.num);
		getchar();
		insert->next = L->next;
		if(L->next)
		L->next->prior = insert;
		L->next = insert;
		insert->prior = L;
		printf("�������ݳɹ���\n");
	}
	else
	{
		printf("Ϊ������\n");
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
		printf("����������:\n");
		scanf("%d", &insert->data.num);
		getchar();
		while (p->next)
		{
			p = p->next;
		}
		p->next = insert;
		insert->next = NULL;
		insert->prior = p;
		printf("�������ݳɹ���\n");
	}
	else
	{
		printf("Ϊ������\n");
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
			printf("��%d��������%d\n", i, p->data.num);
			p = p->next;
		}
		printf("���������\n");
	}
	else
	{
		printf("Ϊ������\n");
	}
	getchar();
}
void Delect_List5(DuLinkList& L)
{
	system("cls");
	if (L)
	{
		int del;
		printf("���뽫ɾ��������...\n");
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
			printf("ɾ���ɹ�!\n");
		}
		else
		{
			printf("û�ҵ�\n");
		}
		
	}
	else
	{
		printf("Ϊ������\n");
	}
	getchar();
}

