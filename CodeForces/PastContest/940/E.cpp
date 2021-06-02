#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,C;
LL a[100010],S = 0;
LL f[100010];
multiset<LL>st;

int main()
{
	scanf("%d%d",&N,&C);
	for (int i=1;i<=N;i++)scanf("%lld",&a[i]),S += a[i];
	f[0] = 0;
	for (int i=1;i<=N;i++)
	{
		f[i] = f[i-1];
		st.insert(a[i]);
		if (i > C) st.erase(st.find(a[i-C]));
		
		if (i >= C) f[i] = max(f[i],f[i-C] + (*st.begin()));
		//printf("f[%d] = %lld\n",i,f[i]);
	}
	printf("%lld\n",S - f[N]);
}
