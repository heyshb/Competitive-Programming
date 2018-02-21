#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;
map<LL,pair<LL,int> >mp;
LL seed = 233;
int cnt[10];
void ins(LL x)
{
	LL tmp = x;
	memset(cnt,0,sizeof(cnt));
	while(tmp)
	{
		cnt[tmp % 10] ++;
		tmp /= 10;
	}
	LL hsh = 0;
	for (int i=0;i<10;i++)hsh = hsh * seed + cnt[i];
	//if (x == 66430125 || x == 56623104 || x == 41063625) printf("%llu\n",hsh);
	if (mp.find(hsh) == mp.end())
		mp[hsh] = make_pair(x,1);
	else
	{
		//printf("%d\n",x);
		auto pr = mp[hsh];
		pr.first = min(pr.first,x);
		pr.second++;
		mp[hsh] = pr;
	}
}

int main()
{
	for (LL i=1;i<=10000;i++)
	{
		ins(i*i*i);
	}
	//printf("%d %d\n",mp[3548501738610809168U].first,mp[3548501738610809168U].second); 
	LL ans = 2e17;
	for (auto t:mp)
		if (t.second.second == 5)
		{
			ans = min(ans,t.second.first);
		}
	printf("%llu\n",ans);
}
