#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,D,B;
int a[100010],S[100010];
int L[100010],R[100010];

bool check(int x)
{
	int split = (N + 1) / 2;
	int sl = x + 1, sr = N - x;
	int suml = split - sl + 1, sumr = sr - split;
	for (int i=sl;i<=split;i++)
}

int main()
{
	scanf("%d%d%d",&N,&D,&B);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]),S[i] = S[i - 1] + a[i];
	int now = 1, S = 0;
	for (int i=1;i<=N;i++)
	{
		while(S[now] <= (i - 1) * B) now++;
		L[i] = now;
		while(S[now] < i * B) now++;
		R[i] = now;
	}
	if (check(0)) return 0*puts("0");
	int l = 0,r = (N + 1) / 2,mid;
	while(l < r)
	{
		mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	printf("%d\n",r);
}
