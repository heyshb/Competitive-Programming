#include <bits/stdc++.h>

using namespace std;

const int INF = 200000;
int A,B,H,W,N;
int v[100010];
vector<pair<int,int> >p;
vector<int>now;

bool dfs(int dep,int mx,double x,double y)
{
	if (dep == mx)
	{
		for (int i=0;i<mx;i++)
		{
			for (int j=0;j<now[i];j++)x/=double(p[i].first);
			for (int j=0;j<p[i].second-now[i];j++)y/=double(p[i].first);
		}
		return (x<1+1e-5 && y<1+1e-5);
	}
	for (int i=0;i<=p[dep].second;i++)
	{
		now.push_back(i);
		bool flag = dfs(dep+1,mx,x,y);
		now.pop_back();
		if (flag) return true;
	}
	return false;
}

int solve()
{
	double x,y;
	if (A <= H)
		x = 1;
	else	
		x = A/H + (A%H != 0);
	
	if (B <= W)
		y = 1;
	else
		y = B/W + (B%W != 0);
		
	double tmp = x*y;
	for (int i=1;i<=N;i++)tmp/=v[i];
	if (tmp > 1 + 1e-5) return INF;
	if (x < 1.00001 && y < 1.00001) return 0;
	
	p.clear();
	for (int i=N;i>=1;i--)
	{
		int sz = p.size();
		if (p.size()>0 && v[i]==p[sz-1].first)
			p[sz-1].second++;
		else
			p.push_back(make_pair(v[i],1));
		now.clear();
		if (dfs(0,p.size(),x,y))
			return N-i+1;
	}
	
	return INF;
}

int main()
{
	scanf("%d%d%d%d%d",&A,&B,&H,&W,&N);
	for (int i=1;i<=N;i++)scanf("%d",&v[i]);
	sort(v+1,v+N+1);
	int ans = solve();
	swap(H,W);
	ans = min(ans,solve());
	if (ans == INF)
		puts("-1");
	else
		printf("%d\n",ans);
}
