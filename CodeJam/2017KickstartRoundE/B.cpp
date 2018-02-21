#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
vector<pair<LL,LL> >stick;
LL v[5010];
LL sum[5010];
int N;

LL C(LL a)
{
	if (a < 2) return 0;
	return a * (a - 1) / 2;
}

LL C3(LL a)
{
	if (a < 3) return 0;
	return a*(a-1)*(a-2)/6;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)scanf("%lld",&v[i]);
		v[N+1] = -1;
		sort(v+1,v+N+1);
		stick.clear();
		int cnt = 1;
		for (int i=1;i<=N;i++)
		{
			if (v[i] != v[i+1])
			{
				stick.push_back(make_pair(v[i],LL(cnt)));
				cnt = 1;
			}
			else
			{
				cnt++;
			}
		}
		int M = stick.size();
		sum[0] = stick[0].second;
		for (int i=1;i<M;i++)sum[i] = sum[i-1] + stick[i].second;
		//for (int i=0;i<M;i++)printf("%lld %lld %lld\n",stick[i].first,stick[i].second,sum[i]);
		int p1, p2;
		LL ans = 0;
		for (int i=0;i<M;i++)
		if (stick[i].second >= 2)
		{
			p2 = 0;
			for (p1 = 0; p1 < M; p1++)
			if (p1 != i)
			{
				while(p2 < M && stick[p1].first + 2*stick[i].first > stick[p2].first)p2++;
				p2--;
				//printf("!! %d %d %d\n",i,p1,p2);
				LL delta = sum[p2] - sum[p1];
				if (i > p1 && i<=p2) delta -= stick[i].second;
				ans += stick[p1].second * delta * C(stick[i].second);
				//printf("get %lld %lld\n",delta,ans);
			}
		}
		for (int i=0;i<M;i++)
			for (int j=0;j<M;j++)
			if (i != j && 3 * stick[i].first > stick[j].first && stick[i].second >= 3)
			{
				//printf("3! %d %d\n",i,j);
				ans += C3(stick[i].second) * stick[j].second;
			}
		printf("Case #%d: %lld\n",_,ans); 
	}
}
