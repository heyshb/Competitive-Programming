#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<pair<int,int> >p;
vector<int>pp;
void ins(int x)
{
	for (auto t:p)
	if (t.first==x)
	{
		t.second++;
		return;
	}
	p.push_back(make_pair(x,1));
}

void fac(int a)
{
	int j;
	for (j=1;j*j<=a;j++)
	for (int i=2;i<=j;i++)
	{
		while(a%i==0)
		{
			a/=i;
			ins(i);
		}
		if (a==1) break;
	}
	if (a>1) ins(a);
}

LL s = 1;
LL sq; 
LL mins = 1LL;

void dfs(int dep,LL mul)
{
	if (mul * mul > s) return;
	if (mul + s/mul < mins + s/mins) mins = mul;
	if (dep == pp.size()) return;
	dfs(dep+1,mul);
	dfs(dep+1,mul * pp[dep]);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		p.clear();
		fac(a);fac(b);
		pp.clear();
		for (auto t:p) printf("%d %d\n",t.first,t.second);
		s = 1;
		for (auto t:p) if (t.second&1) 
		{
			pp.push_back(t.first);
			s *= LL(t.first);
		}
		mins = 1;
		dfs(0,1);
		printf("%lld %lld\n",mins,s/mins);
	}
}
