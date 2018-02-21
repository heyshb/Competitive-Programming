#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,P,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&P);
		if (P <= 2) puts("impossible");
		else 
		{
			int D = N / P;
			for (int i=1;i<=D;i++)
			{
				printf("a");
				for (int j=1;j<=P - 2;j++)printf("b");
				printf("a");
			}
			puts("");
		}
	}
}
