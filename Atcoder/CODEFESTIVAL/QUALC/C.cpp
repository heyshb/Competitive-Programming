#include <bits/stdc++.h>

using namespace std;

char s[100010];
int N,cnt = 0;
char ot[100010];
int v[100010];

int main()
{
	scanf("%s",s+1);
	N = strlen(s+1);
	int now = 0;
	for (int i=1;i<=N;i++)
	{
		if (s[i] != 'x')
		{
			ot[++cnt] = s[i];
			v[cnt] = now;
			now = 0;
		}
		else
		{
			now++;
		}
	}
	for (int i=1;i<=cnt;i++)
	if (ot[i] != ot[cnt+1-i])
		return 0*puts("-1");
	v[++cnt] = now;
	int ans = 0;
	for (int i=1;i<=cnt/2;i++)
	if (v[i] != v[cnt+1-i])
		ans += abs(v[i] - v[cnt+1-i]);
	printf("%d\n",ans);
}
