#include <bits/stdc++.h>

using namespace std;

#define N 1000000
bool ok[1000010];
vector<int>prime;
typedef long long LL;
vector<pair<int,int> >fac[100010];
LL mint(LL x,LL d)//Min(Kd),Kd>=x
{
	if (x%d == 0) return x;
	return (x/d+1)*d;
}
LL A,B;
int main()
{
	for (int i=1;i<=N;i++)ok[i]=true;
	for (int i=2;i<=N;i++)
	{
		if (ok[i]) prime.push_back(i);
		for (int j=2*i;j<=N;j+=i)ok[j]=false;
	}
	scanf("%lld%lld",&A,&B);
	for (int i=0;i<prime.size();i++)
	{
		LL start = mint(A,prime[i]);
		while(start <= B)
		{
			LL tmp = start;
			int cnt = 0;
			while(tmp % prime[i] == 0) 
			{
				tmp /= prime[i];
				cnt++;
			}
			fac[start-A].push_back(make_pair(cnt,prime[i]));
			start += LL(prime[i]);
		}
	}
	priority_queue<int>heap;
	LL ans = 0;
	for (LL i=0;i<=B-A;i++)
	{
		LL tmp = A + i;
		for (int j=0;j<fac[i].size();j++)
			for (int k=0;k<fac[i][j].first;k++)
			tmp/=fac[i][j].second;
		if (tmp > 1)
			fac[i].push_back(make_pair(1,tmp));
		LL now = 1;
		for (int j=0;j<fac[i].size();j++)
		{
			now*=LL(fac[i][j].first+1);
			//printf("push %d\n",fac[i][j].first+1);
			heap.push(fac[i][j].first+1);
		}
		ans+=now;
		//printf("%lld\n",now);
		while(!heap.empty())
		{
			int maxt = heap.top();
			//printf("Big %d\n",maxt);
			heap.pop();
			now = now/maxt*LL(maxt-1);
			//printf("%lld\n",now);
			ans+=now;
			if (maxt>2) heap.push(maxt-1);
		}
		ans--;
		//printf("%lld %lld\n",i,ans);
	}
	printf("%lld\n",ans);
}


	/* 
	cnt[1] = 0;
	for (int i=2;i<=N;i++)
	if (!ok[i])
	{
		int x = i;
		cnt[i] = 1;
		for (int j=0;prime[j]<=x;j++)
		if (x%prime[j]==0)
		{
			int tmp = 0;
			while(x%prime[j]==0)
			{
				tmp++;
				x/=prime[j];
			}
			cnt[i]*=(tmp+1);
		}
		cnt[i]--;
	}
	else cnt[i] = 1;
	//for (int i=1;i<=20;i++)printf("%d\n",cnt[i]);
	d[1] = 0;
	for (int i=2;i<=N;i++)
	{
		d[i] = 0;
		for (int j=1;j<i;j++)
		if (i%j==0)
		{
			d[i] = max(d[i], d[j]+cnt[i]+1);
		}
	}
	for (int i=1;i<=100;i++)printf("%d %d\n",i,d[i]);*/
