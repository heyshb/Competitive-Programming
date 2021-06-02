#include <bits/stdc++.h>

using namespace std;

int cnt[2][26];
char s[101010];

int sol()
{
	memset(cnt,0,sizeof(cnt));
	scanf("%s",s);
	int len = strlen(s);
	for (int i=0;i<len;i++)cnt[0][s[i]-'a']++;
	scanf("%s",s);
	len = strlen(s);
	if (len == 1)return puts("B");
	for (int i=0;i<len;i++)cnt[1][s[i]-'a']++;
	for (int i=0;i<26;i++)
	if (cnt[0][i] > 1 && !cnt[1][i]) return puts("A");
	bool allcan = true;
	for (int i=0;i<26;i++)
	if (cnt[0][i]==1 && !cnt[1][i]) allcan = false;
	if (allcan) return puts("B");
	for (int i=0;i<26;i++)
	if (cnt[1][i] && !cnt[0][i]) return puts("B");
	return puts("A");
	return 0;
}
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		sol();
	}
}
