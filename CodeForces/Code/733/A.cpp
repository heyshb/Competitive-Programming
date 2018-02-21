#include <bits/stdc++.h>

using namespace std;

char s[1010];
int f[1010];

bool isvowel(char x)
{
	return (x=='A' || x=='E' || x=='I' || x=='O' || x=='U' || x=='Y');
}

int main()
{
	scanf("%s",s+1);
	int N=strlen(s+1);
	s[N+1]='A';
	for (int i=1;i<=N+1;i++)
	if (isvowel(s[i]))
	{
		f[i]=i;
		for (int j=1;j<i;j++)
		if (isvowel(s[j]))
		f[i]=min(f[i],max(f[j],i-j));
	}
	printf("%d\n",f[N+1]);
}
