#include <bits/stdc++.h>
#define UP 10000000
using namespace std;

typedef long long LL;
vector<int> po[700010];
int prime[UP+10],cnt;
bool ok[UP+10];
int main()
{
	memset(ok,true,sizeof(ok));
	cnt = 0;
	for (int i=2;i<=UP;i++)
	{
		if (ok[i]) prime[++cnt] = i;
		for (int j=1;j<=cnt && i*prime[j]<=UP;j++)
		{
			ok[i*prime[j]] = false;
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		po[i].push_back(1);
		int tmp = prime[i];
		while(tmp <= R)
		{
			po[i].push_back(tmp);
			if (prime[i] >= 4000) break;
			tmp*=prime[i];
		}
	}
	int N,L,R;
	LL ans;
	scanf("%d%d%d",&N,&L,&R);
	if (N==1) ans = (R-L+1);
	else if (N==2) ans = LL(R-L+1)*LL(R-L+1);
	else
	{
		
	}
}
