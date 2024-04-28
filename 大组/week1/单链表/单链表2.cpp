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
	LinkedList L;//ͷָ��
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
	printf("\n\n������ADT\n\n");
	printf("1.����������\n2.��������\n3.����ڵ�\n4.ɾ���ڵ�\n5.��������\n6.��������\n7.��ת����\n8.�ж������Ƿ�ɻ�\n9.�ҵ���������е�\n10.���������ż����\n����.�˳�\n\n");
	printf("�������Ӧ����\n\n");
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
	L = (LNode*)malloc(sizeof(LNode));//����ͷ�ڵ㣬����������
	L->next = NULL;
	printf("\n��������ɹ���\n");
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
		printf("���ٳɹ�\n");
	}
	else
	{
		printf("Ϊ������\n");
	}
	getchar();

}
void Delect_List4(LinkedList& L)
{
	system("cls");
	if (L)
	{
		int del;
		printf("���뽫ɾ��������...\n");
		scanf("%d", &del);
		getchar();
		LinkedList p = L->next,q=L;
		while (p&&p->data.num!=del)
		{
			q = p;
			p = p->next;
		}
		if (!p)
			printf("û�ҵ�������\n");
		else
		{
			q->next = p->next;
			free(p);
			printf("ɾ���ɹ�!\n");
		}
	}
	else
	{
		printf("Ϊ������\n");
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
	printf("����������:\n");
	scanf("%d", &insert->data.num);
	getchar();
	while (p->next)
	{
		p = p->next;
	}
	p->next = insert;
	insert->next = NULL;
	printf("�������ݳɹ���\n");
    }
	else
	{
		printf("Ϊ������\n");
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
void List_Find6(LinkedList L)
{
	system("cls");
	if (L)
	{
		int find;
		printf("������Ҫ��ѯ������...\n");
		scanf("%d", &find);
		getchar();
		LinkedList p = L->next;
		while (p)
		{
			if (p->data.num == find)
			{
				printf("���ҵ�...\n");
				break;
			}
			p = p->next;
		}
		if(!p)
			printf("û�ҵ�...\n");
	}
	else
	{
		printf("Ϊ������\n");
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
		printf("��ת�ˣ�\n");
	}
	else
	{
		printf("Ϊ������\n");
	}
	getchar();

}
void List_Circle8(LinkedList& L)//û����ѭ�����������ǿ��԰�List_rollback7���������Curr=L->next�ĳ�Curr=L������ѭ������
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
				printf("Ϊ�ǻ�����\n");
				break;
			}
			if (fast->next)
				fast = fast->next;
			else
			{
				printf("Ϊ�ǻ�����\n");
				break;
			}
				slow = slow->next;
				if (slow == fast)
				{
					printf("Ϊ������\n");
					break;
				}
		}
	}
	else
	{
		printf("Ϊ������\n");
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
		printf("��%d��Ϊ�м�㣬�ѷ��ظ�ָ�룡(�����ݵ�ͷ���Ҳ�������������)\n",i);
		getchar();
		return slow;
	}
	else
	{
		printf("Ϊ������\n");
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
		printf("������ɣ�\n");
	}
	else
	{
		printf("Ϊ������\n");
	}
	getchar();
}
