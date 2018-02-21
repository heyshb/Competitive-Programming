#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct seg
{
	LL K,B;
};

set<seg>s[100010];
int N,setnum[100010];
LL f[100010],A[100010],B[100010];
vector<int>e[100010];
int size[100010];

LL con(seg s1,seg s2)
{
	LL k1,k2,b1,b2;
	k1 = s1.K, k2 = s2.K, b1 = s1.B, b2 = s2.B;
	return (b2 - b1) / (k1 - k2);
}

void insert(int num,LL K,L B)
{
	
}

LL find(int num,LL x)
{
	
}

void dfs(int x,int fa)
{
	int cnt = 0;
	size[x] = 1;
	for (auto t:e[x])
	if (t != fa)
	{
		dfs(t,fa);
		size[x] += size[t];
	}
	if (size[x] == 1)
	{
		f[x] = 0;
		setnum[x] = x;
		insert(x,B[x],0);
		return;
	}
	int maxsize = 0,maxson;
	for (auto t:e[x])
	if (t != fa)
	{
		if (size[t] > maxsize)
		{
			maxsize = size[t];
			maxson = t;
		}
	}
	setnum[x] = setnum[maxson];
	for (auto t:e[x])
	if (t != fa && t != maxson)
	{
		for (auto S:s[setnum[t]])
			insert(setnum[x],S.K,S.B);
	}
	f[x] = find(setnum[x],A[x]);
	insert(setnum[x],B[x],f[x]);
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lld",&A[i]);
	for (int i=1;i<=N;i++)scanf("%lld",&B[i]);
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for (int i=1;i<=N;i++)printf("%lld%c",f[i]," \n"[i==N]);
} 
