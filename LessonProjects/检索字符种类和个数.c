#include<stdio.h>
#include<string.h>
void  stat(char sten[], int ch[26])
{
	char backup[27], c;
	int j, i, n = 0, s, t, k = 0;
	s = strlen(sten);
	c = ' ';
	for (i = 0; i < s; i++)
	{
		if (c != sten[i])
		{
			c = sten[i];
			for (j = 0; j < 27; j++)
				if (c == backup[j]) break;
			if (j == 27)
			{
				backup[k] = c;
				k++;
			}
		}
	}
	backup[k] = '\0';
	t = strlen(backup);
	for (i = 0; i < t; n = 0, i++)
		for (j = 0; j < s; j++)
		{
			if (backup[i] == sten[j])
				ch[i] = ++n;

		}
	for (i = 0; i < t; i++)
		sten[i] = backup[i];
	sten[t] = '\0';
}

void main()
{
	char sten[30];
	int ch[26], i, s;
	printf("请输入一个字符串： ");
	gets_s(sten, 30);
	stat(sten, ch);
	s = strlen(sten);
	for (i = 0; i < s; i++)
		printf("%c有%d个\n", sten[i], ch[i]);
}