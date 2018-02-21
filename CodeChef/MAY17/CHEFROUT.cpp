#include <bits/stdc++.h>

using namespace std;

char s[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int N = strlen(s);
		int now=0;
		while(now<N && s[now]=='C') now++;
		while(now<N && s[now]=='E') now++;
		while(now<N && s[now]=='S') now++;
		puts(now==N?"yes":"no");
	}
}
