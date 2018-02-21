#include <bits/stdc++.h>

using namespace std;

int d[10010];

int main()
{
	for (int i=1;i<=10000;i++)
	{
		d[i] = 0;
		for (int j=1;j*j<=i;j++)
		if (i % j == 0)
		{
			d[i] += j;
			if (j != 1 && (j * j != i))
				d[i] += i / j; 
		}
	}
	int S = 0;
	for (int i=2;i<=10000;i++)
	if (d[i] <= 10000 && d[d[i]] == i && d[i] != i)
	{
		printf("%d %d\n",i,d[i]);
		S += i;
	}
	printf("%d\n",S);
}
