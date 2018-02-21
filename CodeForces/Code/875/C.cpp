#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int>w[200010];
bool mustchange[200010],mustnotchange[200010];
int N,M,len[200010],lcp[200010];
vector<int>e[200010];
int fa[200010];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void addedge(int x,int px,int y,int py)
{
	int PX = 2*x-1+px, PY = 2*y-1+py;
	if (find(PX) != find(PY))
		fa[find(PX)] = find(PY);
}
//FALSE 2*M+1   TRUE 2*M+2

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=2*M+2;i++)fa[i] = i;
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&len[i]);
		for (int j=1;j<=len[i];j++)
		{
			int tmp;
			scanf("%d",&tmp);
			w[i].push_back(tmp);
		}
	}
	for (int i=1;i<N;i++)
	{
		for (int j=0;j<min(len[i],len[i+1]);j++)
		{
			if (w[i][j] != w[i+1][j]) break;
			lcp[i] = j+1;
		}
		//printf("%d %d\n",i,lcp[i]);
		if (lcp[i] == min(len[i],len[i+1]))
		{
			if (len[i] > len[i+1]) return 0*puts("No");
			continue;
		}
		if (w[i][lcp[i]] > w[i+1][lcp[i]])
		{
			addedge(M+1,0,w[i][lcp[i]],0);
			addedge(M+1,1,w[i][lcp[i]],1);
			addedge(M+1,0,w[i+1][lcp[i]],1);
			addedge(M+1,1,w[i+1][lcp[i]],0);
		}
		else
		{
			addedge(w[i][lcp[i]],0,w[i+1][lcp[i]],0);
			addedge(w[i][lcp[i]],1,w[i+1][lcp[i]],1);
		}
	}
	for (int i=1;i<=M+1;i++)
	if (find(2*i-1) == find(2*i)) return 0*puts("No");
	puts("Yes");
	vector<int>ans;
	for (int i=1;i<=M;i++)
	if (find(2*i) == find(2*M+2)) ans.push_back(i);
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
}
