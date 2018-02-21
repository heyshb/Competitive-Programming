#include <bits/stdc++.h>

using namespace std;
#define N 10000000
int s[N+10];
int minp[N+10];
bool ok[N+10];
int prime[N],cnt;

typedef long long LL;

void fac(int x)
{
	int tmpx = x;
	s[x] = 1; 
	//printf("fac %d\n",x);
	while(x > 1)
	{
		int p = minp[x], cnt = 1;
		
		while(x%p==0)
		{
			x/=p;
			cnt++;
		}
		if (p == 2) cnt--;
		//printf("%d %d\n",p,cnt);
		s[tmpx] *= cnt;
	}
	//printf("S[%d] = %d\n",tmpx,s[tmpx]);
}

int main()
{
	memset(ok,true,sizeof(ok));
	cnt = 0;
	for (int i=2;i<=N;i++)
	{
		if (ok[i])
		{
			minp[i] = i;
			prime[++cnt] = i;
		}
		for (int j=1;j<=cnt && i*prime[j]<=N;j++)
		{
			ok[i*prime[j]] = false;
			minp[i*prime[j]] = prime[j];
			if (i%prime[j] == 0) break;
		}
	}
	//for (int i=2;i<=100;i++)printf("%d %d %d\n",prime[i],i,minp[i]);
	for (int i=1;i<=N;i++)fac(i);
	for (int i=1;i<=20;i++)printf("%d %d\n",i,s[i]);
	
	for (int i=1;i<=N;i++)
		if (s[i]*s[i+1] >= 500) 
		{
			printf("%d %d %lld\n",i,i+1,LL(i)*(i+1)/2);
			break;
		}
}
