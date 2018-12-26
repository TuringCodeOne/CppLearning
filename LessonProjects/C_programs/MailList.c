#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE  1

typedef int ElemType;
typedef int Status;


typedef struct st
{
	char num[20];
	char name[30];
	char telephone[20];
	char address[50];
	char email[30];
	struct st *next;
}Friend;


Friend *init();    //初始化
Status addTail(Friend *head);      //新建联系人
Status readFile(Friend *head);    //读文件
Status delete(Friend *head);    //删除
Status update(Friend *head);    //修改联系人信息

void output(Friend *head);    //输出到屏幕
void search(Friend *head);    //查找
void outputFile(Friend *head);    //输出到文件
void clear(Friend **head);    //清空
void insertSort(Friend *head);  //根据学号排序


int main()
{
	Friend *HEAD = init();
	int choose;
	while (1)
	{
		printf("*********************************************\n");
		printf("*                    主菜单                 *\n");
		printf("* 输入数字执行操作：                        *\n");
		printf("*      1:查看联系人        4.更改联系人信息 *\n");
		printf("*      2:新建联系人        5.删除联系人     *\n");
		printf("*      3:查找联系人        0:退出           *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("\n\n");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			insertSort(HEAD);
			output(HEAD);
			break;
		case 2:
			addTail(HEAD);
			outputFile(HEAD);
			break;
		case 3:
			search(HEAD);
			break;
		case 4:
			update(HEAD);
			outputFile(HEAD);
			break;
		case 5:
			delete(HEAD);
			outputFile(HEAD);
			break;
		case 0:
			clear(&HEAD);
			break;
		default:
			printf("输入错误，重新输入！\n");
			break;
		}
		if (choose == 0) {
			break;
		}
		getchar();
	}
	return 0;
}


Friend *init()
{
	Friend *head = (Friend *)malloc(sizeof(Friend));
	if (head == NULL) {
		printf("初始化失败！");
		return NULL;
	}
	head->next = NULL;
	return head;
}

Status readFile(Friend *head)
{
	int flag;
	Friend *newfriend, *p;
	FILE *fp;
	p = head;
	fp = fopen("tong_xun_lu_a.txt", "r");

	fscanf(fp, "%d", &flag);
	while (flag != 0)
	{
		p = head;
		newfriend = (Friend *)malloc(sizeof(Friend));
		if (newfriend == NULL)
		{
			return FALSE;
		}

		while (p->next)
		{
			p = p->next;
		}

		newfriend->next = NULL;
		p->next = newfriend;

		fscanf(fp, "%s%s%s%s%s", newfriend->num, newfriend->name, newfriend->telephone,
			newfriend->address, newfriend->email);
		fscanf(fp, "%d", &flag);
	}

	fclose(fp);
	return TRUE;
}

Status addTail(Friend *head)
{
	Friend *p;
	Friend *newfriend = (Friend *)malloc(sizeof(Friend));
	if (newfriend == NULL)
	{
		return FALSE;
	}
	p = head;
	while (p->next)
	{
		p = p->next;
	}
	printf("\n\n请输入新建联系人的学号，姓名，电话号码，地址，email：\n\n\n\n");
	scanf("%s%s%s%s%s", newfriend->num, newfriend->name, newfriend->telephone, newfriend->address, newfriend->email);
	newfriend->next = p->next;
	p->next = newfriend;
	printf("添加联系人成功！\n");
	return TRUE;
}

void search(Friend *head)
{
	int choose, flag = 0;
	Friend *q = head;
	char array[50];
	while (1)
	{
		printf("**********************************************\n");
		printf("*   请选择查找方式：                         *\n");
		printf("*      1:根据姓名查找       3.根据地址查找   *\n");
		printf("*      2:根据号码查找       4.根据email查找  *\n");
		printf("*      5:根据学号查找       0:返回上一级菜单 *\n");
		printf("**********************************************\n");

		scanf("%d", &choose);

		switch (choose)
		{
		case 1:
			flag = 0;
			printf("请输入要查找联系人的姓名：\n\t\t\t");
			scanf("%s", array);
			while (q->next)
			{
				if (strcmp(q->next->name, array) == 0)
				{
					flag = 1;
					printf("找到该联系人：\n\n");
					printf("学号：%s\t 姓名:%s\t 号码:%s\t 地址:%s\t Email:%s\n\n\n", q->next->num,
						q->next->name, q->next->telephone, q->next->address, q->next->email);
				}
				q = q->next;
			}
			if (flag == 0)
			{
				printf("查无此人！\n");
			}

			q = head;
			break;
		case 2:
			flag = 0;
			printf("请输入要查找联系人的号码：\n\t\t\t");
			scanf("%s", array);
			while (q->next)
			{
				if (strcmp(q->next->telephone, array) == 0)
				{
					flag = 1;
					printf("找到该联系人：\n\n");
					printf("学号：%s\t 姓名:%s\t 号码:%s\t 地址:%s\t Email:%s\n\n\n", q->next->num,
						q->next->name, q->next->telephone, q->next->address, q->next->email);
				}
				q = q->next;
			}
			if (flag == 0)
			{
				printf("查无此人！\n");
			}

			q = head;
			break;

		case 3:
			flag = 0;
			printf("请输入要查找联系人的地址：\n\t\t\t");
			scanf("%s", array);
			while (q->next)
			{
				if (strcmp(q->next->address, array) == 0)
				{
					flag = 1;
					printf("找到该联系人：\n\n");
					printf("学号：%s\t 姓名:%s\t 号码:%s\t 地址:%s\t Email:%s\n\n\n", q->next->num,
						q->next->name, q->next->telephone, q->next->address, q->next->email);
				}
				q = q->next;
			}
			if (flag == 0)
			{
				printf("查无此人！\n");
			}

			q = head;
			break;

		case 4:
			flag = 0;
			printf("请输入要查找联系人的email：\n\t\t\t");
			scanf("%s", array);
			while (q->next)
			{
				if (strcmp(q->next->email, array) == 0)
				{
					flag = 1;
					printf("找到该联系人：\n\n");
					printf("学号：%s\t 姓名:%s\t 号码:%s\t 地址:%s\t Email:%s\n\n\n", q->next->num,
						q->next->name, q->next->telephone, q->next->address, q->next->email);
				}
				q = q->next;
			}
			if (flag == 0)
			{
				printf("查无此人！\n");
			}

			q = head;
			break;
		case 5:
			flag = 0;
			printf("请输入要查找联系人的学号：\n\t\t\t");
			scanf("%s", array);
			while (q->next)
			{
				if (strcmp(q->next->num, array) == 0)
				{
					flag = 1;
					printf("找到该联系人：\n\n");
					printf("学号：%s\t 姓名:%s\t 号码:%s\t 地址:%s\t Email:%s\n\n\n", q->next->num,
						q->next->name, q->next->telephone, q->next->address, q->next->email);
				}
				q = q->next;
			}
			if (flag == 0)
			{
				printf("查无此人！\n");
			}

			q = head;
			break;
		case 0:
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

}

void output(Friend *head)
{
	int i = 0;
	if (head->next == NULL)
	{
		printf("无联系人信息！\n");
	}
	else
	{
		printf("\n\n\n\n\n\n\n");
		printf("联系人信息：\n\n");
		while (head->next)
		{
			printf("学号：%s\t 姓名:%s\t 号码:%s\t 地址:%s\t Email:%s\n"
				, head->next->num, head->next->name, head->next->telephone, head->next->address, head->next->email);
			head = head->next;
			i++;
		}
		printf("\n\n\n");
	}
}

Status update(Friend *head)
{
	int flag = 0;
	Friend *q = head;
	Friend *p = (Friend *)malloc(sizeof(Friend));
	if (p == NULL)
	{
		return FALSE;
	}

	printf("请输入要修改联系人的姓名：  ");
	scanf("%s", p->name);
	while (q->next)
	{
		if (strcmp(q->next->name, p->name) == 0)
		{
			flag = 1;
			printf("输入要修改的信息：\n\t\t");
			scanf("%s%s%s%s%s", q->next->num, q->next->name, q->next->telephone, q->next->address, q->next->email);
			printf("修改成功！\n");
		}
		q = q->next;
	}

	if (flag == 0)
	{
		printf("查无此人！\n");

		return FALSE;
	}

	free(p);
	return TRUE;
}

void outputFile(Friend *head)
{
	FILE *fp;
	int k = 1;
	fp = fopen("tong_xun_lu_a.txt", "w+");
	while (head->next)
	{
		fprintf(fp, "%d ", k++);   //输出的时候在每个联系人前面输个序号
		fprintf(fp, "%s     %s     %s      %s      %s\r\n"
			, head->next->num, head->next->name, head->next->telephone, head->next->address, head->next->email);
		head = head->next;
	}

	fprintf(fp, "%d\n", 0);

	fclose(fp);
}

Status delete(Friend *head)
{
	int flag = 0;
	Friend *p = head;
	//Friend *temp;
	char name[50];
	printf("请输入要删除联系人的姓名：\n\t\t\t");
	scanf("%s", name);
	while (p->next)
	{
		if (strcmp(p->next->name, name) == 0)
		{
			flag++;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		printf("查无此人！\n");
	}
	if (flag == 1)
	{
		p = head;
		while (p->next)
		{
			if (strcmp(p->next->name, name) == 0)
			{
				Friend *temp = p->next;
				p->next = temp->next;
				free(temp);
				printf("删除成功！\n");
			}
			else
			{
				p = p->next;
			}
		}
	}

	if (flag > 1)
	{
		printf("\n\n\n您要删除的联系人不止一位，请输入您要删除联系人的学号：\n\n");
		char num[20];
		p = head;
		while (p->next)
		{
			if (strcmp(p->next->name, name) == 0)
			{
				printf("学号：%s\t 姓名:%s\t 号码:%s\t 地址:%s\t Email:%s\n", p->next->num,
					p->next->name, p->next->telephone, p->next->address, p->next->email);
			}
			p = p->next;
		}
		scanf("%s", num);
		p = head;
		while (p->next)
		{
			if (strcmp(p->next->num, num) == 0)
			{
				Friend *temp = p->next;
				p->next = temp->next;
				free(temp);
				printf("删除成功！\n");
			}
			else
			{
				p = p->next;
			}
		}
	}

	return TRUE;
}

void clear(Friend **head)
{
	Friend *temp;
	while ((*head)->next)
	{
		temp = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(temp);
	}

	free(*head);
}

void insertSort(Friend *head)
{
	if (head->next->next == NULL || head->next == NULL) {
		printf("列表为空!");
	}
	Friend *head2 = head->next->next;
	head->next->next = NULL;
	while (head2)
	{
		Friend *p = head;
		Friend *q = head2;
		head2 = head2->next;
		while (p->next)
		{
			if (strcmp(q->num, p->next->num) > 0) {
				p = p->next;
			}
			else
				break;
		}
		q->next = p->next;
		p->next = q;
	}
}