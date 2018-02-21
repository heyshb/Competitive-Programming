#include <bits/stdc++.h>

using namespace std;

int N,P;
struct device
{
	int A,B;
	double T;
}D[100010];
typedef long long LL;
bool cmp(device a,device b)
{
	return a.T<b.T;
}

bool check(double X)
{
	int R = N;
	for (int i=1;i<=N;i++)
	if (D[i].T > X)
	{
		R = i - 1;
		break;
	}
	double tmp = 0;
	for (int i=1;i<=R;i++)
		tmp += (X*D[i].A-D[i].B)/P;
	return tmp<X;
}

int main()
{
	scanf("%d%d",&N,&P);
	LL sum = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d",&D[i].A,&D[i].B);
		sum+=LL(D[i].A);
		D[i].T = double(D[i].B)/double(D[i].A);
	}
	if (LL(P) >= sum)
	{
		puts("-1");
		return 0;
	}
	sort(D+1,D+N+1,cmp);
	double L = 0,R = 1e14;
	while(L<R-(1e-6))
	{
		double mid = (L+R)/2;
		if (check(mid))
			L = mid;
		else
			R = mid;
	}
	printf("%.10lf\n",L);
}
