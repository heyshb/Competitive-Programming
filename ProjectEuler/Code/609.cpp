#include <bits/stdc++.h>

using namespace std;

const int N = 100000000;
bool ok[N + 10];
int d[N + 10];
int prime[N],cnt;

int main()
{
	memset(ok,true,sizeof(ok));
	for (int i=2;i<=N;i++)
	{
		if (ok[i]) prime[++cnt] = i;
		for (int j=1;j<=cnt && prime[j]*i<=N;j++)
		{
			ok[prime[j] * i] = false;
			if (i % prime[j] == 0) break;
		}
	}
	
}
