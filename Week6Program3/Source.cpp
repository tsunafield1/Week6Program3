#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
bool ch[101];
int main()
{
	bool yes = 1;
	int n,table[10][10],sum=0,fsum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &table[i][j]);
			if (ch[table[i][j]])yes = 0;
			ch[table[i][j]] = 1;
		}
	}
	for (int j = 0; j < n; j++)
	{
		sum += table[0][j];
	}
	fsum = sum;
	for (int i = 1; i < n; i++)  
	{
		if (!yes)break;
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += table[i][j];
		}
		if (sum != fsum)
		{
			yes = 0;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!yes)break;
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += table[j][i];
		}
		if (sum != fsum)
		{
			yes = 0;
			break;
		}
	}

	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += table[i][i];
	}
	if (sum != fsum)yes = 0;

	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += table[n-(1+i)][i];
	}
	if (sum != fsum)yes = 0;
	if (yes)printf("Yes");
	if (!yes) printf("No");
}