#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL fac(int x)
{
	LL res = 1;
	for (LL i=1;i<=x;i++)res*=i;
	return res;
}

LL C(int N,int M)
{
	return fac(N)/fac(M)/fac(N-M);
}

LL calc(int v)
{
	LL res = 1;
	for (int i=1;i<=v-1;i++)res*=2LL;
	return res-1;
}

vector<int>ans;

int main()
{
	LL v;
	scanf("%lld",&v);
	int now = 0;
	while(v)
	{
		now++;
		int tmp = 2;
		while(calc(tmp+1) <= v) tmp++;
		for (int i=1;i<=tmp;i++)ans.push_back(now);
		v-=calc(tmp);
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size()-1;i++)printf("%d ",ans[i]);
	printf("%d\n",ans[ans.size()-1]);
}
