#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[110][110];
int s1[110],s2[110];
int N,M,H,V; 
int L[110],R[110],S[110];

int main()
{
	freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d%d%d%d",&N,&M,&H,&V);
		for (int i=1;i<=N;i++)scanf("%s",s[i]+1);
		int cho = 0;
		for (int i=1;i<=M;i++)s2[i] = 0;
		for (int i=1;i<=N;i++)s1[i] = 0;
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
			if (s[i][j] == '@')
			{
				cho++;
				s[i][j] = 1;
				s1[i]++;
				s2[j]++;
			}
			else
			{
				s[i][j] = 0;
			}
		for (int i=1;i<=N;i++)s1[i] += s1[i-1];
		for (int i=1;i<=M;i++)s2[i] += s2[i-1];
		printf("Case #%d: ",_);
		H++;
		V++;
		if (cho % (H*V) != 0) 
		{
			puts("IMPOSSIBLE");
			continue;
		}
		bool ok = true;
		int lastrow = 0,last = 0;
		for (int i=1;i<=V;i++)L[i] = 0, R[i] = M+1;
		for (int i=1;i<=N;i++)
		{
			if (s1[i] >= last + cho / H)
			{
				//printf("here! %d\n",i);
				if (s1[i] == last + cho / H)
				{
					for (int j=1;j<=M;j++)S[j] = 0;
					for (int j=1;j<=M;j++)
					{
						for (int k=lastrow+1;k<=i;k++)
							S[j] += s[k][j];
					}
					for (int j=1;j<=M;j++)S[j] += S[j-1];
					//for (int j=1;j<=M;j++)printf("%d ",S[j]);puts("");
					int lastcol = 0;
					for (int j=1;j<=V;j++)
					{
						int LB = 1000000, RB = -1000000;
						for (int k=1;k<=M;k++)
						if (S[k] == j * (cho / H / V))
						{
							LB = min(LB,k);
							RB = max(RB,k);
						}
						L[j] = max(L[j],LB);
						R[j] = min(R[j],RB);
					}
					last = s1[i];
					lastrow = i;
				}
				else ok = false;
			}
		}
		for (int i=1;i<=V;i++) ok &= (L[i] <= R[i]);
		puts(ok?"POSSIBLE":"IMPOSSIBLE");
	}
} 
