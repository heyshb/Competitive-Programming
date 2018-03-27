#include <bits/stdc++.h>

using namespace std;

//i * (i - 1) / 2

typedef long long LL;
vector<LL>tri;

bool istri(LL x)
{
	LL tmp = LL(sqrt(x*2));
	for (LL i=tmp-2;i<=tmp+2;i++)
	if (i*(i-1)/2==x)return true;
	return false;
}

LL solve(LL x)
{
	tri.clear();
	for (LL i=1;i*(i-1)/2<=x;i++)tri.push_back(i*(i-1)/2);
	LL ans=0;
	for (int i=0;i<tri.size();i++)
		for (int j=0;j<tri.size()&&tri[i]+tri[j]<=x;j++)
			if (istri(x-tri[i]-tri[j])) ans++;
	return ans;
}

int main()
{
	for (LL i=1;i<=100;i++)printf("%lld\n",solve(i));
	//printf("%lld\n",solve(1000));
	//printf("%lld\n",solve(1000000));
	//printf("%lld\n",solve(17526000000000LL));
}
