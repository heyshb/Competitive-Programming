#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL u,v;
		scanf("%lld%lld",&u,&v);// 1+2+...(u+v) + u+1
		printf("%lld\n",(u+v)*(u+v+1)/2+u+1);
	}
}
