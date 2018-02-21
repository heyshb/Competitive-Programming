#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL L,R;
LL len[1000010];

struct seg
{
	LL l,r;
};

bool cmp(seg a,seg b)
{
	return a.l<b.l;
}

vector<seg>s;

void print(LL l,LL r)
{
	printf("%lld~%lld\n",l,r);
	for (LL i=l;i<=r;i++)printf("choose %lld\n",i);
}

int main()
{
	int N;
	scanf("%d",&N);
	scanf("%lld%lld",&L,&R);
	for (int i=1;i<=N;i++)
		scanf("%lld",&len[i]);
	sort(len+1,len+N+1);
	for (int i=2;i<=N;i++)
	{
		LL tmpl,tmpr;
		tmpl = max(len[i]-len[i-1]+1,L);
		tmpr = min(R,len[i]+len[i-1]-1);
		//printf("%lld %lld %lld %lld\n",len[i],len[i-1],tmpl,tmpr);
		if (tmpl>tmpr) continue;
		s.push_back((seg){tmpl,tmpr});
	}
	LL ans = 0;
	LL nowr = -1, nowl = 0;
	sort(s.begin(),s.end(),cmp);
	for (int i=0;i<s.size();i++)
	{
		//printf("%lld %lld\n",s[i].l,s[i].r);
		if (s[i].r<=nowr) continue;
		if (s[i].l>nowr)
		{
			ans+=(nowr-nowl+1);
			nowl = s[i].l; 
		}
		nowr = s[i].r;
	}
	ans+=(nowr-nowl+1);
	//print(nowl,nowr);
	printf("%lld\n",ans);
}
