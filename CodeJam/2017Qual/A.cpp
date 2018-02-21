#include <bits/stdc++.h>

using namespace std;

char s[1010];

int main()
{
	freopen("Alarge.in","r",stdin);
	freopen("Alarge.out","w",stdout);
	int Casi;
	scanf("%d",&Casi);
	for (int _=1;_<=Casi;_++)
	{
		scanf("%s",s+1);
		int N,K;
		scanf("%d",&K);
		N = strlen(s+1);
		int ans = 0;
		for (int i=1;i<=N-K+1;i++)
		{
			
			int R=i+K-1;
			//printf("%d %d\n",i,R);
			if (s[i] == '+') continue;
			ans++;
			for (int j=i;j<=i+K-1;j++)
				s[j] = '+' + '-' - s[j]; 
		}
		for (int i=1;i<=N;i++)if (s[i] == '-') ans=-1;
		printf("Case #%d: ",_);
		if (ans == -1) puts("IMPOSSIBLE");
		else printf("%d\n",ans);
	}
}
