#include <bits/stdc++.h>
#define FIND -2
using namespace std;

int N;
int fa[1000010];
int sum[1000010],v[1000010];
int S,dep[1000010];
int ans1,ans2;
int RT;
vector<int>e[1000010];
vector<int>s1[1000010],s2[1000010];

void dfs(int x)
{
	sum[x] = v[x];
	for (int i=0;i<e[x].size();i++)
	{
		dep[e[x][i]] = dep[x]+1;
		dfs(e[x][i]);
		sum[x]+=sum[e[x][i]];
		//printf("%d--->%d %d",x,e[x][i],sum[x]);
	}
}

int dfs2(int x)
{
	int res = 0, tmpans = -1;
	for (int i=0;i<e[x].size();i++)
	{
		int tmp = dfs2(e[x][i]);
		if (tmp==FIND) return FIND;
		
		if (tmp>0)
		{
			if (sum[x]==2*S && x!=RT)
			{
				ans1 = x;
				ans2 = tmp;
				//printf("%d %d\n",x,FIND);
				return FIND;
			}
			
			if (tmpans == -1)
			{
				tmpans = tmp;
			}
			else
			{
				ans1 = tmpans;
				ans2 = tmp;
				//printf("%d %d\n",x,FIND);
				return FIND; 
			}
		}
	}
	//printf("%d:%d %d\n",x,tmpans,sum[x]);
	if (sum[x]==S) return x;
	if (tmpans!=-1) return tmpans;
	return 0;
}

int main()
{
	scanf("%d",&N);
	S = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d",&fa[i],&v[i]);
		S+=v[i];
		if (fa[i]) 
			e[fa[i]].push_back(i);
		else
			RT = i;
	}
	if (S%3!=0)
	{
		puts("-1");
		return 0;
	}
	S/=3;
	dep[RT] = 1;
	dfs(RT);
	//for (int i=1;i<=N;i++)printf("%d\n",sum[i]);
	if (dfs2(RT)!=FIND)
		puts("-1");
	else
		printf("%d %d\n",ans1,ans2);
}
