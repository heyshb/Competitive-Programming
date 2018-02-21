#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[1010];
int last[26];

int main()
{
	scanf("%s",s+1);
	int len = strlen(s+1);
	memset(last,false,sizeof(last));
	for (int i=1;i<=len;i++)
	{
		if (last[s[i]-'a']) continue;
		last[s[i]-'a'] = i;
	}
	//for (int i=0;i<26;i++)printf("%d\n",last[i]);
	for (int i=0;i<26;i++)
	if (last[i])
	{
		for (int j=0;j<i;j++)
		if (!last[j] || last[j]>last[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
