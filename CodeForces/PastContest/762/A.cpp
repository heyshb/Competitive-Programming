#include <bits/stdc++.h>

using namespace std;

typedef long long LL; 
vector<LL>fac;
vector<pair<LL,int> >p;
int cnt;

void dfs(int dep,LL v)
{
	if (dep==cnt)
	{
		fac.push_back(v);
		return;
	}
	LL v1 = p[dep].first;
	int v2 = p[dep].second;
	for (int i=0;i<=v2;i++)
	{
		dfs(dep+1,v);
		v*=v1;
	}
}

int main()
{
	LL N;
	int K;
	scanf("%I64d%d",&N,&K);
	for (LL i=2;i*i<=N;i++)
	{
		if (N%i==0)
		{
			int tmp = 0;
			while(N%i==0)
			{
				N/=i;
				tmp++;
			}
			p.push_back(make_pair(i,tmp));
			if (N==1) break;
		}
	}
	if (N>1) p.push_back(make_pair(N,1));
	cnt = p.size();
	dfs(0,1);
	if (fac.size()<K) 
	{
		puts("-1");
		return 0;
	}
	sort(fac.begin(),fac.end());
	printf("%I64d\n",fac[K-1]);
}
