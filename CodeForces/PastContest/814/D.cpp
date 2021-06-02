#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const double PI = acos(-1);
const double eps = 1e-9;
int N;
struct cir
{
	double x,y,r;
}C[1010];
vector<int>e[1010],e2[1010];
double ffmax[1010],ffmin[1010];
int ind[1010];
bool rt[1010];
double dis(cir a,cir b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double S(cir a)
{
	return PI * a.r * a.r;
}
bool ct(cir a,cir b)
{
	return a.r > b.r && dis(a,b) + b.r < a.r + eps;
}
queue<int>q;
/*
void solve(int x)
{
	ffmin[x] = ffmax[x] = S(C[x]);
	for (auto t:e2[x]) 
	{
		solve(t);
		ffmin[x] += min(ffmin[t],-ffmax[t]);
		ffmax[x] += max(ffmax[t],-ffmin[t]);
	}
	printf("Res of %d = %.3lf %.3lf\n",x,ffmax[x],ffmin[x]);
}*/

double solve(int x,int dep)
{
	double res;
	if (dep <= 1 || dep % 2 == 1) 
	{
		//printf("Kira! %d\n",x);
		res = S(C[x]);
	}
	else res = -S(C[x]);
	for (auto t:e2[x])
		res += solve(t,dep+1);
	//printf("%d %d %.3lf\n",x,dep,res);
	return res;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lf%lf%lf",&C[i].x,&C[i].y,&C[i].r);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
		if (ct(C[i],C[j]))
		{
			e[i].push_back(j);
			ind[j]++;
		}
	memset(rt,0,sizeof(rt));
	double ans = 0;
	for (int i=1;i<=N;i++)
	if (ind[i] == 0)
	{
		rt[i] = true;
		q.push(i);
	}
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for (auto t:e[now])
		{
			if (--ind[t] == 0)
			{
				e2[now].push_back(t);
				//printf("%d--->%d\n",now,t);
				q.push(t);
			}
		}
	}
	for (int i=1;i<=N;i++)
		if (rt[i]) 
		{
			ans += solve(i,0);
		}
	printf("%.10lf\n",ans);
}
