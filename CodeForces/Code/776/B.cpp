#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int color[100010];
bool ok[100010];

int main()
{
	memset(color,0,sizeof(color));
	memset(ok,true,sizeof(ok));
	int N;
	int K = 1;
	scanf("%d",&N);
	for (int i=2;i<=N+1;i++)
	{
		if (ok[i])
			color[i] = 1;
		else
		{
			K = 2;
			color[i] = 2;
		}
		for (int j=i*2;j<=N+1;j+=i)
		{
			//4printf("%d \n",j);
			ok[j] = false;
		}
	}
	printf("%d\n",K);
	for (int i=2;i<=N+1;i++)printf("%d ",color[i]);
}
