#include <bits/stdc++.h>

using namespace std;

char s[200010];
int cnt[26];
typedef long long LL;

int main()
{
	scanf("%s",s);
	int len = strlen(s);
	LL ans = 1;
	LL sum = 0;
	for (int i=0;i<len;i++)
	{
		ans += sum - LL(cnt[s[i] - 'a']);
		cnt[s[i] - 'a']++;
		sum++;
	}
	printf("%lld\n",ans);
}
