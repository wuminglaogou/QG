#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��ӡ
void print(int arr[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
		
	}
	printf("\n");
}
//�鲢����
void merge(int arr[], int tempArr[], int left,int mid, int right)
{
	int l_first = left;
	int r_first = mid+1;
	int pos = left;
	while (l_first<=mid&&r_first<=right)
	{
		if (arr[l_first] < arr[r_first])
			tempArr[pos++] = arr[l_first++];
		else
			tempArr[pos++] = arr[r_first++];
	}
	while (l_first <= mid)
	{
		tempArr[pos++] = arr[l_first++];
	}
	while (r_first <= right)
	{
		tempArr[pos++] = arr[r_first++];
	}
	while (left<=right)
	{
		arr[left] = tempArr[left];
		left++;
	}
}

void msort(int arr[], int tempArr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		msort(arr, tempArr, left, mid);
		msort(arr, tempArr, mid+1, right);
		merge(arr, tempArr, left, mid, right);
	}


}
void merge_sort(int arr[], int n)
{
	//printf("\n�鲢����\n");
	int* temp_arr = (int*)malloc(n * sizeof(int));
	if(temp_arr)
	{
		msort(arr, temp_arr, 0, n - 1);
		free(temp_arr);
	}
	else
	{
		printf("\n����ʧ��\n");
	}

}
//��������
void insert_sort(int arr[], int n)
{
	//printf("\n��������\n");
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j>=0&&arr[j]>key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
//��������
void conut_sort(int arr[], int n)
{
	//printf("\n��������\n");
	if (n < 1)
		return;
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	int* count = (int*)malloc(sizeof(int) * (max + 1));
	for (int i = 0; i < max + 1; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[arr[i]]++;
	for (int i = 1; i < max + 1; i++)
		count[i] += count[i - 1];
	int* output = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}
//��������
int partition(int arr[], int left, int right)
{
	int temp = 0;
	int pivot = arr[right];
	int i = left;
	for (int j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
		}
	}
	temp = arr[right];
	arr[right] = arr[i];
	arr[i] = temp;
	return i;
}
void qsort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = partition(arr, left, right);
		qsort(arr, left, mid - 1);
		qsort(arr, mid + 1, right);
	}
}
void quick_sort(int arr[], int n)
{
	//printf("\n��������\n");

	qsort(arr,0 ,n - 1);
}
//��������
void radix_sort(int arr[], int n)
{
	//printf("\n��������\n");
	int  max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	int radix = 1;//���ڼ���λ��
	while (max>0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			bucket[arr[i] / radix % 10]++;
		}
		int* tmp = (int*)malloc(sizeof(int) * n);
		for (int i = 1; i <= 9; i++)
		{
			bucket[i] = bucket[i] + bucket[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			tmp[bucket[arr[i] / radix % 10] - 1] = arr[i];
			bucket[arr[i] / radix % 10]--;
		}
		for (int i = 0; i < n; i++)
		{
			arr[i] = tmp[i];
		}
		radix = radix * 10;
		max = max / 10;
	}
}
//��������
void birth_arr(int arr[], int n)
{
	//printf("\n��ʼ����\n");
	FILE* fp;
	fp = fopen("number.txt", "w");
	if (fp == NULL)
	{
		printf("can not open the file");
		exit (0);
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);
}
//ð�������Ż� 
void effervescence_sort(int arr[],int len)
{
	int i = 0, j = 0, n = 0, flag = 0, pos = 0, k = len - 1,temp=0;
	for (i = 0; i < len - 1; i++)
	{
		pos = 0;
		flag = 0;
		for (j = n; j < k; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
				pos = j;
			}

		}
		if (flag == 0)
			break;
		k = pos;
		for (j = k; j > n; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = 1;
			}
		}
		n++;
		if (flag == 0)
			break;

	}
}

void choose_way(int arr[], int n)
{
	int choose = 0;
	printf("��ѡ������ʽ\n1.����\n2.�鲢\n3.����\n4.����\n5.����\n6.ð�������Ż� \n����.�˳�\n");
	scanf("%d", &choose);
	getchar();
	printf("��ȴ�...\n");
	clock_t start, end;
	//printf("\nԭ����:\n");
	//print(arr, n);
	start = clock();
	switch (choose)
	{
	case 1:insert_sort(arr, n); break;
	case 2:merge_sort(arr, n); break;
	case 3:quick_sort(arr, n); break;
	case 4:conut_sort(arr, n); break;
	case 5:radix_sort(arr, n); break;
	case 6:effervescence_sort(arr, n); break;
	default:return; break;
	}
	//merge_sort(arr, n);
	//insert_sort(arr, n);
	//conut_sort(arr, n);
	//quick_sort(arr, n);
	//radix_sort(arr, n);
	end = clock();
	print(arr, n);
	printf("\n\n����ʱ��Ϊ%.0lfms", (double)(end - start));
	getchar();
}
//�Դ���С���ݽ�������
void sort100_1000k()
{
	FILE* fp;
	fp = fopen("number.txt", "w");
	if (fp == NULL)
	{
		printf("can not open the file");
		exit(0);
	}
	int choose = 0, n = 100;
	double time = 0;
	printf("��ѡ������ʽ\n1.����\n2.�鲢\n3.����\n4.����\n5.����\n6.ð�������Ż� \n����.�˳�\n");
	scanf("%d", &choose);
	getchar();
	clock_t start, end;
	int arr[100];
	birth_arr(arr, 100);
	printf("��ȴ�...\n");
	for (int i = 1; i <= 1000*100; i++)
	{
	   start = clock();
		switch (choose)
		{
		case 1:insert_sort(arr, n); break;
		case 2:merge_sort(arr, n); break;
		case 3:quick_sort(arr, n); break;
		case 4:conut_sort(arr, n); break;
		case 5:radix_sort(arr, n); break;
		case 6:effervescence_sort(arr, n); break;
		default:return; break;
		}
	end = clock();
	time += (double)(end - start);
		//print(arr, n);
	}
	printf("\n\n����ʱ��Ϊ%.0lfms", time);
	fclose(fp);
}
void read_file(int arr[])
{
	
	int i=0,choose = 0, n = 100;
	double time = 0;
	clock_t start, end;
	FILE* fp;
	fp = fopen("number.txt", "r");
	if (fp == NULL)
	{
		printf("can not open the file");
		exit(0);
	}
	while (fscanf(fp, "%d", &arr[i]) != EOF)
		i++;
	//print(arr, i);
	printf("��ȡ���\n");
	printf("��ѡ������ʽ\n1.����\n2.�鲢\n3.����\n4.����\n5.����\n6.ð�������Ż� \n����.�˳�\n");
	scanf("%d", &choose);
	getchar();
	printf("��ȴ�...\n");
	start = clock();
	switch (choose)
	{
	case 1:insert_sort(arr, i); break;
	case 2:merge_sort(arr, i); break;
	case 3:quick_sort(arr, i); break;
	case 4:conut_sort(arr, i); break;
	case 5:radix_sort(arr, i); break;
	case 6:effervescence_sort(arr, i); break;
	default:return; break;
	}
	end = clock();
	time += (double)(end - start);
	print(arr, i);
	printf("\n\n����ʱ��Ϊ%.0lfms", time);
	fclose(fp);
}
void color_sort()
{
	int arr[] = { 1,2,1,0,2,0,0 }, n = 7,p0=0,p1=0,p2=6,temp;//p0ָ��0λ��,p2ָ��2λ��,p1���б���
	for (p1 = 1;p1<=p2; p1++)
	{
		
		if (p0 >= p2)
			break;
		while (arr[p1]!=1)
		{
		if (arr[p1] == 0)
		{
			temp = arr[p0];
			arr[p0] = arr[p1];
			arr[p1] = temp;
			p0++;
		}
	    if (arr[p1] == 2)
		{
			temp = arr[p2];
			arr[p2] = arr[p1];
			arr[p1] = temp;
			p2--;
		}
	    }
		
	}
	printf("�������:\n");
	print(arr, n);
}
void disordered_sort()
{
	int arr[] = { 5,2,8,4,3,7,6 }, n = 7;
	quick_sort(arr, n);
	printf("����С����%d", arr[2]);

}
int arr1[50000], arr2[100000], arr3[200000], arr4[100];
int main()
{
	char choose = 0;
	do
	{
		system("cls");
	printf("��ѡ�񷽷���\n1.����50000������\n2.����100000��\n3.����200000������\n4.����100������*1000k��\n5.��ȡ�������ļ�\n6.��ɫ����\n7.�ҵ��������е���С����\n");
	scanf("%c", &choose);
	getchar();
	switch (choose)
	{
	case '1': birth_arr(arr1, 50000); choose_way(arr1, 50000); break;
	case '2':birth_arr(arr2, 100000); choose_way(arr2, 100000); break;
	case '3':birth_arr(arr3, 200000); choose_way(arr3, 200000); break;
	case'4':sort100_1000k(); break;
	case '5':read_file(arr3); break;
	case'6':color_sort(); break;
	case '7':disordered_sort(); break;
	default:break;
	}
	getchar();
	} while ('1'<=choose&&choose<='7');
}

