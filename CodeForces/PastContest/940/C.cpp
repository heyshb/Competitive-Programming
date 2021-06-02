#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int s,t;
char S[200010];
bool vis[200];

int main()
{
	scanf("%d%d",&s,&t);
	scanf("%s",S + 1);
	char mi = 'z', ma = 'a';
	for (int i=1;i<=s;i++)
	{
		mi = min(mi,S[i]);
		ma = max(ma,S[i]);
		vis[S[i]] = true;
	}
	if (s < t)
	{
		printf("%s",S + 1);
		for (int i=1;i<=t-s;i++)printf("%c",mi);
		return 0;
	}
	// s >= t
	for (int i=t;i>=1;i--)
	if (S[i] != ma)
	{
		for (char j=S[i]+1;j<='z';j++)
		if (vis[j])
		{
			//printf("fuck %c\n",j);
			for (int k=1;k<i;k++)printf("%c",S[k]);
			printf("%c",j);
			for (int k=i+1;k<=t;k++)printf("%c",mi);
			break;
		}
		break;
	}
}
