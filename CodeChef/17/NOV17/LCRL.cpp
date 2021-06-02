#include <bits/stdc++.h>

using namespace std;

int main()
{
	int Q,N,M,L,R;
	scanf("%d",&Q);
	while(Q--)
	{
		L = -1e9 - 10;
		R = 1e9 + 10;
		scanf("%d%d",&N,&M);
		bool ok = true;
		for (int i=1;i<=N;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			if (tmp >= M)
			{
				ok &= (tmp < R);
				R = tmp;
			}
			else
			{
				ok &= (tmp > L);
				L = tmp;
			}
		}
		puts(ok?"YES":"NO");
	}
}
