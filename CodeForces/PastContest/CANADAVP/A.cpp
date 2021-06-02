#include <bits/stdc++.h>

using namespace std;

int N,A,B;
char s[200010];
bool fall[200010];

int main()
{
	scanf("%d",&N);
	scanf("%s",s);
	int ans=0;
	for (int i=0;i<N;i++)
	{
		if (s[i]=='<') ans++;
		else break;
	}
	for (int i=N-1;i>=0;i--)
	{
		if (s[i]=='>') ans++;
		else break;
	}
	printf("%d\n",ans);
}
