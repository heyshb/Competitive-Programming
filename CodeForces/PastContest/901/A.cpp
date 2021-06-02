#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int H;
int a[100010];

int main()
{
	scanf("%d",&H);
	for (int i=0;i<=H;i++)scanf("%d",&a[i]);
	bool perfect = true;
	int split = -1;
	for (int i=1;i<H;i++)if (a[i] > 1 && a[i+1] > 1) perfect = false,split = i;
	if (perfect)
	{
		puts("perfect");
		return 0;
	}
	puts("ambiguous");
	printf("0");
	int S = 1;
	for (int i=1;i<=H;i++)
	{
		for (int j=1;j<=a[i];j++)printf(" %d",S);
		S += a[i];
	}
	puts("");
	printf("0");
	S = 1;
	for (int i=1;i<=H;i++)
	{
		if (i == split + 1)
		{
			for (int j=1;j<=a[i];j++)
				printf(" %d",j==1?S:S-1);
		}
		else
		{
			for (int j=1;j<=a[i];j++)printf(" %d",S);
		}
		S += a[i];
	}
}
