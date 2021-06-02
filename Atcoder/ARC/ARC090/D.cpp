#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
int fa[200010],d[200010];

int find(int x)
{
	if (x == fa[x]) return x;
	int tmp = find(fa[x]);
	d[x] += d[fa[x]];
	fa[x] = tmp;
	return tmp;
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)fa[i] = i, d[i] = 0;
	bool ok = true;
	for (int i=1;i<=M;i++)
	{
		int L,R,D;
		scanf("%d%d%d",&L,&R,&D);
		if (find(L) == find(R))
		{
			if (d[L] - d[R] != D) ok = false;
		}
		else
		{
			int fl = find(L), fr = find(R);
			d[fl] = D + d[R] - d[L];
			fa[fl] = fr;
		}
	}
	if (ok)
		puts("Yes");
	else
		puts("No");
	
}
