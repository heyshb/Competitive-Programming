#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL size[1000010],s[1000010],s2[1000010];
LL w[1000010];
int N,M;

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=2;i<=N;i++)scanf("%d",&w[i]);
	for (int i=N;i>=1;i--)
	{
		size[i] = 1;
		if (i*2 <= N) 
		{
			size[i] += size[2*i];
			s[i] += s[2*i] + size[2*i]*w[2*i];
		}
		if (i*2+1 <= N) 
		{
			size[i] += size[2*i+1];
			s[i] += s[2*i+1] + size[2*i+1]*w[2*i+1];
		}
	}
	
}
