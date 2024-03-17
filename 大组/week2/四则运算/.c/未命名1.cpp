#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct StackNode {
	char data;
	float num;
	struct StackNode* Next;
}StackNode, *LinkStack;

LinkStack S = NULL;
LinkStack Count = NULL;
LinkStack Count0;


void push(LinkStack& S, char e)
{
	LinkStack P = (LinkStack)malloc(sizeof(StackNode));
	P->data = e;
	P->Next = S;
	S = P;
}
void push_num(LinkStack& S, float num)
{
	LinkStack P = (LinkStack)malloc(sizeof(StackNode));
	P->num = num;
	P->Next = S;
	S = P;
}
char  pop(LinkStack& S)
{
	if (S != NULL)
	{
		char e = S->data;
		LinkStack P= S;
		S = S->Next;
		free(P);
		return e;
	}
	else
	{
		printf("栈已经为空！\n");
		return '\0';
	}
}
float pop_num(LinkStack& S)
{
	if (S != NULL)
	{
		float num = S->num;
		LinkStack P = S;
		S = S->Next;
		free(P);
		return num;
	}
	else
	{
		printf("栈已经为空！\n");
		return '\0';
	}
}
char get_top(LinkStack& S)
{
	if (S)
	{
		char e = S->data;
		return e;
	}
	else
	{
		printf("栈已经为空aaa！\n");
		return '\0';
	}
}
float compara(char e)
{
	if (e == '+' || e == '-')
		return 1;
	if (e == '*' || e == '/')
		return 2;
}
void show(LinkStack S)
{
	LinkStack p = S;
	printf("\n------\n");
	while (p)
	{
	printf("%c\n", p->data);
	p = p->Next;
	}
	printf("------\n");

}
void all(char del)
{
	if (del == '+')
	{
		float all = pop_num(Count) + pop_num(Count);
		push_num(Count, all);
	}
	if (del == '*')
	{
		float all = pop_num(Count) * pop_num(Count);
		push_num(Count, all);
	}
	if (del == '/')
	{
		float num1 = pop_num(Count), num2 = pop_num(Count);
		float all = num2 / num1;
		push_num(Count, all);
	}
	if (del == '-')
	{
		float num1 = pop_num(Count), num2 = pop_num(Count);
		float all = num2 - num1;
		push_num(Count, all);
	}
}
int check(char s[])
{
	
	LinkStack use_cehck=NULL;
	for (int i = 0; i < strlen(s); i++)
	{
	
		
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '（' || s[i] == '）'||s[i]=='（'||s[i]=='）'||s[i]=='('))
		{
			return 0;
		}
		if (s[i] == '(' || s[i] == '（')
		{
			push(use_cehck, s[i]);

		}
		if (s[i] == ')' || s[i] == '）')
		{
			if (use_cehck != NULL)
				pop(use_cehck);
			else
			{
				return 0;
			}
		}
		if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '.')
		{
			if (i == 0)
			{

				return 0;

			}
			if (i == strlen(s) - 1)
			{

				return 0;

			}
			if ((i != 0 && i < strlen(s) - 1) && (s[i - 1] == '(') || (s[i - 1] == '（'))
			{

				return 0;

			}
			if ((i != 0 && i < strlen(s) - 1) && (s[i + 1] == ')') || (s[i + 1] == '）'))
			{

				return 0;
			}
			if (i > 0 && i < strlen(s) - 1 && (s[i + 1] == '+' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '+' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '.'))
			{

				return 0;
			}
		}
		if (s[i] == '-'||s[i]=='-')
			{
				if (i == strlen(s)- 1)
					return 0;

				if ((s[0] == '-' && s[1] == '-') || ((s[0] == '-' && s[1] == '-')))
					return 0;
				if (i != 0 && i < strlen(s)-1 && (s[i + 1] == ')' || s[i + 1] == '）'))
					return 0;
				if (i != 0 && i < strlen(s) - 1 && (s[i + 1] == '-' || s[i + 1] == '-') && (s[i - 1] == '-' || s[i - 1] == '-'))
					return 0;
		}
		
	}
	if (use_cehck != NULL)
	{
		return 0;
	}
	return 1;
}
int main()
{
	int begin=0;
	do
	{
	printf("开始请输入1\n");
	scanf("%d",&begin);
	if(begin!=1)
	break;
   getchar();
	char str[100];
	char str_new[100];
	bool str_right;
	int x = 0;
	int right=0;
	do
	{
	printf("请合理输入求值表达式(只能输入英文括号)\n");   
	scanf("%s", str);
	getchar();
	right=check(str);
	} while (right==0);

	for (int i = 0; i < strlen(str); i++)
	{
		//show(S);
	
		if (str[i] == '(' || str[i] == '（')
		{
			push(S, str[i]);
		}
		if (str[i] == ')' || str[i] == '）')
		{
			char top = get_top(S);
			while ((top!='(' ))
			{
				char e = pop(S);
				all(e);
				str_new[x] = e;
				x++;
				str_new[x] = '\0';
				top = get_top(S);
			}
	
			if (top == '(')
			{
				pop(S);
			}
		}
		if (str[i] == '+' || (str[i] == '-'&&i!=0&&str[i-1]>='0'&&str[i-1]<='9'||str[i-1]==')') || str[i] == '*' || str[i] == '/')
		{
			if (S == NULL)
			{
				push(S, str[i]);
				continue;
			}
			if (get_top(S) == '(')
			{
				push(S, str[i]);
				continue;
			}
			while (compara(get_top(S))>=compara(str[i]))
			{
				char del = pop(S);
				all(del);
				str_new[x] = del;
				x++;
				str_new[x] = '\0';
				if (S==NULL)
					break;
				if (get_top(S) == '(')
					break;
			}
			push(S, str[i]);
		
		}
		else
		{

			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '-')
			{
				char num[10];
				int index = 0;
				num[index++] = str[i];
				str_new[x] = str[i];
				x++;
				str_new[x] = '\0';
				int j;
				for (j = 1; str[i + j] != '\0'; j++)
				{
					if ((str[i + j] >= '0' && str[i + j] <= '9') || str[i + j] == '.')
					{
					
						num[index++] = str[i + j];
						str_new[x] = str[i + j];
						x++;
						str_new[x] = '\0';

					}
					else
					{
						break;
					}
				}
				num[index++] = '\0';
				float value = atof(num);
				push_num(Count, value);
				i += j - 1;
			}
		}
	}
	while (S!=NULL)
	{
		all(S->data);
		S = S->Next;
	}

		printf("\n\n=%f\n\n",pop_num(Count) );
			getchar();
	}while(begin==1);
}


