/**
* 冒泡排序优化
* 运行环境 Microsoft Visual Studio
* Peng Tsinv
*/

#include<stdio.h>
#include<malloc.h>

// 程序入口
int main()
{
	printf_s("请输入待排序序列长度n:");
	long n, temp;
	scanf_s("%d", &n);

	// 申请内存
	long *p = (long *)malloc(n * sizeof(long));

	// 如果申请失败,结束程序
	if (p == NULL) {
		printf_s("申请内存失败");
		return 0;
	}

	// 用户输入n个数字
	for (long i = 0; i < n; i++) {
		printf_s("请输入第%d个数：", i + 1);
		scanf_s("%d", &p[i]);
	}

	// 冒泡排序
	long k = n - 1;
	long site = 0;

	for (long i = 0; i < n - 1; i++) {
		int flag = 1;
		site = 0;
		for (long j = 0; j < k; j++) {
			if (p[j] > p[j + 1]) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				flag = 0;
				site = j;
			}
		}
		if (flag == 1)
			break;
		k = site;
	}

	// 打印结果
	for (long i = 0; i < n; i++) {
		printf_s("%d ", p[i]);
	}
	return 0;
}