#include <bits/stdc++.h>

using namespace std;

bool choose[100010];
int N;
vector<int>e[100010];
int fa[100010];
priority_queue<pair<int,int> >heap;
bool leaf[100010];

void dfs(int x,int f,int dep)
{
	leaf[x] = true;
	fa[x] = f;
	for (auto t:e[x])
	if (t != f)
	{
		leaf[x] = false;
		dfs(t,x,dep+1);
	}
	if (leaf[x]) heap.push(make_pair(dep,x));
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)e[i].clear();
		int cnt = 0;
		for (int i=1;i<N;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
			if (x==1 || y==1) 
				cnt++;
		}
		fa[1] = 0;
		dfs(1,0,1);
		memset(choose,false,sizeof(choose));
		int ans = 0;
		while(!heap.empty())
		{
			auto t = heap.top();
			heap.pop();
			if (choose[t.second]) continue;
			ans++;
			choose[t.second] = true;
			int f = fa[t.first], ff = fa[f];
			/*
			if (ff == 0)
			{
				heap.push(make_pair(t.second-1,f));
			}
			*/
			if (ff == 0) continue;
			else
			{
				heap.push(make_pair(t.second-2,ff));
			}
		}
		if (cnt == 1 && !choose[1])
			ans++;
		printf("%d\n",ans);
	}
}
