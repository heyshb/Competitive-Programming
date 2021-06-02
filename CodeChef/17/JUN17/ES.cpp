#include <bits/stdc++.h>

using namespace std;

double E;
typedef long long LL;
int main()
{
	double tE = 0;
	LL v = 1;
	for (int i=0;i<=15;i++)
	{
		if (i) v = v * LL(i);
		tE += 1.0/v;
	
		
		printf("%.10lf\n",tE);
	}
	E = exp(1.0);
	LL S = 0;
	int N;
	scanf("%d",&N); 
	for (int i=1;i<=N;i++)
	{
		LL v = LL(i*E);
		S += v;
		//printf("%d %d\n",v,S);
	}
	printf("%lld\n",S);
	freopen("ES.in","w",stdout);
	for (int i=1;i<=3999;i++)printf("1");
}
