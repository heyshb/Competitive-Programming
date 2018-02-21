#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL X,Y;
LL a[2000010];
LL sum[2000010],sum2[2000010];

LL getsum(int l,int r)
{
	return sum[r] - sum[l-1];
}

LL getsum2(int l,int r)
{
	return sum2[r] - sum2[l-1];
}

int main()
{
	scanf("%d%I64d%I64d",&N,&X,&Y);
	for (int i=1;i<=N;i++)
	{
		scanf("%I64d",&a[i]);
		sum[a[i]]++;
	}
	for (int i=1;i<=2000000;i++)
	{
		sum2[i] = sum[i] * LL(i);
		sum[i] += sum[i-1];
		sum2[i] += sum2[i-1];
	}
	//for (int i=1;i<=20;i++)printf("%d %lld %lld\n",i,sum[i],sum2[i]);
	LL ans = 1e18;
	int t = X / Y;
	for (int g=2;g<=2000000;g++)
	{
		double tmp = 0; 
		LL nowans = 0;
		
		for (int mul=g;mul<=2000000;mul+=g)
		{
			bool print = false;
			int admin = mul - t;
			if (admin <= mul-g) admin = mul-g+1;
			if (print)
			{
				printf("%lld\n",getsum(mul-g+1,admin-1) * X);
				printf("??%d %d %lld\n",admin,mul,getsum2(admin,mul));
				printf("%lld\n",- getsum2(admin,mul) + getsum(admin,mul) * LL(mul) * Y);
			}
			nowans += getsum(mul-g+1,admin-1) * X - getsum2(admin,mul) * Y + getsum(admin,mul) * LL(mul) * Y;
			tmp += 1.0 * getsum(mul-g+1,admin-1) * X - 1.0* getsum2(admin,mul) * Y + 1.0 * getsum(admin,mul) * LL(mul) * Y;
		}
		if (tmp < 1e18) ans = min(ans,nowans);
	}
	printf("%I64d\n",ans);
}
