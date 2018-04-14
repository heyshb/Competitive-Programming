#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
double x[100010],y[100010],r[100010];
double a[100010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lf%lf%lf",&x[i],&y[i],&a[i]);
	double L = 0,R = 20001;
	for (int _=1;_<=60;_++)
	{
		double mid = (L + R) / 2;
		if (check(mid))
			R = mid;
		else
			L = mid;
	}
	
}

