#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
unordered_map<int,int>last;
const LL MOD = 1000000007;

int N,K;
int A[500010],nxt[500010],lst[500010],r[500010];
unordered_map<int,int>biu;
int f[500010],s[500010];

int main()
{
	scanf("%d%d",&N,&K);
	last.clear();
	bool havezero = false;
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		havezero |= (A[i] == 0);
		lst[i] = last[A[i]];
		last[A[i]] = i;
	}
	if (havezero && K==0)
		return 0*puts("0");
	last.clear();
	for (int i=N;i>=1;i--)
	{
		nxt[i] = last[A[i]];
		last[A[i]] = i;
	}
	int now = 0;
	int cnt = 0;
	biu.clear();
	for (int i=1;i<=N;i++)
	{
		while(now+1<=N)
		{
			int nv = A[now+1];
			if (nv>K) 
			{
				now++;
				continue;
			}
			if (biu[nv] == 0) 
			{
				if (cnt < K)
					cnt++;
				else
					break;
			}
			biu[nv] = ++now;
		}
		r[i] = now;
		if (biu[A[i]] == i)
		{
			biu[A[i]] = 0;
			cnt--;
		}
	}
	//for (int i=1;i<=N;i++)printf("%d ",r[i]);puts("");
	f[N+1] = 1;
	s[N+1] = 1;
	for (int i=N;i>=1;i--)
	{
			f[i] = (s[i+1] - s[r[i]+2] + MOD) % MOD; 
		s[i] = (s[i+1] + f[i]) % MOD;
	}
	//for (int i=1;i<=N;i++)printf("%d %d\n",f[i],s[i]);
	printf("%d\n",f[1]);
}
