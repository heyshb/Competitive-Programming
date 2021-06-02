#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool vis[30];
bool appear[30];
vector<int>e[30];

int N;
char s1[100010],s2[100010];
int S = 0;
vector<pair<int,int> >anss;

void dfs(int x,int fa)
{
	if (fa != -1)
		anss.push_back(make_pair(x,fa));
	vis[x] = true;
	S++;
	for (auto t:e[x])
	if (!vis[t])
		dfs(t,x);
}

int main()
{
	scanf("%d",&N);
	scanf("%s",s1);
	scanf("%s",s2);
	for (int i=0;i<N;i++)s1[i]-='a',s2[i]-='a',appear[s1[i]+1]=appear[s2[i]+1]=true;
	for (int i=0;i<N;i++)
	if (s1[i] != s2[i])
	{
		int a,b;
		a = s1[i] + 1;
		b = s2[i] + 1;
		//printf("%d %d\n",a,b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int ans = 0;
	for (int i=1;i<=26;i++)
	if (appear[i] && !vis[i])
	{
		S = 0;
		dfs(i,-1);
		ans += S - 1;
	}
	printf("%d\n",ans);
	for (auto t:anss)
	{
		printf("%c %c\n",'a' + t.first - 1,'a' + t.second - 1);
	}
} 
