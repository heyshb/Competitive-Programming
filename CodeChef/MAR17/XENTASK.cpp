#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int S1 = 0, S2 = 0;
		int N,v;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&v);
			if (i&1)
				S1 += v;
			else
				S2 += v;
		}
		
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&v);
			if (i&1)
				S2 += v;
			else
				S1 += v;
		}
		
		printf("%d\n",min(S1,S2));
	}
}
