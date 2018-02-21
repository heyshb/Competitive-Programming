#include <bits/stdc++.h>

using namespace std;

int N = 100;
vector<int>prime,p2;
int cnt[1010];

bool check(int x)
{
	for (int i=2;i*i<=x;i++)
	if (x%i==0) return false;
	return true;
}

typedef long long LL;
map<pair<LL,LL>,LL> f1[100],f2[100];//f[i][j][k] 
map<pair<LL,LL>,LL>ct;

LL gcd(LL a,LL b){return b==0?a:gcd(b,a%b);}
#define MP make_pair 
int main()
{
	for (int i=2;i<=N;i++)
	if (check(i))
		prime.push_back(i);
	int M = prime.size();
	for (int i=1;i<=N;i++)
	{
		int x = i;
		for (int j=0;j<M;j++)
		while(x%prime[j]==0)
		{
			x/=prime[j];
			cnt[j]++;
		}
	}
	for (int i=0;i<M;i++)printf("%d %d\n",prime[i],cnt[i]);
	for (int i=3;i<M;i++)p2.push_back(cnt[i]);
	f1[0][MP(1,1)] = 1;
	//freopen("FUCK598.out","w",stdout);
	for (int i=0;i<4;i++)
	{
		//printf("Consider first %i\n",i);
		int x = cnt[i];
		//printf("%d %d\n",prime[i],x);
		for (auto t:f1[i])
		{
			//printf("%lld %lld:%lld\n",t.first.first,t.first.second,t.second);
			for (int j=0;j<=x;j++)
			{
				f1[i+1][MP(t.first.first * LL(j+1), t.first.second * LL(x+1-j))] += f1[i][t.first];
			}
		}
	}
	f2[0][MP(1,1)] = 1;
	for (int i=0;i<p2.size();i++)
	{
		int x = p2[i];
		for (auto t:f2[i])
		{
			for (int j=0;j<=x;j++)
			{
				f2[i+1][MP(t.first.first * LL(j+1), t.first.second * LL(x+1-j))] += f2[i][t.first];
			}
		}
	}
	printf("%d\n",f1[3].size());
	printf("%d\n",f2[M-3].size());
	
	//for (auto t:f2[M-3])
	//	printf("%lld %lld %lld\n",t.first.first,t.first.second,t.second);
	LL ans = 0;
	int cntt = 0;
	ct.clear();
	for (auto t2:f2[M-3])
	{
		LL a,b,g;
		a = t2.first.first;
		b = t2.first.second;
		g = gcd(a,b);
		ct[make_pair(a/g,b/g)] += t2.second;  
	}
	for (auto t1:f1[3])
	{
		LL g = gcd(t1.first.first,t1.first.second);
		ans += ct[make_pair(t1.first.second/g,t1.first.first/g)] * t1.second;
	}
	printf("ans = %lld\n",ans/2);
}
