#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int>v1,v2;
bool vis[1010];
int K,N;
int f1[1000010],f2[1000010];

int main()
{
	scanf("%d%d",&K,&N);
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if (tmp==K)
		{
			puts("1");
			return 0;
		}
		vis[tmp] = true;
	}
	for (int i=0;i<K;i++)
	if (vis[i])
	{
		//printf("1 %d\n",K-i);
		v1.push_back(K-i);
	}
	for (int i=K+1;i<=1000;i++)
	if (vis[i])
	{
		//printf("2 %d\n",i-K);
		v2.push_back(i-K);
	}
	if (!v1.size() || !v2.size())
	{
		puts("-1");
		return 0;
	}
	for (int i=1;i<=500000;i++)
	{
		f1[i] = f2[i] = 10000000;
	}
	f1[0] = f2[0] = 0;
	for (int i=0;i<v1.size();i++)
	{
		//printf("update %d %d\n",i,v1[i]);
		for (int j=v1[i];j<=500000;j++)
		f1[j] = min(f1[j], f1[j-v1[i]] + 1);
	}
	//for (int i=0;i<=100;i++)printf("%d %d\n",i,f1[i]);
	
	for (int i=0;i<v2.size();i++)
	{
		for (int j=v2[i];j<=500000;j++)
		f2[j] = min(f2[j], f2[j-v2[i]] + 1);
	}
	
	int ans = 10000000;
	for (int i=1;i<=500000;i++)ans=min(ans,f1[i]+f2[i]);
	printf("%d\n",ans);
}
