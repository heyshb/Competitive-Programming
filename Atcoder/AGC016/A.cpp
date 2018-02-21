#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[110];
int N;
char now[110],nxt[110];

bool sm(int len,char x)
{
	for (int i=0;i<len;i++)
	if (now[i] != x) return false;
	return true;
}

int check(char x)
{
	for (int i=0;i<N;i++)
		now[i] = s[i];
	int len = N;
	while(true)
	{
		if (sm(len,x)) break;
		len--;
		for (int i=0;i<len;i++)
			if (now[i] == x || now[i+1] == x)
				nxt[i] = x;
			else
				nxt[i] = '?';
		for (int i=0;i<len;i++)
			now[i] = nxt[i];
	}
	return N - len;
}

int main()
{
	scanf("%s",s);
	N = strlen(s);
	int ans = 10000;
	for (int i=0;i<N;i++) 
		ans = min(ans,check(s[i]));
	printf("%d\n",ans);
}
