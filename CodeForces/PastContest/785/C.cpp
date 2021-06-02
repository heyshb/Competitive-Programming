#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N,M;

int tr[500010];
int lowbit(int x){return x&-x;}
int getsum(int x){int res = 0;while(x){res+=tr[x];x-=lowbit(x);}return res;}
void add(int x,int y){while(x<=N){tr[x]+=y;x+=lowbit(x);}}

int main()
{
	scanf("%I64d%I64d",&N,&M);
	if (M>=N)
	{
		printf("%I64d\n",N);
		return 0;
	}
	LL ans = M;
	LL L=0, R = 2e9;
	while(R>L+1)
	{
		LL mid = (L+R)>>1;
		if ((mid+1)*mid/2>=N-M)
		R = mid;
		else L = mid;
	}
	ans+=R;
	printf("%I64d\n",ans);
}
