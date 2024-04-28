#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct Qnode {
    void *data;
    char type;
    struct Qnode* next;
}Qnode,*QuenePtr;
typedef struct Lqueue
{
    Qnode* front;
    Qnode* rear;
    int length;
}Lqueue;
Lqueue S;
 
void InitQnode(Lqueue &S)
{
    system("cls");
    S.front = (QuenePtr)malloc(sizeof(Qnode));
    S.front->next = NULL;
    S.rear = S.front;
    getchar();
}
void  DistroyQuenePtr(Lqueue& S)
{
    system("cls");
    if (S.front != NULL)
    {
        Qnode *p=S.front->next;
        while (p)
        {
            free(S.front);
            S.front = p;
            p = p->next;
        }
        printf("�Ѵݻ�����\n");
        S.front = NULL;
        getchar();
    }
    else
    {
        printf("��������\n");
        getchar();
    }
}
void get_int(Lqueue& S)
{
    system("cls");
    if (S.front != NULL)
    {
        int add;
        printf("������Ҫ�����ֵ\n");
        scanf("%d", &add);
        getchar();
        Qnode* p = (QuenePtr)malloc(sizeof(Qnode));
        (p->data) = (void*)add;
        p->type = 'i';
        p->next = NULL;
        S.rear->next = p;
        S.rear = p;
        printf("�������ݳɹ���\n");
    }
    else
    {
        printf("��������\n");
    }
        getchar();
}
void get_float(Lqueue& S)
{
    system("cls");
    if (S.front != NULL)
    {
        float s;
        float *add=&s;
        printf("������Ҫ�����ֵ\n");
        scanf("%f", add);
        getchar();
        Qnode* p = (QuenePtr)malloc(sizeof(Qnode));
        (p->data) = (void*)add;
        p->type = 'f';
        p->next = NULL;
        S.rear->next = p;
        S.rear = p;
        printf("�������ݳɹ���\n");
    }
    else
    {
        printf("��������\n");
    }
    getchar();
}
void get_char(Lqueue& S)
{
    system("cls");
    if (S.front != NULL)
    {
        char s;
        char* add = &s;
        printf("������Ҫ�����ֵ\n");
        scanf("%c", add);
        getchar();
        Qnode* p = (QuenePtr)malloc(sizeof(Qnode));
        (p->data) = (void*)add;
        p->type = 'c';
        p->next = NULL;
        S.rear->next = p;
        S.rear = p;
        printf("�������ݳɹ���\n");
    }
    else
    {
        printf("��������\n");
    }
    getchar();
}
void del(Lqueue& S)
{
    system("cls");
    if (S.front != NULL)
    {
        if (S.front->next != NULL)
        {
            QuenePtr p = S.front->next;
            S.front->next = p->next;
            if (p == S.rear)
                S.rear = S.front;
            free(p);
            printf("ɾ���ɹ���\n");
        }
        else
        {
            printf("�����Ѿ�Ϊ��");
        }

    }
    else
    {
        printf("��������\n");
    }
        getchar();
}
void print(Lqueue S)
{
    int i = 0;
    system("cls");
    if (S.front != NULL)
    {
        printf("������Ϊ:\n");
        QuenePtr p = S.front->next;
        while (p)
        {
            if (p->type == 'i')
            printf("%d ", (p->data));
            if (p->type == 'f')
            printf("%f ", *(float *)(p->data));
            if (p->type == 'c')
                printf("%c ", *(char*)(p->data));
            p = p->next;
            i++;
        }
        printf("\n����Ϊ%d\n", i);
    }
    else
    {
        printf("��������\n");
    }
    getchar();
}




int main()
{
    S.front = NULL;
    int choose;
    do
    {
    system("cls");
    printf("1.����������\n2.��������\n3.����ڵ�(int)\n4.����ڵ�(float)\n5.����ڵ�(char)\n6.ɾ���ڵ�\n7.��������+�鿴����\n����.�˳�\n\n");
    scanf("%d", &choose);
    getchar();
    switch (choose)
    {
    case 1:InitQnode(S); break;
    case 2:DistroyQuenePtr(S); break;
    case 3:get_int(S); break;
    case 4:get_float(S); break;
    case 5:get_char(S); break;
    case 6:del(S); break;
    case 7:print(S); break;
    default:
        break;
    }
    } while (choose>=1&&choose<=7);
    getchar();
}