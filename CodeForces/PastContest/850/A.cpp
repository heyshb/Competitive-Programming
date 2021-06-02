#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct point
{
	int x[5];
	friend point operator - (point a,point b)
	{
		point c;
		for (int i=0;i<5;i++)c.x[i] = a.x[i] - b.x[i];
		return c;
	}
	friend int operator * (point a,point b)
	{
		int c = 0;
		for (int i=0;i<5;i++)c += a.x[i] * b.x[i];
		return c;
	}
}p[1010];

int N;
vector<int>ans;

double cs(point a,point b)
{
	return 1.0 * (a*b) / sqrt(a*a) / sqrt(b*b);
}

bool good(int x)
{
	for (int i=1;i<=min(N,100);i++)
		for (int j=i+1;j<=N;j++)
		if (i != x && j != x)
		{
			if (cs(p[i]-p[x],p[j]-p[x]) > 1e-5) 
			{
				//printf("%d %d %d %.6lf\n",x,i,j,cs(p[i]-p[x],p[j]-p[x]));
				return false;
			}
		}
	return true;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		for (int j=0;j<5;j++)scanf("%d",&p[i].x[j]);
	ans.clear();
	for (int i=1;i<=N;i++)
	if (good(i))
		ans.push_back(i);
	printf("%d\n",ans.size());
	for (auto t:ans) printf("%d\n",t);	
}
