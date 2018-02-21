#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,A[100010]; 
int ans[100010];
bool vis[100010];
int f[360][100010];
vector<int>now;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	int B = int(sqrt(N)+1);
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=B;i++)
	{
		now.clear();
		int cnt = 0, cosum = 0;
		for (int j=1;j<=N;j++)
		{
			if (!vis[A[j]])
			{
				if (++cosum > i)
				{
					for (int k=0;k<now.size();k++)vis[now[k]] = false;
					cosum = 1;
				}
				now.push_back(A[j]);
				vis[A[j]] = true;
				if (cosum==1) 
				{
					cnt++;
					//printf("%d %d\n",i,j);
				}
			}
			ans[i] = cnt;
		}
		for (int k=0;k<now.size();k++)vis[now[k]] = false;
	}
	for (int i=1;i<=B;i++)
		for (int j=1;j<=N;j++)
		{
			
		}
	for (int i=1;i<=B;i++)
	{
		
	}
	for (int i=1;i<=N;i++)printf("%d ",ans[i]);
}
