#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;
struct point
{
	LL x,y; 
}mon[1010],st[10];
LL ret(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x); 
}
LL mul(point a,point b,point c)
{
	return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}
int K,n;
int p[10][1010][1010],cnt[10][1010],q[10];
LL nowx,nowy;
bool used[8];
bool killed[1010];

bool cmp(int a,int b)
{
	return ((mon[a].x-nowx)*(mon[a].x-nowx)+(mon[a].y-nowy)*(mon[a].y-nowy) < (mon[b].x-nowx)*(mon[b].x-nowx)+(mon[b].y-nowy)*(mon[b].y-nowy));
}

bool dfs(int num,int dep)
{
	if (dep==K+1)
	{
		bool flag=false;
		//printf("CALC %d ",num);
		//for (int i=1;i<=K;i++)printf("%d ",q[i]);puts("");
		for (int k=1;k<=K;k++)
		{
			for (int i=1;i<=cnt[q[k]][num];i++)
			if (!killed[p[q[k]][num][i]])
			{
				killed[p[q[k]][num][i]]=true;
				break;
			}
		}
		 
		if (killed[num]) flag=true;
		
		for (int k=1;k<=K;k++)
		{
			for (int i=1;i<=K;i++)
				killed[p[q[k]][num][i]]=false;
		}
		return flag;
	}
	for (int i=1;i<=K;i++)
	if (!used[i])
	{
		q[dep]=i;
		used[i]=true;
		if (dfs(num,dep+1)) {used[i]=false;return true;}
		used[i]=false;
	}
	return false;
}

int main()
{
	scanf("%d%d",&K,&n);
	for (int i=1;i<=K;i++)cin>>st[i].x>>st[i].y;
	for (int i=1;i<=n;i++)cin>>mon[i].x>>mon[i].y;
	memset(cnt,0,sizeof(cnt));
	for (int k=1;k<=K;k++)
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			if (i!=j)
			{
				if (ret(st[k],mon[i],mon[j])==0 && mul(mon[j],mon[i],st[k])<0) p[k][i][++cnt[k][i]]=j;
			}
			p[k][i][++cnt[k][i]]=i;
		}
	for (int k=1;k<=K;k++)
		for (int i=1;i<=n;i++)
		{
			nowx=st[k].x;
			nowy=st[k].y;
			sort(p[k][i]+1,p[k][i]+cnt[k][i]+1,cmp);
		}
		
		/*
	for (int i=1;i<=K;i++)
	for (int j=1;j<=n;j++)
	{
		printf("%d %d:",i,j);
		for (int k=1;k<=cnt[i][j];k++)printf("%d ",p[i][j][k]);
		puts(""); 
	}*/

	int ans=0;
	memset(killed,false,sizeof(killed));
	for (int i=1;i<=n;i++)
	{
		memset(used,false,sizeof(used));
		if (dfs(i,1)) ans++;
	}
	printf("%d\n",ans);
} 
