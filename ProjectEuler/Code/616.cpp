#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL up = 1e12;
set<LL>ans;

double pod(LL a,int b)
{
	double res = 1;
	for (int i=1;i<=b;i++)
		res = res * a;
	return res;
}

LL po(LL a,int b)
{
	LL res = 1;
	for (int i=1;i<=b;i++)
		res = res * a;
	return res;
}

int main()
{
	for (LL a=2;a<=1000;a++)
	{
		for (int b=2;b<=10;b++)
		{
			int tmp = b*b;
			while(true)
			{
				double v = pod(a,tmp);
				if (v > up) break;
				LL v2 = po(a,tmp);
				if (v2 != 16) ans.insert(v2);
				if (v2==up)printf("fuck!!! %lld %d\n",a,b);
				tmp *= b;
			}
		}
	}
	LL sum = 0;
	vector<LL> res;
	for (auto t:ans) sum += t,res.push_back(t);//printf("%lld ",t);
	puts("");
	printf("%lld\n",sum);
}
