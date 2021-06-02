#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[100010];
char ch[2];
int N,ans = 0;
int v[26];
set<char>canbeans;

int main()
{
	scanf("%d",&N);
	for (int i='a';i<='z';i++)canbeans.insert(i);
	for (int t=1;t<=N;t++)
	{
		scanf("%s",ch);
		scanf("%s",s);
		int len = strlen(s);
		if (ch[0] == '.')
		{
			//if (canbeans.size() == 1) ans++;
			for (int i=0;i<len;i++)
				canbeans.erase(s[i]);
		}
		if (ch[0] == '!')
		{
			if (canbeans.size() == 1) ans++;
			for (int i=0;i<26;i++)v[i] = 0;
			for (int i=0;i<len;i++)v[s[i]-'a'] = 1;
			for (int i='a';i<='z';i++)
			if (!v[i-'a']) canbeans.erase(i);
		}
		if (ch[0] == '?' && t < N)
		{
			if (canbeans.size() == 1) ans++;
			canbeans.erase(s[0]); 
		}
	}	
	printf("%d\n",ans);
}
