#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL p,k;
vector<LL>ans;
int rev;

int main()
{
	scanf("%lld%lld",&p,&k);
	LL nxt;
	rev = 1;
	while(p)
	{
		ans.push_back(p % k);
		rev ^= 1;
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
} 
