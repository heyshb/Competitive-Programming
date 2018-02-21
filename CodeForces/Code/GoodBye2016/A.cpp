#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int N,k,S=0,ans=0;
	scanf("%d%d",&N,&k);
	for (int i=1;i<=N;i++)
	{
		//printf("%d %d\n",i,k+5*(i+1)*i/2);
		if (k+5*(i+1)*i/2<=240) ans=i;
	}
	printf("%d",ans);
}
