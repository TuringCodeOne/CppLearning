#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
typedef int Status;

typedef struct st
{
	char name[30];
	char phone[20];
	struct st *next;
} Friend;

Friend *init();							//初始化
void addTail(Friend *head); //新建
void delTail(Friend *head); //删除
void update(Friend *head);	//修改
void search(Friend *head);	//检索
void output(Friend *head);	//查看

void readFile(Friend *head);	 //读文件
void outputFile(Friend *head); //写文件
void clear(Friend *head);			 //清空

int main()
{
	Friend *HEAD = init();
	int choose;
	while (true)
	{
		printf("*********************************************\n");
		printf("*                    主菜单                 *\n");
		printf("*      [1]查看联系人      [4]更改联系人信息 *\n");
		printf("*      [2]新建联系人      [5]删除联系人     *\n");
		printf("*      [3]查找联系人      [0]退出           *\n");
		printf("*********************************************\n");
		printf("输入数字执行操作：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			output(HEAD);
			break;
		case 2:
			addTail(HEAD);
			break;
		case 3:
			search(HEAD);
			break;
		case 4:
			update(HEAD);
			break;
		case 5:
			delTail(HEAD);
			break;
		case 0:
			outputFile(HEAD);
			clear(HEAD);
			break;
		default:
			printf("输入错误，重新输入！\n");
			break;
		}
		if (choose == 0)
		{
			break;
		}
		getchar();
	}
	return 0;
}

Friend *init()
{
	Friend *head = (Friend *)malloc(sizeof(Friend));
	if (head == NULL)
	{
		printf("----初始化失败！----");
		return 0;
	}
	head->next = NULL;
	readFile(head);
	return head;
}

void readFile(Friend *head)
{
	FILE *fp = fopen("phone.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("phone.txt", "w");
	}
	while (true)
	{
		char name[10];
		char phone[20];
		Friend *tail = head;
		while (tail->next)
		{
			tail = tail->next;
		}
		if (fscanf(fp, "%s%s", name, phone) != EOF)
		{
			Friend *newFriend = (Friend *)malloc(sizeof(Friend));
			if (newFriend == NULL)
			{
				printf("内存出错");
				break;
			}
			strcpy(newFriend->name, name);
			strcpy(newFriend->phone, phone);
			tail->next = newFriend;
			newFriend->next = NULL;
		}
		else
		{
			break;
		}
	}
	fclose(fp);
}

void addTail(Friend *head)
{
	char name[20];
	Friend *newFriend = (Friend *)malloc(sizeof(Friend));
	if (newFriend == NULL)
	{
		printf("----内存出错----");
	}
	Friend *p = head;
	Friend *q = head;
	while (p->next)
	{
		p = p->next;
	}
	printf("\n----填写联系人相关信息---\n");
	bool flag = true;
	while (flag)
	{
		printf("姓名：");
		scanf("%s", name);
		while (q->next)
		{
			if (strcmp(q->next->name, name) != 0)
			{
				flag = false;
			}
			else
			{
				printf("\n----联系人列表中已存在此联系人！请重新录入----\n");
				break;
			}
			q = q->next;
		}
		if (q->next == NULL)
		{
			flag = false;
		}
		strcpy(newFriend->name, name);
	}
	printf("号码：");
	scanf("%s", newFriend->phone);
	p->next = newFriend;
	newFriend->next = NULL;
	printf("----添加联系人成功！----\n\n");
}

void search(Friend *head)
{
	int choose, flag = 0;
	Friend *q = head;
	char array[50];
	while (true)
	{
		printf("\n---------------------------------------------\n");
		printf("+                菜单                       +\n");
		printf("+            [1]根据姓名检索                +\n");
		printf("+            [2]根据号码检索                +\n");
		printf("+            [0]返回上一层                  +\n");
		printf("---------------------------------------------\n");
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			flag = 0;
			printf("姓名：");
			scanf("%s", array);
			while (q->next)
			{
				if (strcmp(q->next->name, array) == 0)
				{
					flag = 1;
					printf("\n----找到该联系人----\n");
					printf("姓名:%-10s号码:%s\n", q->next->name, q->next->phone);
				}
				q = q->next;
			}
			if (flag == 0)
			{
				printf("\n----没有此联系人！----\n");
			}
			q = head;
			break;
		case 2:
			flag = 0;
			printf("号码：");
			scanf("%s", array);
			while (q->next)
			{
				if (strcmp(q->next->phone, array) == 0)
				{
					flag = 1;
					printf("\n----找到该联系人----\n");
					printf("姓名:%s\t 号码:%s\n", q->next->name, q->next->phone);
				}
				q = q->next;
			}
			if (flag == 0)
			{
				printf("\n----没有此联系人！----\n");
			}
			q = head;
			break;
		case 0:
			break;
		default:
			printf("\n----没有此选项，请重新选择！----\n");
			break;
		}
		if (choose == 0)
		{
			break;
		}
		getchar();
	}
}

void output(Friend *head)
{
	int i = 0;
	if (head->next == NULL)
	{
		printf("\n----联系人列表为空！----\n\n");
	}
	else
	{
		printf("\n----所有联系人信息如下----\n");
		while (head->next)
		{
			printf("姓名:%-10s\t 号码:%s\n", head->next->name, head->next->phone);
			head = head->next;
			i++;
		}
		printf("\n");
	}
}

void update(Friend *head)
{
	bool flag = true;
	Friend *q = head;
	char name[20];
	printf("\n请输入要修改联系人的姓名：");
	scanf("%s", name);
	while (q->next)
	{
		if (strcmp(q->next->name, name) == 0)
		{
			q = q->next;
			break;
		}
		else
		{
			printf("\n----没有此联系人！----\n");
			flag = false;
			break;
		}
	}
	while (flag)
	{
		printf("\n---------------------------------------------\n");
		printf("+                菜单                       +\n");
		printf("+  [1]更改姓名  [2]更改号码  [0]返回上一层  +\n");
		printf("---------------------------------------------\n");
		printf("请选择：");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			char array[20];
			printf("请输入新的姓名：");
			scanf("%s", array);
			strcpy(q->name, array);
			printf("\n----修改成功！----\n");
			break;
		case 2:
			printf("请输入新号码：");
			scanf("%s", array);
			strcpy(q->phone, array);
			printf("\n----修改成功！----\n");
			break;
		case 0:
			break;
		default:
			printf("\n----没有此选项，请重新选择！----\n");
			break;
		}
		break;
	}
}

void outputFile(Friend *head)
{
	FILE *fp = fopen("phone.txt", "w+");
	if (fp == NULL)
	{
		printf("\n----没有找到文件！----\n");
	}
	while (head->next)
	{
		fprintf(fp, "%-20s%s\n", head->next->name, head->next->phone);
		head = head->next;
	}
	fclose(fp);
}

void delTail(Friend *head)
{
	int flag = 0;
	Friend *p = head;
	char name[20];
	printf("\n请输入要删除联系人的姓名：");
	scanf("%s", name);
	while (p->next)
	{
		if (strcmp(p->next->name, name) == 0)
		{
			flag = 1;
			Friend *temp = p->next;
			p->next = temp->next;
			free(temp);
			printf("\n----删除成功！----\n\n");
			break;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		printf("\n----没有找到此联系人！----\n\n");
	}
}

void clear(Friend *head)
{
	Friend *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
