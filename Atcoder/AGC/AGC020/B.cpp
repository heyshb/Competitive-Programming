#include <bits/stdc++.h>

using namespace std;

int K,A[100010];
typedef long long LL; 

int main()
{
	scanf("%d",&K);
	for (int i=1;i<=K;i++)scanf("%d",&A[i]);
	
	LL L = 2, R = 2, NL, NR;
	for (int i=K;i>=1;i--)
	{
		LL v = A[i];
		
		NL = ((L + v - 1) / v) * v;
		NR = (R / v) * v;
		NR += (v - 1);
		
		if (NL > NR) return 0*puts("-1");
		L = NL;
		R = NR;
	}
	printf("%lld %lld\n",NL,NR);
} 
