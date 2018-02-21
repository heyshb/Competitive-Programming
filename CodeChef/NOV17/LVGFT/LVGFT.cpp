#include <bits/stdc++.h>

using namespace std;

struct query
{
	int type,C,ans;
}q[100010];

int N,M,T;
vector<int>e[100010];
int col[100010];
int fa[100010];
set<int>s[100010];
set<int>all;

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

/*
void shrink()
{
	while(all.size() > 4)
		all.erase(all.begin());
}*/

void shrink(int num)
{
	while(s[num].size() > 2)
		s[num].erase(s[num].begin());
}

int query(int num)
{
	if (N == 1) return -1;
	if (col[num]) return N - 1; 
	//printf("%d %d\n",num,find(num));
	for (auto t:s[find(num)])
	{
		//printf("erase %d\n",t);
		all.erase(t);
	}
	auto it = all.end();
	int res = -1;
	if (it != all.begin())
	{
		it--;	
		if (it != all.begin())
		{
			it--;
			res = (*it);
		}
	}
	for (auto t:s[find(num)])
		all.insert(t);
	//shrink();
	return res;
}

void uno(int x,int y)
{
	//printf("uno %d %d\n",x,y);
	x = find(x);
	y = find(y);
	if (x == y) return;
	fa[y] = x;
	for (auto t:s[x]) all.erase(t);
	for (auto t:s[y]) all.erase(t);
	for (auto t:s[y])
	{
		s[x].insert(t);		
	}
	s[y].clear();
	shrink(x);
	for (auto t:s[x]) all.insert(t);
	//shrink();
}

void init()
{
	all.clear();
	for (int i=1;i<=N;i++)
	{
		fa[i] = i;
		s[i].clear();
		s[i].insert(i);
		all.insert(i);
	}
	//shrink();
	for (int i=1;i<=N;i++)
		for (auto t:e[i])
		if (!col[i] && !col[t]) uno(i,t);
}

void white(int num)
{
	if (--col[num] == 0)
	{
		for (auto t:e[num])
		if (!col[t])
		{
			uno(num,t);
		}
	}
}

void print(set<int>ss)
{
	for (auto t:ss)printf("%d ",t);
	puts("");
}

int main()
{
	freopen("LVGFT.in","r",stdin);
	freopen("std.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int cnt2 = 0;
		scanf("%d%d",&N,&M);
		for (int i=1;i<=N;i++)e[i].clear(),col[i] = 0;
		for (int i=1;i<N;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int i=1;i<=M;i++)
		{
			scanf("%d%d",&q[i].type,&q[i].C);
			if (q[i].type == 1)
				col[q[i].C]++; 
			else 
				cnt2++;
		}
		//printf("cnt2 = %d\n",cnt2);
		init();
		//puts("init done");
		for (int i=M;i>=1;i--)
		{
			//printf("%d th oper\n",i);
			//printf("%d %d\n",q[i].type,q[i].C);
			//print(all);
			//print(s[find(1)]);
			int C = q[i].C;
			if (q[i].type == 1)
			{
				white(C);
			}
			else
			{
				q[i].ans = query(C);
				//printf("ans = %d\n",q[i].ans); 
				//printf("%d\n",query(C));
			}
		}
		for (int i=1;i<=M;i++)
		{
			//printf("%d %d\n",q[i].type,q[i].C);
			if (q[i].type == 2)
			{
				printf("%d\n",q[i].ans);
			}
		}
	}
}
