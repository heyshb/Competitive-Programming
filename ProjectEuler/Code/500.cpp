#include <bits/stdc++.h>
#define MOD 500500507
using namespace std;

typedef long long LL;
#define UP 9000000
#define NUM 500500
bool ok[UP+10];
int prime[1000010],cnt;
priority_queue<int,vector<int> ,greater<int> >heap;

int main()
{
	
	cnt = 0;
	memset(ok,true,sizeof(ok));
	for (int i=2;i<=UP;i++)
	{
		if (ok[i]) prime[++cnt] = i;
		for (int j=1;j<=cnt && i*prime[j]<=UP;j++)
		{
			ok[i*prime[j]] = false;
			if (i%prime[j]==0) break;
		}
	}
	//printf("%d\n",cnt);
	LL ans = 2;
	int now = 2;
	heap.push(2);
	for (int i=2;i<=NUM;i++)
	{
		int tmp = heap.top();
		if (prime[now] > tmp*tmp)
		{
			heap.pop();
			ans = ans*tmp*tmp%MOD;
			//printf("%d\n",tmp*tmp);
			heap.push(tmp*tmp);
		}
		else 
		{
			ans = ans*prime[now]%MOD;
			//printf("%d\n",prime[now]);
			heap.push(prime[now]);
			now++; 
		} 
	}
	printf("%lld\n",ans);
}
