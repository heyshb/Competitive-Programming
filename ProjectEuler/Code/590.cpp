#include <bits/stdc++.h>

using namespace std;

int N = 4;
vector<int>prime;
vector<int>num[5510]; 

int T(int x,int y)
{
	int res = 0;
	while(x%y==0)
	{
		x/=y;
		res++;
	}
	return res;
}

bool check(int x)
{
	for (int i=2;i*i<=x;i++)
	if (x%i==0) return false;
	return true;
}

typedef long long LL;

int NUMCNT[50010];

int main()
{
	//freopen("590.txt","w",stdout);
	for (int i=2;i<=N;i++)if (check(i))prime.push_back(i);
	int M = prime.size();
	printf("%d\n",M);
	int MM,edge = 0,l2cnt = 0;
	int MOD = 1e9;
	LL ans = 1;
	for (int i=0;i<M;i++)
	{
		LL tmp = prime[i];
		while(tmp*LL(prime[i]) <= N) tmp*=prime[i];
		for (int j=tmp;j<=N;j+=tmp)
		{
			NUMCNT[j]++;
			num[i].push_back(int(j));
		}
		if (num[i].size()>1) 
		{
			l2cnt++;
			edge+=num[i].size();
			LL tmp2 = 1;
			for (int i=1;i<=num[i].size();i++)tmp2=(tmp2*2)%MOD;
			tmp2--;
			ans = ans*tmp2%MOD;
			//printf("%d %d\n",prime[i],num[i].size());
		}
	} 
	
	//for (int i=1;i<=50000;i++)if (NUMCNT[i]>1) printf("!!! %d\n",i);
	for (int i=1;i<=N-edge;i++)ans=ans*2%MOD;
	printf("%I64d\n",ans);
	//for (int i=0;i<=30;i++)printf("%d\n",prime[i]);
}
