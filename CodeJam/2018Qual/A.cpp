#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T,N;
LL P;
char s[100];

LL calc()
{
	LL beam = 1;
	LL ret = 0;
	for (int i=0;i<N;i++)
	{
		if (s[i] == 'C')
			beam *= 2LL;
		else
			ret += beam;
	}
	return ret;
}

void swp()
{
	for (int i=N-2;i>=0;i--)
	if (s[i] == 'C' && s[i+1] == 'S')
	{
		swap(s[i],s[i+1]);
		return;
	}
}

int main()
{
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		scanf("%lld",&P);
		scanf("%s",s);
		int Scnt = 0;
		N = strlen(s);
		for (int i=0;i<N;i++)Scnt += (s[i] == 'S');
		if (Scnt > P) 
		{
			puts("IMPOSSIBLE");
			continue;
		}
		int ans = 0;
		while(calc() > P)
		{
			swp();
			ans++;
		}
		printf("%d\n",ans);
	}	
}
