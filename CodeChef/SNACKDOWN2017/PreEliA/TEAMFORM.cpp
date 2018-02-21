#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int N,M,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		int u,v;
		for (int i=1;i<=M;i++)scanf("%d%d",&u,&v);
		puts((N&1)?"no":"yes");
	}
}
