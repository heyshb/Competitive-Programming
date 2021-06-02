#include <bits/stdc++.h>

using namespace std;

int N,M,S;
int v1[1010],v2[1010];
int cnt,ch[500010][26];
bool ed[500010]; 

int main()
{
	char str[510];
	scanf("%d%d",&N,&M);
	memset(ed,false,sizeof(ed));
	cnt = 1;
	for (int i=1;i<=N;i++)
	{
		scanf("%s",str);
		int len=strlen(str),now=1;
		for (int j=0;j<len;j++)
		{
			if (!ch[now][str[j]-'a'])
				ch[now][str[j]-'a'] = ++cnt;
			now = ch[now][str[j]-'a'];
		}
		ed[now]=true;
	}
	S = 0;
	for (int i=1;i<=M;i++)
	{
		scanf("%s",str);
		int len=strlen(str),now=1;
		bool exist = true;
		for (int j=0;j<len;j++)
		{
			if (!ch[now][str[j]-'a'])
			{
				exist = false;
				break;
			}
			now = ch[now][str[j]-'a'];
		}
		if (!ed[now]) exist = false;
		if (exist) S++;
	}
	N-=S;
	M-=S;
	int now = 1;
	while(true)
	{
		if (now)
		{
			if (S) S--;
			else if (N) N--;
			else 
			{
				puts("NO");
				return 0;
			}
		}
		else
		{
			if (S) S--;
			else if (M) M--;
			else 
			{
				puts("YES");
				return 0;
			}
		}
		now ^=1;
	}
}
