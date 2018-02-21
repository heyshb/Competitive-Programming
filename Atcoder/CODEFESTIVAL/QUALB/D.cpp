#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[500010];
int nxt[500010];
int v[500010];
int f[500010][3];
int pre0[500010],nxt0[500010];
int N;

LL solve(int L,int R)
{
	int len = R - L + 1;
	for (int i=1;i<=len;i++)
		v[i] = s[L + i - 1] - '0';
	
	//for (int i=1;i<=len;i++)printf("%d",v[i]);puts("");
	v[0] = -1;
	v[N+1] = -1;
	int last = 0;
	for (int i=1;i<=len;i++)
	{
		pre0[i] = last;
		if (v[i] == 0)
			last = i;
	}
	last = N + 1;
	for (int i=len;i>=1;i--)
	{
		f[i][0] = f[i][1] = f[i][2] = 0;
		nxt0[i] = last;
		if (v[i] == 0)
			last = i;
	}
	int ans = 0;
	for (int i=1;i<=len;i++)
	if (v[i] == 0)
	{
		int L = pre0[i], R = nxt0[i];
		if (v[i+1] == 1 && v[i-1] == 1)
			f[i][0] = max(f[L][0] + i - L - 2, f[L][1] + i - L - 1);
		f[i][1] = max(f[L][0], max(f[L][1],f[L][2] + i - L - 1));
		f[i][2] = max(f[L][])
		
		ans = max(ans,f[i][1]);
		ans = max(ans,f[i][2] + nxt0[i] - i - 1);
		ans = max(ans,f[i][0]);
	}
	else
	{
		f[i][0] = f[i-1][0];
		f[i][1] = f[i-1][1];
		f[i][2] = f[i-2][2];
	}
	
	
	return ans;
}

int main()
{
	scanf("%d",&N);
	N += 2;
	scanf("%s",s+1);
	s[N] = s[N - 1] = '0';
	LL ans = 0;
	int last = 0;
	nxt[N+1] = N;
	for (int i=N;i>=1;i--)
	if (s[i] == '0')
		nxt[i] = nxt[i+1];
	else
		nxt[i] = i - 1;
	for (int i=1;i<=N;)
	if (nxt[i] > i)
	{
		ans += solve(last+1, i-1);
		last = nxt[i];
		i = nxt[i] + 1;
	}
	else i++;
	printf("%lld\n",ans);
}
