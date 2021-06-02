#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int>e0[100010],e[100010];

int N,M,H;
int u[100010];
int dfn[100010],low[100010],top = 0,stk[100100];
bool ins[100010];
int tmc = 0, tarcnt = 0;
int num[100010],sum[100010];
bool ok[100010];

void dfs(int x)
{
	dfn[x] = low[x] = ++tmc;
	stk[++top] = x;
	ins[x] = true;
	for (int i=0;i<e[x].size();i++)
	if (!dfn[e[x][i]])
	{
		dfs(e[x][i]);
		low[x] = min(low[x],low[e[x][i]]);
	}
	else if (ins[e[x][i]])
	{
		low[x] = min(low[x],dfn[e[x][i]]);
	}
	if (dfn[x] == low[x])
	{
		int tmp;
		tarcnt++;
		do
		{
			tmp = stk[top--];
			ins[tmp] = false;
			num[tmp] = tarcnt;
			sum[tarcnt]++;
		}while(tmp != x);
	}
}

int main()
{
	scanf("%d%d%d",&N,&M,&H);
	for (int i=1;i<=N;i++)scanf("%d",&u[i]);
	for (int i=1;i<=M;i++)
	{
		int U,V;
		scanf("%d%d",&U,&V);
		//e0[U].push_back(V);
		//e0[V].push_back(U);
		if (u[U] == (u[V] + 1) % H) e[V].push_back(U);//printf("add %d %d\n",V,U);
		if (u[V] == (u[U] + 1) % H) e[U].push_back(V);//printf("add %d %d\n",U,V);
	}
	for (int i=1;i<=N;i++)
	if (!dfn[i]) 
	{
		//if (i==2) puts("??");
		dfs(i);
	}
	//for (int i=1;i<=N;i++)printf("num[%d]=%d\n",i,num[i]);
	memset(ok,true,sizeof(ok));
	for (int i=1;i<=N;i++)
		for (int j=0;j<e[i].size();j++)
		if (num[i] != num[e[i][j]])
		{
			ok[num[i]] = false;
			//printf("fuck %d\n",num[i]);
		}
	int mins = 1e9, tarnum = -1;
	for (int i=1;i<=tarcnt;i++)
	if (ok[i] && sum[i] < mins)
	{
		mins = sum[i];
		tarnum = i;
	}
	printf("%d\n",mins);
	vector<int>ans;
	for (int i=1;i<=N;i++)
	if (num[i] == tarnum) ans.push_back(i);
	for (int i=0;i<ans.size();i++)printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
}
