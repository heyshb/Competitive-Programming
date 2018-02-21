#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<pair<int,double> >e[100010];
int N;
double a[100010],b[100010],f[100010];
bool ok = true;

void dfs(int x)
{
	//printf("dfs %d\n",x);
	f[x] = b[x]-a[x];
	for (auto t:e[x])
	{
		dfs(t.first);
		if (f[t.first] < 0)
			f[x] += t.second * f[t.first];
		else
			f[x] += f[t.first];
		if (f[x] < -1e20) ok = false;
	}
	//printf("f[%d]=%.3lf\n",x,f[x]);
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lf",&b[i]);
	for (int i=1;i<=N;i++)scanf("%lf",&a[i]);
	for (int i=2;i<=N;i++)
	{
		int u;
		double w;
		scanf("%d%lf",&u,&w);
		e[u].push_back(make_pair(i,w));
	}
	dfs(1);
	puts(f[1] > -1e-12 && ok ? "YES":"NO");
}
