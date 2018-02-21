#include <bits/stdc++.h>

using namespace std;

char s[100010];
int N;
int L,R;
vector<pair<int,int> >v;
typedef long long LL;

int main()
{
	int Casi;
	scanf("%d",&Casi);
	while(Casi--)
	{
		scanf("%s",s+1);
		N = strlen(s+1);
		L = 1;
		R = N;
		while(s[L] == '0') L++;
		while(s[R] == '1') R--;
		s[R+1] = '1';
		v.clear();
		int cnt0 = 0, cnt1 = 0;
		LL ans = 0;
		for (int i=L;i<=R;i++) 
		{
			if (s[i]=='0') cnt0++;
			else cnt1++;
			if (s[i]=='0' && s[i+1]=='1')
			{
				v.push_back(make_pair(cnt1,cnt0));
				cnt0 = 0;
				cnt1 = 0;
			}
		}
		//for (int i=0;i<v.size();i++)printf("%d %d\n",v[i].first,v[i].second);
		LL sum1 = 0;
		for (int i=0;i<v.size();i++)
		{
			sum1+=v[i].first;
			ans+=sum1*LL(v[i].second+1);	
		}
		printf("%lld\n",ans);
	}
}
