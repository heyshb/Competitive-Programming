#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,D[500010],M;
double T[500010];
vector<pair<double,double> >e0[500010];
vector<pair<double,int> >e[500010];
double v[500010];
int cnt;
double tr[500010];
int lowbit(int x){return x&-x;}
double get(int x){
	double S = 0;
	while(x)
	{
		S += tr[x];
		x -= lowbit(x);
	}
	return S;
}
void add(int x,double y)
{
	while(x<=M)
	{
		tr[x] += y;
		x += lowbit(x);
	}
}

double eps = 1e-6;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&D[i]);
	cnt = 0;
	for (int i=1;i<=N;i++)
	{
		for (int j=0;j<D[i];j++)
		{
			double a;
			double p;
			scanf("%lf%lf",&p,&a);
			e0[i].push_back(make_pair(p,a));
			v[++cnt] = a;
		}
	}
	sort(v+1,v+cnt+1);
	M = 0;
	v[0] = v[1] - 1;
	for (int i=1;i<=cnt;i++)
	if (v[i] - v[i - 1] > eps)
		v[++M] = v[i];
	for (int i=1;i<=N;i++)
	{
		for (int j=0;j<D[i];j++)
		{
			int pos = lower_bound(v+1,v+M+1,e0[i][j].second - 3*eps) - v;
			e[i].push_back(make_pair(e0[i][j].first,pos));
		}
	}
	double ans = 0;
	for (int i=N;i>=1;i--)
	{
		for (int j=0;j<D[i];j++)
		{
			double p = e[i][j].first;
			int a = e[i][j].second;
			ans += p * get(a-1);
		}
		for (int j=0;j<D[i];j++)
		{
			double p = e[i][j].first;
			int a = e[i][j].second;
			add(a,p);
		}
	}
	printf("%.2lf\n",ans);
}

