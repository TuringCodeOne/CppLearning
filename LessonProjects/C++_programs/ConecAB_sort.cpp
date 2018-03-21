#include<iostream>
#include<stdlib.h>
using namespace std;
#define INITSIZE 100
typedef int ElemType;

typedef struct
{
	ElemType *data;
	int length;
	int listsize;
}sqlist;

int initlist(sqlist *L)
{
	L->data = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);
	if (L->data == NULL)
		return 0;
	L->length = 0;
	L->listsize = INITSIZE;
}

int insert(sqlist *L, int i, ElemType x)
{
	int j;
	if (i<1 || i>L->length + 1)
		return 0;
	if (L->length == L->listsize)
	{
		L->data = (ElemType *)realloc(L->data, (L->listsize + 1) * sizeof(ElemType));
		if (L->data == NULL)
			return 0;
		L->listsize++;
	}
	for (j = L->length - 1; j >= i - 1; j--)
		L->data[j + 1] = L->data[j];
	L->data[i - 1] = x;
	L->length++;
	return true;
}

bool insert(sqlist *L, int i)
{
	if (i < 1)
		return 0;
	L->length = i;
	if (i >= INITSIZE)
	{
		L->data = (ElemType *)realloc(L->data, (L->listsize + i - INITSIZE) * sizeof(ElemType));
		if (L->data == NULL)
			return 0;
		L->listsize += i - INITSIZE;
	}
	for (int j = 0; j < i; j++)
		cin >> L->data[j];
}

void output_list(sqlist *L)
{
	int i;
	for (i = 0; i < L->length; i++)
		printf_s("%-5d", L->data[i]);
	cout << endl;
}

void select_sort(sqlist *L)
{
	int i, j, k;
	int temp;

	for (i = 0; i < L->length - 1; i++)
	{
		k = i;
		for (j = i + 1; j < L->length; j++)
		{
			if (L->data[j] > L->data[k])
				k = j;
		}
		if (i != k)
		{
			temp = L->data[i];
			L->data[i] = L->data[k];
			L->data[k] = temp;
		}
	}
}

int link(sqlist *L1, sqlist *L2, sqlist *L)
{
	int i, j;
	initlist(L);
	L->length = L1->length + L2->length;
	if (L->length > INITSIZE)
	{
		L->data = (ElemType *)realloc(L->data, (L->length - INITSIZE) * sizeof(ElemType));
		if (L->data == NULL)
			return 0;
		L->listsize += L->length - INITSIZE;
	}
	for (i = 0; i < L1->length; i++)
		L->data[i] = L1->data[i];
	for (j = 0; j < L2->length; j++, i++)
		L->data[i] = L2->data[j];
}

int merge(sqlist *L1, sqlist *L2, sqlist *L)
{
	int i = 0;
	int *p = L1->data, *q = L2->data;
	initlist(L);
	L->length = L1->length + L2->length;
	if (L->length > INITSIZE)
	{
		L->data = (ElemType *)realloc(L->data, (L->length - INITSIZE) * sizeof(ElemType));
		if (L->data == NULL)
			return 0;
		L->listsize += L->length - INITSIZE;
	}
	while (true)
	{
		if (p == L1->data + L1->length || q == L1->data + L1->length)
			break;
		if (*p > *q)
		{
			L->data[i++] = *p;
			p++;
		}
		else {
			L->data[i++] = *q;
			q++;
		}
	}
	if (L->data[i - 1] == L1->data[L1->length - 1])
	{
		while (i != L->length)
		{
			L->data[i++] = *q;
			q++;
		}

	}
	else {
		while (i != L->length)
		{
			L->data[i++] = *p;
			p++;
		}
	}
}



int main()
{
	int a, b;
	sqlist *A = (sqlist *)malloc(sizeof(sqlist));
	sqlist *B = (sqlist *)malloc(sizeof(sqlist));
	sqlist *C = (sqlist *)malloc(sizeof(sqlist));
	sqlist *D = (sqlist *)malloc(sizeof(sqlist));
	initlist(A);
	initlist(B);
	cout << "Please give the length of linked chart A and B: ";
	cin >> a >> b;
	cout << "Please enter the " << a << " value of chart A in sequence: " << endl;
	insert(A, a);
	cout << "Please enter the " << b << " value of chart B in sequence: " << endl;
	insert(B, b);
	link(A, B, C);
	select_sort(C);
	cout << "(By link)The order of new linked chart from big to small is:" << endl;
	output_list(C);

	cout << "(By merge)The order of new linked chart from big to small is:" << endl;
	select_sort(A);
	select_sort(B);
	merge(A, B, D);
	output_list(D);
	return 0;
}

