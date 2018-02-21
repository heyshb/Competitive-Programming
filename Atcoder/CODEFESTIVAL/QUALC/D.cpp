#include <bits/stdc++.h>

using namespace std;

int v[200010];
char s[200010];
int N;
int f[200010];
int mi[1<<26];

int main()
{
	scanf("%s",s + 1);	
	N = strlen(s + 1);
	v[0] = 0;
	for (int i=1;i<=N;i++)
		v[i] = v[i-1] ^ (1 << (s[i] - 'a'));
	f[0] = 0;
	mi[0] = 0;
	for (int i=1;i<(1<<26);i++)mi[i] = 10000000;
	for (int i=1;i<=N;i++)
	{
		f[i] = mi[v[i]] + 1;
		for (int j=0;j<26;j++)
			f[i] = min(f[i],mi[v[i] ^ (1<<j)] + 1);
		//printf("%d\n",f[i]);
		mi[v[i]] = min(mi[v[i]],f[i]);
	}
	printf("%d\n",f[N]);
}
