#include <bits/stdc++.h>

using namespace std;

int T;
char s[200010];
int l[200010],r[200010];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int N = strlen(s+1);
		int cnta = 0,cntb = 0;
		l[0] = 0;
		for (int i=1;i<=N;i++)
		if (s[i] == '.')
			l[i] = l[i-1];
		else
		{
			l[i] = s[i];
			if (s[i] == 'A') cnta++;
			else cntb++;
		}
		
		r[N + 1] = 0;
		for (int i=N;i>=1;i--)
		if (s[i] == '.')
		{
			r[i] = r[i+1];
			if (r[i] == l[i] && r[i])
			{
				if (r[i] == 'A')
					cnta++;
				else
					cntb++;
			}
		}
		else r[i] = s[i];
		printf("%d %d\n",cnta,cntb);
	}
}
