#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

char s[1000010];
vector<pair<int,int> >v;

int get(int x)//2^x-1
{
	if (x==0) return 1;
	if (x==1) return 2;
	int tmp = get(x/2);
	tmp = LL(tmp) * LL(tmp) % MOD;
	if (x&1) tmp = tmp * 2 % MOD;
	return tmp;
}

int ans;

int main()
{
	ans = 0;
	scanf("%s",s+1);
	int N = strlen(s+1);
	int sum = 0, cnt = 0, cnt2 = 0, now;
	for (int i=1;i<=N;)
	{
		for (int j=i;j<=N && s[j]==s[i];j++)
		{
			i = j;
			if (s[j] == 'a')
				cnt++;
		}
		i++;
		if (i<=N && s[i]=='b')
		{
			int now = 1;
			while(i+now <= N && s[i+now]=='b') now++;
			LL delta = 0;
			delta = LL(LL(get(cnt)-1) * LL(now)) % MOD;
			sum = (sum + delta) % MOD;
		}
	}
	printf("%d\n",sum);
}
