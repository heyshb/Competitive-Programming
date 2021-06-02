#include <bits/stdc++.h>

using namespace std;

char s[200010];
int N,L;
int cnt,l[200010],r[200010];

int main()
{
	scanf("%d%d",&N,&L);
	scanf("%s",s+1);
	int p;
	for (int i=1;i<=N;i++)if (s[i]=='.') p=i;
	/*
	for (int i=p+1;i<=N;i++)
	if (s[i]=='4')
	{
		cnt++;
		l[cnt]=i;
		int j=hv 
	}*/
	
	for (int i=1;i<=p;i++)printf("%c",s[i]);
	for (int i=p+1;i<=N;i++)
	{
		if (s[i]>='5')
		{
		}
	}
}
