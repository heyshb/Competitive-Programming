#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;
int N,M;
int m[MAXN];
vector<int>ob[MAXN],e[MAXN];
int umi;
int vis[MAXN];
int ind[MAXN],ans[MAXN];
priority_queue<int,vector<int>,greater<int> >heap;

int dfs(int u){
	vis[u] = umi;
	for (auto &v : e[u]){
		if (vis[v] == umi)
			return 0;
		if (vis[v] == 0)
			if (!dfs(v))
				return 0;
	}
	return 1;
}

int maki(){
	for (int i = 1; i <= N; i++)
		vis[i] = 0;
	umi = 0;
	for (int i = 1; i <= N; i++)
		if (!vis[i]){
			umi++;
			if (!dfs(i))
				return 0;
		}
	return 1;
}

int nico(){
	for (int i=1;i<=N;i++)ind[i] = 0;
	for (int i=1;i<=N;i++)
		for (int j=0;j<e[i].size();j++)
			ind[e[i][j]]++;
	for (int i=1;i<=N;i++)
	if (!ind[i]) heap.push(i);
	for (int i=1;i<=N;i++)
	{
		if (heap.empty()) return 0;
		int x = heap.top();
		ans[i] = x;
		heap.pop();
		for (int j=0;j<e[x].size();j++)
		if (--ind[e[x][j]] == 0)
			heap.push(e[x][j]);
	}
	return 1;
}

bool check(int x)
{
//	puts("check begin");
	for (int i=1;i<=N;i++)e[i].clear();
	for (int i=1;i<=x;i++)
	{
		//printf("%d %d %d\n",i,m[i],ob[i].size());
		for (int j=1;j<m[i];j++)
		{
			//printf("add %d %d\n",ob[i][j-1],ob[i][j]);
			e[ob[i][j-1]].push_back(ob[i][j]);
		}
	}
	
	int tmp = nico();
	//puts("check end");
	return tmp;
}

void fuck(){
	int ans = 0;
	while(1) ans++;
	cout << ans << endl;
}

int main()
{
	freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
	scanf("%d%d",&N,&M);
	/*if (M == 50000) {
		fuck();
	}*/
	for (int i=1;i<=M;i++)
	{
		scanf("%d",&m[i]);
		int tmp;
		for (int j=0;j<m[i];j++)
		{
			scanf("%d",&tmp);
			ob[i].push_back(tmp);
		}
	}
	int L = 0, R = M + 1;
	while(L < R - 1)
	{
		int mid = (L + R) / 2;
		if (check(mid))
		{
			L = mid;
		}
		else
		{
			R = mid;
		}
	}
	check(L);
	for (int i=1;i<=N;i++)
		for (int j=0;j<e[i].size();j++)
			ind[e[i][j]]++;
	for (int i=1;i<=N;i++)
	if (!ind[i]) heap.push(i);
	for (int i=1;i<=N;i++)
	{
		int x = heap.top();
		ans[i] = x;
		heap.pop();
		for (int j=0;j<e[x].size();j++)
		if (--ind[e[x][j]] == 0)
			heap.push(e[x][j]);
	}
	//while (lalala(L + 1))
	//	L++;
	//lalala(L);
	assert(heap.empty());
	for (int i=1;i<=N;i++)printf("%d%c",ans[i]," \n"[i==N]);
}
